# AnyLibcxx

AnyLibcxx builds the C++ runtime for PS5 and for the AnyPS5 implementations of the PS5 API on Windows and Linux. Applications resolve its external functions against the target `libc` and `libkernel` libraries. Building the archive itself does not require AnyPS5 binaries.

Use Clang 18 or newer for PS5, Linux and Windows. Windows also supports x86_64 MinGW GCC 14 or newer. CMake 3.22 or newer and Ninja are required. The selected compiler and its tools must be on `PATH`.

## Windows

Set `ANYLIBCXX_SYSROOT` to a directory containing MinGW C headers in `include`. ABI test executables also need the selected toolchain's host C++ library and native link libraries.

```sh
cmake -S libcxx/platform/anyps5 -B build/windows-gcc -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/Windows.cmake -DANYLIBCXX_COMPILER=gcc -DANYLIBCXX_SYSROOT=/path/to/mingw -DCMAKE_BUILD_TYPE=Release
cmake --build build/windows-gcc --target anylibcxx_package anylibcxx_math_abi anylibcxx_jump_abi anylibcxx_callback_abi --parallel
ctest --test-dir build/windows-gcc --output-on-failure
```

For Clang, use `-DANYLIBCXX_COMPILER=clang` and a separate build directory. Clang remains the default compiler.

Packages are written to `build/windows-gcc/packages`. The GCC package has `windows-gcc` in its name; the Clang package has `windows`. Select the matching package with `AnyLibcxx_DIR` and link `AnyLibcxx::Runtime`. Mixing these Windows packages is rejected because the compilers use different `long double` calling conventions.

Both compilers use exception allocation, throwing, catching and exception pointers from `libc.prx`. GCC emits SEH metadata instead of Clang's DWARF metadata. Its runtime archive supplies the `.sehgcc` personality identities recognized by the AnyPS5 unwinder. The exported CMake target retains this section and the GCC weak allocation definitions during linking. No separate host C++ exception runtime is linked.

GCC consumers inherit `-fno-lifetime-dse` for the libc++ object lifetime model. They also inherit `-nodefaultlibs`; applications must explicitly link their target libraries. ADK applications already do this.

## PS5 and Linux

Use the `Ps5.cmake` or `Linux.cmake` toolchain with Clang and a target C sysroot containing `usr/include`.

```sh
cmake -S libcxx/platform/anyps5 -B build/ps5 -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/Ps5.cmake -DANYLIBCXX_SYSROOT=/path/to/elf-sysroot -DCMAKE_BUILD_TYPE=Release
cmake --build build/ps5 --target anylibcxx_package --parallel
```

The PS5 package remains an ELF runtime and uses the console's system exception implementation. Windows SEH support is compiled only for Windows GCC.
