# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build"

# Include any dependencies generated for this target.
include submodule/CMakeFiles/Submodule.dir/depend.make

# Include the progress variables for this target.
include submodule/CMakeFiles/Submodule.dir/progress.make

# Include the compile flags for this target's objects.
include submodule/CMakeFiles/Submodule.dir/flags.make

submodule/CMakeFiles/Submodule.dir/subfunc.cc.o: submodule/CMakeFiles/Submodule.dir/flags.make
submodule/CMakeFiles/Submodule.dir/subfunc.cc.o: ../submodule/subfunc.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object submodule/CMakeFiles/Submodule.dir/subfunc.cc.o"
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Submodule.dir/subfunc.cc.o -c "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/submodule/subfunc.cc"

submodule/CMakeFiles/Submodule.dir/subfunc.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Submodule.dir/subfunc.cc.i"
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/submodule/subfunc.cc" > CMakeFiles/Submodule.dir/subfunc.cc.i

submodule/CMakeFiles/Submodule.dir/subfunc.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Submodule.dir/subfunc.cc.s"
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/submodule/subfunc.cc" -o CMakeFiles/Submodule.dir/subfunc.cc.s

submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.requires:

.PHONY : submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.requires

submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.provides: submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.requires
	$(MAKE) -f submodule/CMakeFiles/Submodule.dir/build.make submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.provides.build
.PHONY : submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.provides

submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.provides.build: submodule/CMakeFiles/Submodule.dir/subfunc.cc.o


# Object files for target Submodule
Submodule_OBJECTS = \
"CMakeFiles/Submodule.dir/subfunc.cc.o"

# External object files for target Submodule
Submodule_EXTERNAL_OBJECTS =

submodule/libSubmodule.a: submodule/CMakeFiles/Submodule.dir/subfunc.cc.o
submodule/libSubmodule.a: submodule/CMakeFiles/Submodule.dir/build.make
submodule/libSubmodule.a: submodule/CMakeFiles/Submodule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSubmodule.a"
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && $(CMAKE_COMMAND) -P CMakeFiles/Submodule.dir/cmake_clean_target.cmake
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Submodule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
submodule/CMakeFiles/Submodule.dir/build: submodule/libSubmodule.a

.PHONY : submodule/CMakeFiles/Submodule.dir/build

submodule/CMakeFiles/Submodule.dir/requires: submodule/CMakeFiles/Submodule.dir/subfunc.cc.o.requires

.PHONY : submodule/CMakeFiles/Submodule.dir/requires

submodule/CMakeFiles/Submodule.dir/clean:
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" && $(CMAKE_COMMAND) -P CMakeFiles/Submodule.dir/cmake_clean.cmake
.PHONY : submodule/CMakeFiles/Submodule.dir/clean

submodule/CMakeFiles/Submodule.dir/depend:
	cd "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options" "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/submodule" "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build" "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule" "/home/liuzihua/Desktop/Slam/CMAKE_tutorial/Cmake compile options/build/submodule/CMakeFiles/Submodule.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : submodule/CMakeFiles/Submodule.dir/depend
