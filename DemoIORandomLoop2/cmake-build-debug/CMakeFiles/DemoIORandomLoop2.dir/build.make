# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\jayde\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5080.54\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\jayde\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5080.54\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\PROG2100\CPPSourceCode\DemoIORandomLoop2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DemoIORandomLoop2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DemoIORandomLoop2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DemoIORandomLoop2.dir/flags.make

CMakeFiles/DemoIORandomLoop2.dir/main.cpp.obj: CMakeFiles/DemoIORandomLoop2.dir/flags.make
CMakeFiles/DemoIORandomLoop2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DemoIORandomLoop2.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DemoIORandomLoop2.dir\main.cpp.obj -c C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\main.cpp

CMakeFiles/DemoIORandomLoop2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DemoIORandomLoop2.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\main.cpp > CMakeFiles\DemoIORandomLoop2.dir\main.cpp.i

CMakeFiles/DemoIORandomLoop2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DemoIORandomLoop2.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\main.cpp -o CMakeFiles\DemoIORandomLoop2.dir\main.cpp.s

# Object files for target DemoIORandomLoop2
DemoIORandomLoop2_OBJECTS = \
"CMakeFiles/DemoIORandomLoop2.dir/main.cpp.obj"

# External object files for target DemoIORandomLoop2
DemoIORandomLoop2_EXTERNAL_OBJECTS =

DemoIORandomLoop2.exe: CMakeFiles/DemoIORandomLoop2.dir/main.cpp.obj
DemoIORandomLoop2.exe: CMakeFiles/DemoIORandomLoop2.dir/build.make
DemoIORandomLoop2.exe: CMakeFiles/DemoIORandomLoop2.dir/linklibs.rsp
DemoIORandomLoop2.exe: CMakeFiles/DemoIORandomLoop2.dir/objects1.rsp
DemoIORandomLoop2.exe: CMakeFiles/DemoIORandomLoop2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DemoIORandomLoop2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DemoIORandomLoop2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DemoIORandomLoop2.dir/build: DemoIORandomLoop2.exe
.PHONY : CMakeFiles/DemoIORandomLoop2.dir/build

CMakeFiles/DemoIORandomLoop2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DemoIORandomLoop2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DemoIORandomLoop2.dir/clean

CMakeFiles/DemoIORandomLoop2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\PROG2100\CPPSourceCode\DemoIORandomLoop2 C:\PROG2100\CPPSourceCode\DemoIORandomLoop2 C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug C:\PROG2100\CPPSourceCode\DemoIORandomLoop2\cmake-build-debug\CMakeFiles\DemoIORandomLoop2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DemoIORandomLoop2.dir/depend

