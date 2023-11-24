import os
import platform
import sys
from methods import get_compiler_version, using_gcc
from platform_methods import detect_arch

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from SCons import Environment

def is_active():
    return False

def get_name():
    return "Wii U"


def can_build():
    if (not os.getenv("DEVKITPRO")):
        print("DEVKITPRO not found in environment! Wii U target disabled!")
        return False
    return True  # Wii U enabled


def get_opts():
    from SCons.Variables import BoolVariable, EnumVariable

    return [
        EnumVariable("linker", "Linker program", "default", ("default", "bfd", "gold", "lld", "mold")),
        BoolVariable("use_llvm", "Use the LLVM compiler", False),
        BoolVariable("use_static_cpp", "Link libgcc and libstdc++ statically for better portability", True),
        BoolVariable("use_coverage", "Test Godot coverage", False),
        BoolVariable("use_ubsan", "Use LLVM/GCC compiler undefined behavior sanitizer (UBSAN)", False),
        BoolVariable("use_asan", "Use LLVM/GCC compiler address sanitizer (ASAN)", False),
        BoolVariable("use_lsan", "Use LLVM/GCC compiler leak sanitizer (LSAN)", False),
        BoolVariable("use_tsan", "Use LLVM/GCC compiler thread sanitizer (TSAN)", False),
        BoolVariable("use_msan", "Use LLVM compiler memory sanitizer (MSAN)", False),
        BoolVariable("use_sowrap", "Dynamically load system libraries", True),
        BoolVariable("alsa", "Use ALSA", True),
        BoolVariable("pulseaudio", "Use PulseAudio", True),
        BoolVariable("dbus", "Use D-Bus to handle screensaver and portal desktop settings", True),
        BoolVariable("speechd", "Use Speech Dispatcher for Text-to-Speech support", True),
        BoolVariable("fontconfig", "Use fontconfig for system fonts support", True),
        BoolVariable("udev", "Use udev for gamepad connection callbacks", True),
        BoolVariable("x11", "Enable X11 display", True),
        BoolVariable("touch", "Enable touch events", True),
        BoolVariable("execinfo", "Use libexecinfo on systems where glibc is not available", False),
    ]

def get_doc_classes():
    return [
        "EditorExportPlatformWiiU",
    ]

def get_doc_path():
    return "doc_classes"

def get_flags():
    return [
        ("arch", detect_arch()),
    ]

def configure(env: "Environment"):
    # Validate arch.
    supported_arches = ["ppc32"]
    if env["arch"] not in supported_arches:
        print(
            'Unsupported CPU architecture "%s" for Wii U. Supported architectures are: ppc32.'
            % (env["arch"], ", ".join(supported_arches))
        )
        sys.exit(255)

    ## Build type

    if env.dev_build:
        # This is needed for our crash handler to work properly.
        # gdb works fine without it though, so maybe our crash handler could too.
        env.Append(LINKFLAGS=["-rdynamic"])

    # CPU architecture flags.
    if env["arch"] == "rv64":
        # G = General-purpose extensions, C = Compression extension (very common).
        env.Append(CCFLAGS=["-march=rv64gc"])

    ## Compiler configuration
    