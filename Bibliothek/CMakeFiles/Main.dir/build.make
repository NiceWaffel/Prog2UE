# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/src/Customer.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/Customer.cpp.o: src/Customer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/src/Customer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/Customer.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Customer.cpp

CMakeFiles/Main.dir/src/Customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/Customer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Customer.cpp > CMakeFiles/Main.dir/src/Customer.cpp.i

CMakeFiles/Main.dir/src/Customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/Customer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Customer.cpp -o CMakeFiles/Main.dir/src/Customer.cpp.s

CMakeFiles/Main.dir/src/Inventory.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/Inventory.cpp.o: src/Inventory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Main.dir/src/Inventory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/Inventory.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Inventory.cpp

CMakeFiles/Main.dir/src/Inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/Inventory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Inventory.cpp > CMakeFiles/Main.dir/src/Inventory.cpp.i

CMakeFiles/Main.dir/src/Inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/Inventory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Inventory.cpp -o CMakeFiles/Main.dir/src/Inventory.cpp.s

CMakeFiles/Main.dir/src/Library.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/Library.cpp.o: src/Library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Main.dir/src/Library.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/Library.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Library.cpp

CMakeFiles/Main.dir/src/Library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/Library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Library.cpp > CMakeFiles/Main.dir/src/Library.cpp.i

CMakeFiles/Main.dir/src/Library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/Library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Library.cpp -o CMakeFiles/Main.dir/src/Library.cpp.s

CMakeFiles/Main.dir/src/Person.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/Person.cpp.o: src/Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Main.dir/src/Person.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/Person.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Person.cpp

CMakeFiles/Main.dir/src/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/Person.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Person.cpp > CMakeFiles/Main.dir/src/Person.cpp.i

CMakeFiles/Main.dir/src/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/Person.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Person.cpp -o CMakeFiles/Main.dir/src/Person.cpp.s

CMakeFiles/Main.dir/src/Renderer.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/Renderer.cpp.o: src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Main.dir/src/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/Renderer.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Renderer.cpp

CMakeFiles/Main.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Renderer.cpp > CMakeFiles/Main.dir/src/Renderer.cpp.i

CMakeFiles/Main.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/Renderer.cpp -o CMakeFiles/Main.dir/src/Renderer.cpp.s

CMakeFiles/Main.dir/src/main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/main.cpp.o -c /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/main.cpp

CMakeFiles/Main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/main.cpp > CMakeFiles/Main.dir/src/main.cpp.i

CMakeFiles/Main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/src/main.cpp -o CMakeFiles/Main.dir/src/main.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/src/Customer.cpp.o" \
"CMakeFiles/Main.dir/src/Inventory.cpp.o" \
"CMakeFiles/Main.dir/src/Library.cpp.o" \
"CMakeFiles/Main.dir/src/Person.cpp.o" \
"CMakeFiles/Main.dir/src/Renderer.cpp.o" \
"CMakeFiles/Main.dir/src/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/src/Customer.cpp.o
Main: CMakeFiles/Main.dir/src/Inventory.cpp.o
Main: CMakeFiles/Main.dir/src/Library.cpp.o
Main: CMakeFiles/Main.dir/src/Person.cpp.o
Main: CMakeFiles/Main.dir/src/Renderer.cpp.o
Main: CMakeFiles/Main.dir/src/main.cpp.o
Main: CMakeFiles/Main.dir/build.make
Main: /usr/lib/x86_64-linux-gnu/libcurses.so
Main: /usr/lib/x86_64-linux-gnu/libform.so
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main

.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek /home/simon/develop/cpp/Uebungen/Prog2/Bibliothek/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

