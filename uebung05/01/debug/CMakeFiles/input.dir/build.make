# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/nils/Documents/IPK/Uebung05/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nils/Documents/IPK/Uebung05/01/debug

# Include any dependencies generated for this target.
include CMakeFiles/input.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/input.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/input.dir/flags.make

CMakeFiles/input.dir/input.cc.o: CMakeFiles/input.dir/flags.make
CMakeFiles/input.dir/input.cc.o: ../input.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nils/Documents/IPK/Uebung05/01/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/input.dir/input.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/input.dir/input.cc.o -c /home/nils/Documents/IPK/Uebung05/01/input.cc

CMakeFiles/input.dir/input.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/input.dir/input.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nils/Documents/IPK/Uebung05/01/input.cc > CMakeFiles/input.dir/input.cc.i

CMakeFiles/input.dir/input.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/input.dir/input.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nils/Documents/IPK/Uebung05/01/input.cc -o CMakeFiles/input.dir/input.cc.s

CMakeFiles/input.dir/input.cc.o.requires:

.PHONY : CMakeFiles/input.dir/input.cc.o.requires

CMakeFiles/input.dir/input.cc.o.provides: CMakeFiles/input.dir/input.cc.o.requires
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/input.cc.o.provides.build
.PHONY : CMakeFiles/input.dir/input.cc.o.provides

CMakeFiles/input.dir/input.cc.o.provides.build: CMakeFiles/input.dir/input.cc.o


# Object files for target input
input_OBJECTS = \
"CMakeFiles/input.dir/input.cc.o"

# External object files for target input
input_EXTERNAL_OBJECTS =

libinput.a: CMakeFiles/input.dir/input.cc.o
libinput.a: CMakeFiles/input.dir/build.make
libinput.a: CMakeFiles/input.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nils/Documents/IPK/Uebung05/01/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libinput.a"
	$(CMAKE_COMMAND) -P CMakeFiles/input.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/input.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/input.dir/build: libinput.a

.PHONY : CMakeFiles/input.dir/build

CMakeFiles/input.dir/requires: CMakeFiles/input.dir/input.cc.o.requires

.PHONY : CMakeFiles/input.dir/requires

CMakeFiles/input.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/input.dir/cmake_clean.cmake
.PHONY : CMakeFiles/input.dir/clean

CMakeFiles/input.dir/depend:
	cd /home/nils/Documents/IPK/Uebung05/01/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nils/Documents/IPK/Uebung05/01 /home/nils/Documents/IPK/Uebung05/01 /home/nils/Documents/IPK/Uebung05/01/debug /home/nils/Documents/IPK/Uebung05/01/debug /home/nils/Documents/IPK/Uebung05/01/debug/CMakeFiles/input.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/input.dir/depend

