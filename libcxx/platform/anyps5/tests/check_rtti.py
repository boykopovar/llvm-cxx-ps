import argparse
from pathlib import Path
from check_windows_imports import symbols


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--nm", required=True)
    parser.add_argument("--archive", type=Path, required=True)
    parser.add_argument("--objects", type=Path, required=True)
    arguments = parser.parse_args()
    objects = sorted(path for path in arguments.objects.rglob("*") if path.suffix in (".obj", ".o"))
    if not arguments.archive.is_file() or not objects:
        raise RuntimeError("Missing runtime archive or compiled consumer objects")
    defined = symbols(arguments.nm, arguments.archive, True)
    required = symbols(arguments.nm, arguments.archive, False)
    for path in objects:
        defined.update(symbols(arguments.nm, path, True))
        required.update(symbols(arguments.nm, path, False))
    missing = sorted(name for name in required - defined if name.startswith(("_ZTI", "_ZTS", "_ZTVN10__cxxabiv1")))
    if missing:
        raise RuntimeError("Runtime does not provide RTTI:\n" + "\n".join(missing))
    print("Runtime provides consumer and library RTTI")


if __name__ == "__main__":
    main()
