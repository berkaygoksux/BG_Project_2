# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/berkaygoksu/sinifta_esya_arama

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/berkaygoksu/sinifta_esya_arama/build

# Include any dependencies generated for this target.
include CMakeFiles/sinifta_esya_arama.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sinifta_esya_arama.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sinifta_esya_arama.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sinifta_esya_arama.dir/flags.make

CMakeFiles/sinifta_esya_arama.dir/codegen:
.PHONY : CMakeFiles/sinifta_esya_arama.dir/codegen

CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o: CMakeFiles/sinifta_esya_arama.dir/flags.make
CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o: /Users/berkaygoksu/sinifta_esya_arama/libs/glad/src/glad.c
CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o: CMakeFiles/sinifta_esya_arama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/berkaygoksu/sinifta_esya_arama/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o -MF CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o.d -o CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o -c /Users/berkaygoksu/sinifta_esya_arama/libs/glad/src/glad.c

CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/berkaygoksu/sinifta_esya_arama/libs/glad/src/glad.c > CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.i

CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/berkaygoksu/sinifta_esya_arama/libs/glad/src/glad.c -o CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.s

CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o: CMakeFiles/sinifta_esya_arama.dir/flags.make
CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o: /Users/berkaygoksu/sinifta_esya_arama/src/main.cpp
CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o: CMakeFiles/sinifta_esya_arama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/berkaygoksu/sinifta_esya_arama/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o -MF CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o.d -o CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o -c /Users/berkaygoksu/sinifta_esya_arama/src/main.cpp

CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/berkaygoksu/sinifta_esya_arama/src/main.cpp > CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.i

CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/berkaygoksu/sinifta_esya_arama/src/main.cpp -o CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.s

CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o: CMakeFiles/sinifta_esya_arama.dir/flags.make
CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o: /Users/berkaygoksu/sinifta_esya_arama/src/scene.cpp
CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o: CMakeFiles/sinifta_esya_arama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/berkaygoksu/sinifta_esya_arama/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o -MF CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o.d -o CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o -c /Users/berkaygoksu/sinifta_esya_arama/src/scene.cpp

CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/berkaygoksu/sinifta_esya_arama/src/scene.cpp > CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.i

CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/berkaygoksu/sinifta_esya_arama/src/scene.cpp -o CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.s

# Object files for target sinifta_esya_arama
sinifta_esya_arama_OBJECTS = \
"CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o" \
"CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o" \
"CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o"

# External object files for target sinifta_esya_arama
sinifta_esya_arama_EXTERNAL_OBJECTS =

sinifta_esya_arama: CMakeFiles/sinifta_esya_arama.dir/libs/glad/src/glad.c.o
sinifta_esya_arama: CMakeFiles/sinifta_esya_arama.dir/src/main.cpp.o
sinifta_esya_arama: CMakeFiles/sinifta_esya_arama.dir/src/scene.cpp.o
sinifta_esya_arama: CMakeFiles/sinifta_esya_arama.dir/build.make
sinifta_esya_arama: /usr/local/lib/libglfw.3.4.dylib
sinifta_esya_arama: /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework
sinifta_esya_arama: CMakeFiles/sinifta_esya_arama.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/berkaygoksu/sinifta_esya_arama/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sinifta_esya_arama"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sinifta_esya_arama.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sinifta_esya_arama.dir/build: sinifta_esya_arama
.PHONY : CMakeFiles/sinifta_esya_arama.dir/build

CMakeFiles/sinifta_esya_arama.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sinifta_esya_arama.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sinifta_esya_arama.dir/clean

CMakeFiles/sinifta_esya_arama.dir/depend:
	cd /Users/berkaygoksu/sinifta_esya_arama/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/berkaygoksu/sinifta_esya_arama /Users/berkaygoksu/sinifta_esya_arama /Users/berkaygoksu/sinifta_esya_arama/build /Users/berkaygoksu/sinifta_esya_arama/build /Users/berkaygoksu/sinifta_esya_arama/build/CMakeFiles/sinifta_esya_arama.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sinifta_esya_arama.dir/depend

