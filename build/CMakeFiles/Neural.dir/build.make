# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/tiago/Documents/Developing/attemped neural net"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/tiago/Documents/Developing/attemped neural net/build"

# Include any dependencies generated for this target.
include CMakeFiles/Neural.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Neural.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Neural.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Neural.dir/flags.make

CMakeFiles/Neural.dir/main.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/main.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/main.cpp
CMakeFiles/Neural.dir/main.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Neural.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/main.cpp.o -MF CMakeFiles/Neural.dir/main.cpp.o.d -o CMakeFiles/Neural.dir/main.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/main.cpp"

CMakeFiles/Neural.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/main.cpp" > CMakeFiles/Neural.dir/main.cpp.i

CMakeFiles/Neural.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/main.cpp" -o CMakeFiles/Neural.dir/main.cpp.s

CMakeFiles/Neural.dir/Matrix.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/Matrix.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/Matrix.cpp
CMakeFiles/Neural.dir/Matrix.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Neural.dir/Matrix.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/Matrix.cpp.o -MF CMakeFiles/Neural.dir/Matrix.cpp.o.d -o CMakeFiles/Neural.dir/Matrix.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/Matrix.cpp"

CMakeFiles/Neural.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/Matrix.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/Matrix.cpp" > CMakeFiles/Neural.dir/Matrix.cpp.i

CMakeFiles/Neural.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/Matrix.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/Matrix.cpp" -o CMakeFiles/Neural.dir/Matrix.cpp.s

CMakeFiles/Neural.dir/neural/Neural.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/neural/Neural.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/neural/Neural.cpp
CMakeFiles/Neural.dir/neural/Neural.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Neural.dir/neural/Neural.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/neural/Neural.cpp.o -MF CMakeFiles/Neural.dir/neural/Neural.cpp.o.d -o CMakeFiles/Neural.dir/neural/Neural.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/neural/Neural.cpp"

CMakeFiles/Neural.dir/neural/Neural.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/neural/Neural.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/neural/Neural.cpp" > CMakeFiles/Neural.dir/neural/Neural.cpp.i

CMakeFiles/Neural.dir/neural/Neural.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/neural/Neural.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/neural/Neural.cpp" -o CMakeFiles/Neural.dir/neural/Neural.cpp.s

CMakeFiles/Neural.dir/Util.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/Util.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/Util.cpp
CMakeFiles/Neural.dir/Util.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Neural.dir/Util.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/Util.cpp.o -MF CMakeFiles/Neural.dir/Util.cpp.o.d -o CMakeFiles/Neural.dir/Util.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/Util.cpp"

CMakeFiles/Neural.dir/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/Util.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/Util.cpp" > CMakeFiles/Neural.dir/Util.cpp.i

CMakeFiles/Neural.dir/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/Util.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/Util.cpp" -o CMakeFiles/Neural.dir/Util.cpp.s

CMakeFiles/Neural.dir/StringMatrixMap.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/StringMatrixMap.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/StringMatrixMap.cpp
CMakeFiles/Neural.dir/StringMatrixMap.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Neural.dir/StringMatrixMap.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/StringMatrixMap.cpp.o -MF CMakeFiles/Neural.dir/StringMatrixMap.cpp.o.d -o CMakeFiles/Neural.dir/StringMatrixMap.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/StringMatrixMap.cpp"

CMakeFiles/Neural.dir/StringMatrixMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/StringMatrixMap.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/StringMatrixMap.cpp" > CMakeFiles/Neural.dir/StringMatrixMap.cpp.i

CMakeFiles/Neural.dir/StringMatrixMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/StringMatrixMap.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/StringMatrixMap.cpp" -o CMakeFiles/Neural.dir/StringMatrixMap.cpp.s

CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/neural/NeuralUtil.cpp
CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o -MF CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o.d -o CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/neural/NeuralUtil.cpp"

CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/neural/NeuralUtil.cpp" > CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.i

CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/neural/NeuralUtil.cpp" -o CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.s

CMakeFiles/Neural.dir/neural/Weights.cpp.o: CMakeFiles/Neural.dir/flags.make
CMakeFiles/Neural.dir/neural/Weights.cpp.o: /Users/tiago/Documents/Developing/attemped\ neural\ net/neural/Weights.cpp
CMakeFiles/Neural.dir/neural/Weights.cpp.o: CMakeFiles/Neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Neural.dir/neural/Weights.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Neural.dir/neural/Weights.cpp.o -MF CMakeFiles/Neural.dir/neural/Weights.cpp.o.d -o CMakeFiles/Neural.dir/neural/Weights.cpp.o -c "/Users/tiago/Documents/Developing/attemped neural net/neural/Weights.cpp"

CMakeFiles/Neural.dir/neural/Weights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Neural.dir/neural/Weights.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tiago/Documents/Developing/attemped neural net/neural/Weights.cpp" > CMakeFiles/Neural.dir/neural/Weights.cpp.i

CMakeFiles/Neural.dir/neural/Weights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Neural.dir/neural/Weights.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tiago/Documents/Developing/attemped neural net/neural/Weights.cpp" -o CMakeFiles/Neural.dir/neural/Weights.cpp.s

# Object files for target Neural
Neural_OBJECTS = \
"CMakeFiles/Neural.dir/main.cpp.o" \
"CMakeFiles/Neural.dir/Matrix.cpp.o" \
"CMakeFiles/Neural.dir/neural/Neural.cpp.o" \
"CMakeFiles/Neural.dir/Util.cpp.o" \
"CMakeFiles/Neural.dir/StringMatrixMap.cpp.o" \
"CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o" \
"CMakeFiles/Neural.dir/neural/Weights.cpp.o"

# External object files for target Neural
Neural_EXTERNAL_OBJECTS =

Neural: CMakeFiles/Neural.dir/main.cpp.o
Neural: CMakeFiles/Neural.dir/Matrix.cpp.o
Neural: CMakeFiles/Neural.dir/neural/Neural.cpp.o
Neural: CMakeFiles/Neural.dir/Util.cpp.o
Neural: CMakeFiles/Neural.dir/StringMatrixMap.cpp.o
Neural: CMakeFiles/Neural.dir/neural/NeuralUtil.cpp.o
Neural: CMakeFiles/Neural.dir/neural/Weights.cpp.o
Neural: CMakeFiles/Neural.dir/build.make
Neural: CMakeFiles/Neural.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Neural"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Neural.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Neural.dir/build: Neural
.PHONY : CMakeFiles/Neural.dir/build

CMakeFiles/Neural.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Neural.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Neural.dir/clean

CMakeFiles/Neural.dir/depend:
	cd "/Users/tiago/Documents/Developing/attemped neural net/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/tiago/Documents/Developing/attemped neural net" "/Users/tiago/Documents/Developing/attemped neural net" "/Users/tiago/Documents/Developing/attemped neural net/build" "/Users/tiago/Documents/Developing/attemped neural net/build" "/Users/tiago/Documents/Developing/attemped neural net/build/CMakeFiles/Neural.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Neural.dir/depend
