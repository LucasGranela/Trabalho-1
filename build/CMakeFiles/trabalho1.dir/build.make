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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/lucas.granela/Documents/ED3/Trabalho 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lucas.granela/Documents/ED3/Trabalho 1/build"

# Include any dependencies generated for this target.
include CMakeFiles/trabalho1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trabalho1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trabalho1.dir/flags.make

CMakeFiles/trabalho1.dir/main.c.o: CMakeFiles/trabalho1.dir/flags.make
CMakeFiles/trabalho1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lucas.granela/Documents/ED3/Trabalho 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trabalho1.dir/main.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/trabalho1.dir/main.c.o   -c "/home/lucas.granela/Documents/ED3/Trabalho 1/main.c"

CMakeFiles/trabalho1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalho1.dir/main.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lucas.granela/Documents/ED3/Trabalho 1/main.c" > CMakeFiles/trabalho1.dir/main.c.i

CMakeFiles/trabalho1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalho1.dir/main.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lucas.granela/Documents/ED3/Trabalho 1/main.c" -o CMakeFiles/trabalho1.dir/main.c.s

CMakeFiles/trabalho1.dir/arquivos.c.o: CMakeFiles/trabalho1.dir/flags.make
CMakeFiles/trabalho1.dir/arquivos.c.o: ../arquivos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lucas.granela/Documents/ED3/Trabalho 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/trabalho1.dir/arquivos.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/trabalho1.dir/arquivos.c.o   -c "/home/lucas.granela/Documents/ED3/Trabalho 1/arquivos.c"

CMakeFiles/trabalho1.dir/arquivos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalho1.dir/arquivos.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lucas.granela/Documents/ED3/Trabalho 1/arquivos.c" > CMakeFiles/trabalho1.dir/arquivos.c.i

CMakeFiles/trabalho1.dir/arquivos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalho1.dir/arquivos.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lucas.granela/Documents/ED3/Trabalho 1/arquivos.c" -o CMakeFiles/trabalho1.dir/arquivos.c.s

# Object files for target trabalho1
trabalho1_OBJECTS = \
"CMakeFiles/trabalho1.dir/main.c.o" \
"CMakeFiles/trabalho1.dir/arquivos.c.o"

# External object files for target trabalho1
trabalho1_EXTERNAL_OBJECTS =

trabalho1: CMakeFiles/trabalho1.dir/main.c.o
trabalho1: CMakeFiles/trabalho1.dir/arquivos.c.o
trabalho1: CMakeFiles/trabalho1.dir/build.make
trabalho1: CMakeFiles/trabalho1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lucas.granela/Documents/ED3/Trabalho 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable trabalho1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trabalho1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trabalho1.dir/build: trabalho1

.PHONY : CMakeFiles/trabalho1.dir/build

CMakeFiles/trabalho1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trabalho1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trabalho1.dir/clean

CMakeFiles/trabalho1.dir/depend:
	cd "/home/lucas.granela/Documents/ED3/Trabalho 1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lucas.granela/Documents/ED3/Trabalho 1" "/home/lucas.granela/Documents/ED3/Trabalho 1" "/home/lucas.granela/Documents/ED3/Trabalho 1/build" "/home/lucas.granela/Documents/ED3/Trabalho 1/build" "/home/lucas.granela/Documents/ED3/Trabalho 1/build/CMakeFiles/trabalho1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/trabalho1.dir/depend

