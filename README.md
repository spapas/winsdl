# winsdl

To compile and run an SDL2 program with Windows command line build tools (cl.exe) without using the Visual Studio: 

1. Download & install Build Tools for Visual Studio 2019 (should also work with 2017 version): https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019 - no need for Visual Studio
1. Download & install the Windows SDK: https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/
1. Download & unzip the SDL Development Libraries for Visual Studio: https://www.libsdl.org/download-2.0.php
1. Fix the include and libpath paths on makeme.bat depending on where you installed SDL
1. Fix the shell32.lib path: this is included in the Windows SDK usually in a folder C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\um\x86\shell32.lib
1. Run vcvarsall.bat x86 (i.e C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat or C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat)
1. Run makeme.bat; it should run without errors and generate a main.exe file
1. Copy over SDL2.dll from the SDL folder to where the main.exe file is created
1. Run main.exe; it should display a window
