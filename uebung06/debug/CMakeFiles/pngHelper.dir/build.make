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
CMAKE_SOURCE_DIR = /home/nils/Documents/IPK/uebung06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nils/Documents/IPK/uebung06/debug

# Include any dependencies generated for this target.
include CMakeFiles/pngHelper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pngHelper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pngHelper.dir/flags.make

CMakeFiles/pngHelper.dir/pngHelper.cc.o: CMakeFiles/pngHelper.dir/flags.make
CMakeFiles/pngHelper.dir/pngHelper.cc.o: ../pngHelper.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nils/Documents/IPK/uebung06/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pngHelper.dir/pngHelper.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pngHelper.dir/pngHelper.cc.o -c /home/nils/Documents/IPK/uebung06/pngHelper.cc

CMakeFiles/pngHelper.dir/pngHelper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pngHelper.dir/pngHelper.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nils/Documents/IPK/uebung06/pngHelper.cc > CMakeFiles/pngHelper.dir/pngHelper.cc.i

CMakeFiles/pngHelper.dir/pngHelper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pngHelper.dir/pngHelper.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nils/Documents/IPK/uebung06/pngHelper.cc -o CMakeFiles/pngHelper.dir/pngHelper.cc.s

CMakeFiles/pngHelper.dir/pngHelper.cc.o.requires:

.PHONY : CMakeFiles/pngHelper.dir/pngHelper.cc.o.requires

CMakeFiles/pngHelper.dir/pngHelper.cc.o.provides: CMakeFiles/pngHelper.dir/pngHelper.cc.o.requires
	$(MAKE) -f CMakeFiles/pngHelper.dir/build.make CMakeFiles/pngHelper.dir/pngHelper.cc.o.provides.build
.PHONY : CMakeFiles/pngHelper.dir/pngHelper.cc.o.provides

CMakeFiles/pngHelper.dir/pngHelper.cc.o.provides.build: CMakeFiles/pngHelper.dir/pngHelper.cc.o


# Object files for target pngHelper
pngHelper_OBJECTS = \
"CMakeFiles/pngHelper.dir/pngHelper.cc.o"

# External object files for target pngHelper
pngHelper_EXTERNAL_OBJECTS =

libpngHelper.a: CMakeFiles/pngHelper.dir/pngHelper.cc.o
libpngHelper.a: CMakeFiles/pngHelper.dir/build.make
libpngHelper.a: CMakeFiles/pngHelper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nils/Documents/IPK/uebung06/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpngHelper.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pngHelper.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pngHelper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pngHelper.dir/build: libpngHelper.a

.PHONY : CMakeFiles/pngHelper.dir/build

CMakeFiles/pngHelper.dir/requires: CMakeFiles/pngHelper.dir/pngHelper.cc.o.requires

.PHONY : CMakeFiles/pngHelper.dir/requires

CMakeFiles/pngHelper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pngHelper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pngHelper.dir/clean

CMakeFiles/pngHelper.dir/depend:
	cd /home/nils/Documents/IPK/uebung06/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nils/Documents/IPK/uebung06 /home/nils/Documents/IPK/uebung06 /home/nils/Documents/IPK/uebung06/debug /home/nils/Documents/IPK/uebung06/debug /home/nils/Documents/IPK/uebung06/debug/CMakeFiles/pngHelper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pngHelper.dir/depend
