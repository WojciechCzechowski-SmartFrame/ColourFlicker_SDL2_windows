# What is this about?
This repository contains sources of a program demonstrating issues of non-uniform frame pacing, through colour flickering.

---

# Build instructions

To build this app it is necessary to install the MinGW-w64 toolchain first. To do so, follow the steps described here: https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain

After installing the toolchain, follow the steps below.

1. Open powershell in directory, where you want to place the project and clone the repository with:

```
git clone https://github.com/WojciechCzechowski-SmartFrame/ColourFlicker_SDL2_windows
```

---

2.  Navigate to the main directory of the copied repository

---

3. Build the app with

```
g++ -Isrc/include -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
```

---

4. Run the app with

```
./main.exe
```
