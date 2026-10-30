import argparse
import pathlib
import subprocess


def symbols(nm, path, defined):
    option = "--defined-only" if defined else "--undefined-only"
    output = subprocess.check_output([nm, option, "--format=posix", str(path)], text=True)
    return {line.split()[0] for line in output.splitlines() if len(line.split()) >= 2 and not line.endswith(":")}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--nm", required=True)
    parser.add_argument("--archive", type=pathlib.Path, required=True)
    parser.add_argument("--objects", type=pathlib.Path, required=True)
    arguments = parser.parse_args()
    objects = sorted(arguments.objects.rglob("*.obj"))
    if not arguments.archive.is_file() or not objects:
        raise RuntimeError("Missing runtime archive or compiled consumer objects")
    files = [arguments.archive, *objects]
    defined = set()
    required = set()
    for path in files:
        defined.update(symbols(arguments.nm, path, True))
        required.update(symbols(arguments.nm, path, False))
    native = {
        "_Unwind_Resume", "_ZSt9terminatev", "__cxa_allocate_exception",
        "__cxa_begin_catch", "__cxa_end_catch", "__cxa_free_exception",
        "__cxa_get_globals", "__cxa_rethrow", "__cxa_throw", "__gxx_personality_v0",
    }
    missing = sorted(name for name in required - defined - native if not name.endswith("_nid_postfix"))
    if missing:
        raise RuntimeError("Unadapted runtime imports:\n" + "\n".join(missing))
    print(f"Verified {len(required - defined)} external imports and {len(objects)} consumer objects")


if __name__ == "__main__":
    main()
