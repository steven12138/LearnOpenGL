# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/m1861/UserData/dev/LearnOpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/m1861/UserData/dev/LearnOpenGL/build

# Include any dependencies generated for this target.
include CMakeFiles/LearnOpenGL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LearnOpenGL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LearnOpenGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LearnOpenGL.dir/flags.make

CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj: CMakeFiles/LearnOpenGL.dir/flags.make
CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj: CMakeFiles/LearnOpenGL.dir/includes_C.rsp
CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj: C:/Users/m1861/UserData/dev/LearnOpenGL/external/glad/src/glad.c
CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj: CMakeFiles/LearnOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/m1861/UserData/dev/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj -MF CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj.d -o CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj -c C:/Users/m1861/UserData/dev/LearnOpenGL/external/glad/src/glad.c

CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.i"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/m1861/UserData/dev/LearnOpenGL/external/glad/src/glad.c > CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.i

CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.s"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/m1861/UserData/dev/LearnOpenGL/external/glad/src/glad.c -o CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.s

CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj: CMakeFiles/LearnOpenGL.dir/flags.make
CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj: CMakeFiles/LearnOpenGL.dir/includes_CXX.rsp
CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj: C:/Users/m1861/UserData/dev/LearnOpenGL/src/main.cpp
CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj: CMakeFiles/LearnOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/m1861/UserData/dev/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj -MF CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj.d -o CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj -c C:/Users/m1861/UserData/dev/LearnOpenGL/src/main.cpp

CMakeFiles/LearnOpenGL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LearnOpenGL.dir/src/main.cpp.i"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/m1861/UserData/dev/LearnOpenGL/src/main.cpp > CMakeFiles/LearnOpenGL.dir/src/main.cpp.i

CMakeFiles/LearnOpenGL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LearnOpenGL.dir/src/main.cpp.s"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/m1861/UserData/dev/LearnOpenGL/src/main.cpp -o CMakeFiles/LearnOpenGL.dir/src/main.cpp.s

CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj: CMakeFiles/LearnOpenGL.dir/flags.make
CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj: CMakeFiles/LearnOpenGL.dir/includes_CXX.rsp
CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj: C:/Users/m1861/UserData/dev/LearnOpenGL/src/shader/shader.cpp
CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj: CMakeFiles/LearnOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/m1861/UserData/dev/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj -MF CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj.d -o CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj -c C:/Users/m1861/UserData/dev/LearnOpenGL/src/shader/shader.cpp

CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.i"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/m1861/UserData/dev/LearnOpenGL/src/shader/shader.cpp > CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.i

CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.s"
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/m1861/UserData/dev/LearnOpenGL/src/shader/shader.cpp -o CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.s

# Object files for target LearnOpenGL
LearnOpenGL_OBJECTS = \
"CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj" \
"CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj" \
"CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj"

# External object files for target LearnOpenGL
LearnOpenGL_EXTERNAL_OBJECTS =

LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/external/glad/src/glad.c.obj
LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/src/main.cpp.obj
LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/src/shader/shader.cpp.obj
LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/build.make
LearnOpenGL.exe: external/glfw-3.3.8/src/libglfw3.a
LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/linkLibs.rsp
LearnOpenGL.exe: CMakeFiles/LearnOpenGL.dir/objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/m1861/UserData/dev/LearnOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LearnOpenGL.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/LearnOpenGL.dir/objects.a
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/ar.exe qc CMakeFiles/LearnOpenGL.dir/objects.a @CMakeFiles/LearnOpenGL.dir/objects1
	C:/devtools/w64devkit-1.16.1/w64devkit/bin/c++.exe -Wl,--whole-archive CMakeFiles/LearnOpenGL.dir/objects.a -Wl,--no-whole-archive -o LearnOpenGL.exe -Wl,--out-implib,libLearnOpenGL.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/LearnOpenGL.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/LearnOpenGL.dir/build: LearnOpenGL.exe
.PHONY : CMakeFiles/LearnOpenGL.dir/build

CMakeFiles/LearnOpenGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LearnOpenGL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LearnOpenGL.dir/clean

CMakeFiles/LearnOpenGL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/m1861/UserData/dev/LearnOpenGL C:/Users/m1861/UserData/dev/LearnOpenGL C:/Users/m1861/UserData/dev/LearnOpenGL/build C:/Users/m1861/UserData/dev/LearnOpenGL/build C:/Users/m1861/UserData/dev/LearnOpenGL/build/CMakeFiles/LearnOpenGL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LearnOpenGL.dir/depend
