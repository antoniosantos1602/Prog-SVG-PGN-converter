# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/png_diff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/png_diff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/png_diff.dir/flags.make

CMakeFiles/png_diff.dir/programs/png_diff.cpp.o: CMakeFiles/png_diff.dir/flags.make
CMakeFiles/png_diff.dir/programs/png_diff.cpp.o: ../programs/png_diff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/png_diff.dir/programs/png_diff.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/png_diff.dir/programs/png_diff.cpp.o -c "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/programs/png_diff.cpp"

CMakeFiles/png_diff.dir/programs/png_diff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/png_diff.dir/programs/png_diff.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/programs/png_diff.cpp" > CMakeFiles/png_diff.dir/programs/png_diff.cpp.i

CMakeFiles/png_diff.dir/programs/png_diff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/png_diff.dir/programs/png_diff.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/programs/png_diff.cpp" -o CMakeFiles/png_diff.dir/programs/png_diff.cpp.s

# Object files for target png_diff
png_diff_OBJECTS = \
"CMakeFiles/png_diff.dir/programs/png_diff.cpp.o"

# External object files for target png_diff
png_diff_EXTERNAL_OBJECTS =

png_diff: CMakeFiles/png_diff.dir/programs/png_diff.cpp.o
png_diff: CMakeFiles/png_diff.dir/build.make
png_diff: libsvg.a
png_diff: libtinyxml2.a
png_diff: CMakeFiles/png_diff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable png_diff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/png_diff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/png_diff.dir/build: png_diff

.PHONY : CMakeFiles/png_diff.dir/build

CMakeFiles/png_diff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/png_diff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/png_diff.dir/clean

CMakeFiles/png_diff.dir/depend:
	cd "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter" "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter" "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug" "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug" "/mnt/c/Users/Ze Carvalho/Desktop/FEUP/Programacao/Prog-SVG-PGN-converter/cmake-build-debug/CMakeFiles/png_diff.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/png_diff.dir/depend
