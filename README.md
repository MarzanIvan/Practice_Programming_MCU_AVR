# Practice_Programming_MCU_AVR

It is project to practice work with AVR MCUs. The project does't have any purpose.

To work with avr MCUs you need to configure the system variable PATH so:
1) create new sys. variable with name AVR wherein value = path of the source files avr are located, in the my pc they are located so: C:/WinAVR-20100110
2) modify value of PATH to add values: %AVR%, %AVR%\avr\include
3) save changes

in the json file "c_cpp_properties" you need to write following code:
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "${PATH}"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:\\Program Files\\mingw64\\bin\\gcc.exe",
            "cStandard": "gnu17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}

That is default json file, you only need to add system variable PATH.
So right now you can use the source files of AVR in the project
