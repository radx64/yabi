# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/radek/yabi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/radek/yabi/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/dummy.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/dummy.cpp.o: ../src/dummy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/radek/yabi/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/src.dir/dummy.cpp.o"
	cd /home/radek/yabi/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/src.dir/dummy.cpp.o -c /home/radek/yabi/src/dummy.cpp

src/CMakeFiles/src.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/dummy.cpp.i"
	cd /home/radek/yabi/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/radek/yabi/src/dummy.cpp > CMakeFiles/src.dir/dummy.cpp.i

src/CMakeFiles/src.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/dummy.cpp.s"
	cd /home/radek/yabi/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/radek/yabi/src/dummy.cpp -o CMakeFiles/src.dir/dummy.cpp.s

src/CMakeFiles/src.dir/dummy.cpp.o.requires:
.PHONY : src/CMakeFiles/src.dir/dummy.cpp.o.requires

src/CMakeFiles/src.dir/dummy.cpp.o.provides: src/CMakeFiles/src.dir/dummy.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/src.dir/build.make src/CMakeFiles/src.dir/dummy.cpp.o.provides.build
.PHONY : src/CMakeFiles/src.dir/dummy.cpp.o.provides

src/CMakeFiles/src.dir/dummy.cpp.o.provides.build: src/CMakeFiles/src.dir/dummy.cpp.o

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/dummy.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/dummy.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libsrc.a"
	cd /home/radek/yabi/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /home/radek/yabi/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/requires: src/CMakeFiles/src.dir/dummy.cpp.o.requires
.PHONY : src/CMakeFiles/src.dir/requires

src/CMakeFiles/src.dir/clean:
	cd /home/radek/yabi/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /home/radek/yabi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/radek/yabi /home/radek/yabi/src /home/radek/yabi/build /home/radek/yabi/build/src /home/radek/yabi/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

