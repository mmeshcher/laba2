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
CMAKE_COMMAND = /cygdrive/c/Users/zamot/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/zamot/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Projects/lab-02-cache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Projects/lab-02-cache/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/template.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template.dir/flags.make

CMakeFiles/template.dir/sources/source.cpp.o: CMakeFiles/template.dir/flags.make
CMakeFiles/template.dir/sources/source.cpp.o: ../sources/source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Projects/lab-02-cache/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template.dir/sources/source.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template.dir/sources/source.cpp.o -c /cygdrive/d/Projects/lab-02-cache/sources/source.cpp

CMakeFiles/template.dir/sources/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template.dir/sources/source.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Projects/lab-02-cache/sources/source.cpp > CMakeFiles/template.dir/sources/source.cpp.i

CMakeFiles/template.dir/sources/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template.dir/sources/source.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Projects/lab-02-cache/sources/source.cpp -o CMakeFiles/template.dir/sources/source.cpp.s

CMakeFiles/template.dir/sources/main.cpp.o: CMakeFiles/template.dir/flags.make
CMakeFiles/template.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Projects/lab-02-cache/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/template.dir/sources/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template.dir/sources/main.cpp.o -c /cygdrive/d/Projects/lab-02-cache/sources/main.cpp

CMakeFiles/template.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template.dir/sources/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Projects/lab-02-cache/sources/main.cpp > CMakeFiles/template.dir/sources/main.cpp.i

CMakeFiles/template.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template.dir/sources/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Projects/lab-02-cache/sources/main.cpp -o CMakeFiles/template.dir/sources/main.cpp.s

# Object files for target template
template_OBJECTS = \
"CMakeFiles/template.dir/sources/source.cpp.o" \
"CMakeFiles/template.dir/sources/main.cpp.o"

# External object files for target template
template_EXTERNAL_OBJECTS =

libtemplated.a: CMakeFiles/template.dir/sources/source.cpp.o
libtemplated.a: CMakeFiles/template.dir/sources/main.cpp.o
libtemplated.a: CMakeFiles/template.dir/build.make
libtemplated.a: CMakeFiles/template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Projects/lab-02-cache/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtemplated.a"
	$(CMAKE_COMMAND) -P CMakeFiles/template.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template.dir/build: libtemplated.a

.PHONY : CMakeFiles/template.dir/build

CMakeFiles/template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/template.dir/cmake_clean.cmake
.PHONY : CMakeFiles/template.dir/clean

CMakeFiles/template.dir/depend:
	cd /cygdrive/d/Projects/lab-02-cache/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Projects/lab-02-cache /cygdrive/d/Projects/lab-02-cache /cygdrive/d/Projects/lab-02-cache/cmake-build-debug /cygdrive/d/Projects/lab-02-cache/cmake-build-debug /cygdrive/d/Projects/lab-02-cache/cmake-build-debug/CMakeFiles/template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template.dir/depend
