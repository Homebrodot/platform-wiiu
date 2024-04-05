import os, platform, sys


from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from SCons import Environment

#Godot for Wii U
#Based heavily on the Android port, because that's a prime example of linking external libraries,
#compiling for an arch that is not the host's arch, etc. Also based on SeleDream's port of Godot 4 to 3DS.

def is_active():
    return True #Needs to be true for the platform to be usable, false for convenience

def get_name():
    return "Wii U"

def can_build():
    if not(os.getenv("DEVKITPRO") and os.getenv("DEVKITPPC")):
        print("Either DevKitPro or DevKitPPC were not found, Wii U disabled.")
        return False
    else:
        return True

def get_opts():
    from SCons.Variables import BoolVariable, EnumVariable

    return [
        BoolVariable("gamepad_touch", "Gamepad 1's touchscreen acts like a mouse for the gamepad's window", True),
        BoolVariable("wiimote_pointer_touch", "P1's Wiimote cursor acts like a mouse", True),
        BoolVariable("experimental_features", "Use experimental or in-dev features, which may be untested or cause crashes", False),
    ]

def get_doc_classes():
    return [
        "EditorExportPlatformWiiU",
    ]

def get_doc_path():
    return "doc_classes"

def get_flags():
    return [
        
        ("arch", "x86_64"), #Hack fix to get export templates to compile

        #Based on detect.py of the Godot 3 Wii port
        ("builtin_freetype", False), # ppc-freetype
        ("builtin_libogg", False), # ppc-libogg
        ("builtin_libpng", False), # ppc-libpng
        ("builtin_libvorbis", False), # ppc-libvorbis
        ("builtin_opus", False), # ppc-libopus + ppc-opusfile
        ("builtin_pcre2_with_jit", False), # pcre2 JIT is unsupported
        ("builtin_zlib", False), # ppc-zlib
    ]

def configure(env: "Environment"):
    # Validate arch. These are supported COMPILE arches, not supported EXPORT arches.
    supported_arches = ["x86_32", "x86_64", "arm32", "arm64"] #Does devkitppc even work on ARM...???
    if env["arch"] not in supported_arches:
        print(
            'Unsupported CPU architecture "%s" for Wii U. Supported architectures are: %s.'
            % (env["arch"], ", ".join(supported_arches))
        )
        sys.exit()

    ## Build type

    env["bits"] = "32"

    ## Compiler configuration

    # Set compilers
    env["CC"] = "powerpc-eabi-gcc"
    env["CXX"] = "powerpc-eabi-g++"
    env["LD"] = "powerpc-eabi-ld"

    devkitpath = os.environ.get("DEVKITPRO", "/opt/devkitpro")
    devkitppc = devkitpath + "/devkitPPC"
    
    #Link flags
    
    env.Prepend(CPPPATH=[devkitppc + "/powerpc-eabi/include"])
    env.Prepend(CPPFLAGS=[devkitpath + "wut/include/"])
    

    
    env.Append(LIBS=["wut"])


    
