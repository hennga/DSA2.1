# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/marcel/Desktop/clion-2017.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/marcel/Desktop/clion-2017.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcel/Desktop/DSA2.1/P4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcel/Desktop/DSA2.1/P4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P4.dir/flags.make

CMakeFiles/P4.dir/main.cpp.o: CMakeFiles/P4.dir/flags.make
CMakeFiles/P4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcel/Desktop/DSA2.1/P4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P4.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P4.dir/main.cpp.o -c /home/marcel/Desktop/DSA2.1/P4/main.cpp

CMakeFiles/P4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcel/Desktop/DSA2.1/P4/main.cpp > CMakeFiles/P4.dir/main.cpp.i

CMakeFiles/P4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcel/Desktop/DSA2.1/P4/main.cpp -o CMakeFiles/P4.dir/main.cpp.s

CMakeFiles/P4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/P4.dir/main.cpp.o.requires

CMakeFiles/P4.dir/main.cpp.o.provides: CMakeFiles/P4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/P4.dir/build.make CMakeFiles/P4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/P4.dir/main.cpp.o.provides

CMakeFiles/P4.dir/main.cpp.o.provides.build: CMakeFiles/P4.dir/main.cpp.o


CMakeFiles/P4.dir/P4_graph.cpp.o: CMakeFiles/P4.dir/flags.make
CMakeFiles/P4.dir/P4_graph.cpp.o: ../P4_graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcel/Desktop/DSA2.1/P4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/P4.dir/P4_graph.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P4.dir/P4_graph.cpp.o -c /home/marcel/Desktop/DSA2.1/P4/P4_graph.cpp

CMakeFiles/P4.dir/P4_graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4.dir/P4_graph.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcel/Desktop/DSA2.1/P4/P4_graph.cpp > CMakeFiles/P4.dir/P4_graph.cpp.i

CMakeFiles/P4.dir/P4_graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4.dir/P4_graph.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcel/Desktop/DSA2.1/P4/P4_graph.cpp -o CMakeFiles/P4.dir/P4_graph.cpp.s

CMakeFiles/P4.dir/P4_graph.cpp.o.requires:

.PHONY : CMakeFiles/P4.dir/P4_graph.cpp.o.requires

CMakeFiles/P4.dir/P4_graph.cpp.o.provides: CMakeFiles/P4.dir/P4_graph.cpp.o.requires
	$(MAKE) -f CMakeFiles/P4.dir/build.make CMakeFiles/P4.dir/P4_graph.cpp.o.provides.build
.PHONY : CMakeFiles/P4.dir/P4_graph.cpp.o.provides

CMakeFiles/P4.dir/P4_graph.cpp.o.provides.build: CMakeFiles/P4.dir/P4_graph.cpp.o


CMakeFiles/P4.dir/P4_graphnode.cpp.o: CMakeFiles/P4.dir/flags.make
CMakeFiles/P4.dir/P4_graphnode.cpp.o: ../P4_graphnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcel/Desktop/DSA2.1/P4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/P4.dir/P4_graphnode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P4.dir/P4_graphnode.cpp.o -c /home/marcel/Desktop/DSA2.1/P4/P4_graphnode.cpp

CMakeFiles/P4.dir/P4_graphnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4.dir/P4_graphnode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcel/Desktop/DSA2.1/P4/P4_graphnode.cpp > CMakeFiles/P4.dir/P4_graphnode.cpp.i

CMakeFiles/P4.dir/P4_graphnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4.dir/P4_graphnode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcel/Desktop/DSA2.1/P4/P4_graphnode.cpp -o CMakeFiles/P4.dir/P4_graphnode.cpp.s

CMakeFiles/P4.dir/P4_graphnode.cpp.o.requires:

.PHONY : CMakeFiles/P4.dir/P4_graphnode.cpp.o.requires

CMakeFiles/P4.dir/P4_graphnode.cpp.o.provides: CMakeFiles/P4.dir/P4_graphnode.cpp.o.requires
	$(MAKE) -f CMakeFiles/P4.dir/build.make CMakeFiles/P4.dir/P4_graphnode.cpp.o.provides.build
.PHONY : CMakeFiles/P4.dir/P4_graphnode.cpp.o.provides

CMakeFiles/P4.dir/P4_graphnode.cpp.o.provides.build: CMakeFiles/P4.dir/P4_graphnode.cpp.o


# Object files for target P4
P4_OBJECTS = \
"CMakeFiles/P4.dir/main.cpp.o" \
"CMakeFiles/P4.dir/P4_graph.cpp.o" \
"CMakeFiles/P4.dir/P4_graphnode.cpp.o"

# External object files for target P4
P4_EXTERNAL_OBJECTS =

P4: CMakeFiles/P4.dir/main.cpp.o
P4: CMakeFiles/P4.dir/P4_graph.cpp.o
P4: CMakeFiles/P4.dir/P4_graphnode.cpp.o
P4: CMakeFiles/P4.dir/build.make
P4: CMakeFiles/P4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcel/Desktop/DSA2.1/P4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable P4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P4.dir/build: P4

.PHONY : CMakeFiles/P4.dir/build

CMakeFiles/P4.dir/requires: CMakeFiles/P4.dir/main.cpp.o.requires
CMakeFiles/P4.dir/requires: CMakeFiles/P4.dir/P4_graph.cpp.o.requires
CMakeFiles/P4.dir/requires: CMakeFiles/P4.dir/P4_graphnode.cpp.o.requires

.PHONY : CMakeFiles/P4.dir/requires

CMakeFiles/P4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P4.dir/clean

CMakeFiles/P4.dir/depend:
	cd /home/marcel/Desktop/DSA2.1/P4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcel/Desktop/DSA2.1/P4 /home/marcel/Desktop/DSA2.1/P4 /home/marcel/Desktop/DSA2.1/P4/cmake-build-debug /home/marcel/Desktop/DSA2.1/P4/cmake-build-debug /home/marcel/Desktop/DSA2.1/P4/cmake-build-debug/CMakeFiles/P4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P4.dir/depend

