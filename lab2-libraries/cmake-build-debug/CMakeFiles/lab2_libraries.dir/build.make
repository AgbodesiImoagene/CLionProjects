# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\agbod\CLionProjects\lab2-libraries

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2_libraries.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_libraries.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_libraries.dir/flags.make

CMakeFiles/lab2_libraries.dir/main.c.obj: CMakeFiles/lab2_libraries.dir/flags.make
CMakeFiles/lab2_libraries.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2_libraries.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab2_libraries.dir\main.c.obj   -c C:\Users\agbod\CLionProjects\lab2-libraries\main.c

CMakeFiles/lab2_libraries.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_libraries.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\agbod\CLionProjects\lab2-libraries\main.c > CMakeFiles\lab2_libraries.dir\main.c.i

CMakeFiles/lab2_libraries.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_libraries.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\agbod\CLionProjects\lab2-libraries\main.c -o CMakeFiles\lab2_libraries.dir\main.c.s

CMakeFiles/lab2_libraries.dir/library.c.obj: CMakeFiles/lab2_libraries.dir/flags.make
CMakeFiles/lab2_libraries.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab2_libraries.dir/library.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab2_libraries.dir\library.c.obj   -c C:\Users\agbod\CLionProjects\lab2-libraries\library.c

CMakeFiles/lab2_libraries.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_libraries.dir/library.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\agbod\CLionProjects\lab2-libraries\library.c > CMakeFiles\lab2_libraries.dir\library.c.i

CMakeFiles/lab2_libraries.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_libraries.dir/library.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\agbod\CLionProjects\lab2-libraries\library.c -o CMakeFiles\lab2_libraries.dir\library.c.s

# Object files for target lab2_libraries
lab2_libraries_OBJECTS = \
"CMakeFiles/lab2_libraries.dir/main.c.obj" \
"CMakeFiles/lab2_libraries.dir/library.c.obj"

# External object files for target lab2_libraries
lab2_libraries_EXTERNAL_OBJECTS =

lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/main.c.obj
lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/library.c.obj
lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/build.make
lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/linklibs.rsp
lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/objects1.rsp
lab2_libraries.exe: CMakeFiles/lab2_libraries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab2_libraries.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab2_libraries.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_libraries.dir/build: lab2_libraries.exe

.PHONY : CMakeFiles/lab2_libraries.dir/build

CMakeFiles/lab2_libraries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab2_libraries.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab2_libraries.dir/clean

CMakeFiles/lab2_libraries.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\agbod\CLionProjects\lab2-libraries C:\Users\agbod\CLionProjects\lab2-libraries C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug C:\Users\agbod\CLionProjects\lab2-libraries\cmake-build-debug\CMakeFiles\lab2_libraries.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_libraries.dir/depend

