# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/vctr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vctr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vctr/Рабочий стол/OS_Lab/Lab10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/deleteLink.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/deleteLink.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/deleteLink.dir/flags.make

CMakeFiles/deleteLink.dir/src/deleteLink.c.o: CMakeFiles/deleteLink.dir/flags.make
CMakeFiles/deleteLink.dir/src/deleteLink.c.o: ../src/deleteLink.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/deleteLink.dir/src/deleteLink.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/deleteLink.dir/src/deleteLink.c.o   -c "/home/vctr/Рабочий стол/OS_Lab/Lab10/src/deleteLink.c"

CMakeFiles/deleteLink.dir/src/deleteLink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/deleteLink.dir/src/deleteLink.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/vctr/Рабочий стол/OS_Lab/Lab10/src/deleteLink.c" > CMakeFiles/deleteLink.dir/src/deleteLink.c.i

CMakeFiles/deleteLink.dir/src/deleteLink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/deleteLink.dir/src/deleteLink.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/vctr/Рабочий стол/OS_Lab/Lab10/src/deleteLink.c" -o CMakeFiles/deleteLink.dir/src/deleteLink.c.s

# Object files for target deleteLink
deleteLink_OBJECTS = \
"CMakeFiles/deleteLink.dir/src/deleteLink.c.o"

# External object files for target deleteLink
deleteLink_EXTERNAL_OBJECTS =

deleteLink: CMakeFiles/deleteLink.dir/src/deleteLink.c.o
deleteLink: CMakeFiles/deleteLink.dir/build.make
deleteLink: CMakeFiles/deleteLink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable deleteLink"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/deleteLink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/deleteLink.dir/build: deleteLink

.PHONY : CMakeFiles/deleteLink.dir/build

CMakeFiles/deleteLink.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/deleteLink.dir/cmake_clean.cmake
.PHONY : CMakeFiles/deleteLink.dir/clean

CMakeFiles/deleteLink.dir/depend:
	cd "/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vctr/Рабочий стол/OS_Lab/Lab10" "/home/vctr/Рабочий стол/OS_Lab/Lab10" "/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug" "/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug" "/home/vctr/Рабочий стол/OS_Lab/Lab10/cmake-build-debug/CMakeFiles/deleteLink.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/deleteLink.dir/depend

