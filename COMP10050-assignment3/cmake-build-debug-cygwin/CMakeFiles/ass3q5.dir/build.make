# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/agbod/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/agbod/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin

# Include any dependencies generated for this target.
include CMakeFiles/ass3q5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ass3q5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ass3q5.dir/flags.make

CMakeFiles/ass3q5.dir/ass3q5.c.o: CMakeFiles/ass3q5.dir/flags.make
CMakeFiles/ass3q5.dir/ass3q5.c.o: ../ass3q5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ass3q5.dir/ass3q5.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ass3q5.dir/ass3q5.c.o   -c /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/ass3q5.c

CMakeFiles/ass3q5.dir/ass3q5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ass3q5.dir/ass3q5.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/ass3q5.c > CMakeFiles/ass3q5.dir/ass3q5.c.i

CMakeFiles/ass3q5.dir/ass3q5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ass3q5.dir/ass3q5.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/ass3q5.c -o CMakeFiles/ass3q5.dir/ass3q5.c.s

CMakeFiles/ass3q5.dir/fact.c.o: CMakeFiles/ass3q5.dir/flags.make
CMakeFiles/ass3q5.dir/fact.c.o: ../fact.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ass3q5.dir/fact.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ass3q5.dir/fact.c.o   -c /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/fact.c

CMakeFiles/ass3q5.dir/fact.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ass3q5.dir/fact.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/fact.c > CMakeFiles/ass3q5.dir/fact.c.i

CMakeFiles/ass3q5.dir/fact.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ass3q5.dir/fact.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/fact.c -o CMakeFiles/ass3q5.dir/fact.c.s

# Object files for target ass3q5
ass3q5_OBJECTS = \
"CMakeFiles/ass3q5.dir/ass3q5.c.o" \
"CMakeFiles/ass3q5.dir/fact.c.o"

# External object files for target ass3q5
ass3q5_EXTERNAL_OBJECTS =

ass3q5.out: CMakeFiles/ass3q5.dir/ass3q5.c.o
ass3q5.out: CMakeFiles/ass3q5.dir/fact.c.o
ass3q5.out: CMakeFiles/ass3q5.dir/build.make
ass3q5.out: /usr/lib/libcunit.dll.a
ass3q5.out: CMakeFiles/ass3q5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ass3q5.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ass3q5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ass3q5.dir/build: ass3q5.out

.PHONY : CMakeFiles/ass3q5.dir/build

CMakeFiles/ass3q5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ass3q5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ass3q5.dir/clean

CMakeFiles/ass3q5.dir/depend:
	cd /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3 /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3 /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin /cygdrive/c/Users/agbod/CLionProjects/COMP10050-assignment3/cmake-build-debug-cygwin/CMakeFiles/ass3q5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ass3q5.dir/depend

