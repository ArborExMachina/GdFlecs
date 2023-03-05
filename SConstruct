#!/usr/bin/env python
import os
import sys

from glob import glob

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = [
    "src/flecs/flecs.c"
]
sources.extend(glob("src/**/*.cpp", recursive=True))
print(sources)

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "test/bin/libgdflecs.{}.{}.framework/libgdflecs.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "test/bin/libgdflecs{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
