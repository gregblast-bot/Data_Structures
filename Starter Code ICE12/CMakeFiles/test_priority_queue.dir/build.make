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
CMAKE_SOURCE_DIR = "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12"

# Include any dependencies generated for this target.
include CMakeFiles/test_priority_queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_priority_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_priority_queue.dir/flags.make

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o: CMakeFiles/test_priority_queue.dir/flags.make
CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o: test_priority_queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o -c "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/test_priority_queue.cpp"

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/test_priority_queue.cpp" > CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.i

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/test_priority_queue.cpp" -o CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.s

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.requires:

.PHONY : CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.requires

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.provides: CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_priority_queue.dir/build.make CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.provides.build
.PHONY : CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.provides

CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.provides.build: CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o


# Object files for target test_priority_queue
test_priority_queue_OBJECTS = \
"CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o"

# External object files for target test_priority_queue
test_priority_queue_EXTERNAL_OBJECTS =

test_priority_queue: CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o
test_priority_queue: CMakeFiles/test_priority_queue.dir/build.make
test_priority_queue: CMakeFiles/test_priority_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_priority_queue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_priority_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_priority_queue.dir/build: test_priority_queue

.PHONY : CMakeFiles/test_priority_queue.dir/build

CMakeFiles/test_priority_queue.dir/requires: CMakeFiles/test_priority_queue.dir/test_priority_queue.cpp.o.requires

.PHONY : CMakeFiles/test_priority_queue.dir/requires

CMakeFiles/test_priority_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_priority_queue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_priority_queue.dir/clean

CMakeFiles/test_priority_queue.dir/depend:
	cd "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12" "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12" "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12" "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12" "/home/tailor/Desktop/\$$Ch00L/Data Structures and Algorithms/ICE/Starter Code ICE12/CMakeFiles/test_priority_queue.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_priority_queue.dir/depend

