# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thiago/repositorios/testesopencl/matrixmulti

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiago/repositorios/testesopencl/matrixmulti

# Include any dependencies generated for this target.
include CMakeFiles/matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix.dir/flags.make

CMakeFiles/matrix.dir/main.c.o: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/main.c.o: main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/thiago/repositorios/testesopencl/matrixmulti/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/matrix.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/matrix.dir/main.c.o   -c /home/thiago/repositorios/testesopencl/matrixmulti/main.c

CMakeFiles/matrix.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/thiago/repositorios/testesopencl/matrixmulti/main.c > CMakeFiles/matrix.dir/main.c.i

CMakeFiles/matrix.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/thiago/repositorios/testesopencl/matrixmulti/main.c -o CMakeFiles/matrix.dir/main.c.s

CMakeFiles/matrix.dir/main.c.o.requires:
.PHONY : CMakeFiles/matrix.dir/main.c.o.requires

CMakeFiles/matrix.dir/main.c.o.provides: CMakeFiles/matrix.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/matrix.dir/build.make CMakeFiles/matrix.dir/main.c.o.provides.build
.PHONY : CMakeFiles/matrix.dir/main.c.o.provides

CMakeFiles/matrix.dir/main.c.o.provides.build: CMakeFiles/matrix.dir/main.c.o

# Object files for target matrix
matrix_OBJECTS = \
"CMakeFiles/matrix.dir/main.c.o"

# External object files for target matrix
matrix_EXTERNAL_OBJECTS =

matrix: CMakeFiles/matrix.dir/main.c.o
matrix: libmatrixmulti.a
matrix: /usr/lib/libOpenCL.so
matrix: CMakeFiles/matrix.dir/build.make
matrix: CMakeFiles/matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix.dir/build: matrix
.PHONY : CMakeFiles/matrix.dir/build

CMakeFiles/matrix.dir/requires: CMakeFiles/matrix.dir/main.c.o.requires
.PHONY : CMakeFiles/matrix.dir/requires

CMakeFiles/matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix.dir/clean

CMakeFiles/matrix.dir/depend:
	cd /home/thiago/repositorios/testesopencl/matrixmulti && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thiago/repositorios/testesopencl/matrixmulti /home/thiago/repositorios/testesopencl/matrixmulti /home/thiago/repositorios/testesopencl/matrixmulti /home/thiago/repositorios/testesopencl/matrixmulti /home/thiago/repositorios/testesopencl/matrixmulti/CMakeFiles/matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrix.dir/depend
