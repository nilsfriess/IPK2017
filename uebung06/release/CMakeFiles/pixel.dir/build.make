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
CMAKE_BINARY_DIR = /home/nils/Documents/IPK/uebung06/release

# Include any dependencies generated for this target.
include CMakeFiles/pixel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pixel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pixel.dir/flags.make

CMakeFiles/pixel.dir/main.cc.o: CMakeFiles/pixel.dir/flags.make
CMakeFiles/pixel.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nils/Documents/IPK/uebung06/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pixel.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pixel.dir/main.cc.o -c /home/nils/Documents/IPK/uebung06/main.cc

CMakeFiles/pixel.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pixel.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nils/Documents/IPK/uebung06/main.cc > CMakeFiles/pixel.dir/main.cc.i

CMakeFiles/pixel.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pixel.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nils/Documents/IPK/uebung06/main.cc -o CMakeFiles/pixel.dir/main.cc.s

CMakeFiles/pixel.dir/main.cc.o.requires:

.PHONY : CMakeFiles/pixel.dir/main.cc.o.requires

CMakeFiles/pixel.dir/main.cc.o.provides: CMakeFiles/pixel.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/pixel.dir/build.make CMakeFiles/pixel.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/pixel.dir/main.cc.o.provides

CMakeFiles/pixel.dir/main.cc.o.provides.build: CMakeFiles/pixel.dir/main.cc.o


# Object files for target pixel
pixel_OBJECTS = \
"CMakeFiles/pixel.dir/main.cc.o"

# External object files for target pixel
pixel_EXTERNAL_OBJECTS =

pixel: CMakeFiles/pixel.dir/main.cc.o
pixel: CMakeFiles/pixel.dir/build.make
pixel: libpoint.a
pixel: libcanvas.a
pixel: libpgm.a
pixel: libpngHelper.a
pixel: CMakeFiles/pixel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nils/Documents/IPK/uebung06/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pixel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pixel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pixel.dir/build: pixel

.PHONY : CMakeFiles/pixel.dir/build

CMakeFiles/pixel.dir/requires: CMakeFiles/pixel.dir/main.cc.o.requires

.PHONY : CMakeFiles/pixel.dir/requires

CMakeFiles/pixel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pixel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pixel.dir/clean

CMakeFiles/pixel.dir/depend:
	cd /home/nils/Documents/IPK/uebung06/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nils/Documents/IPK/uebung06 /home/nils/Documents/IPK/uebung06 /home/nils/Documents/IPK/uebung06/release /home/nils/Documents/IPK/uebung06/release /home/nils/Documents/IPK/uebung06/release/CMakeFiles/pixel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pixel.dir/depend

