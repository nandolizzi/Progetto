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
CMAKE_SOURCE_DIR = /home/nando/Scrivania/Progetto_Pretto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nando/Scrivania/Progetto_Pretto/build

# Include any dependencies generated for this target.
include CMakeFiles/Progetto_finale.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Progetto_finale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Progetto_finale.dir/flags.make

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o: ../src/project_app.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/project_app.cpp

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/project_app.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/project_app.cpp > CMakeFiles/Progetto_finale.dir/src/project_app.cpp.i

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/project_app.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/project_app.cpp -o CMakeFiles/Progetto_finale.dir/src/project_app.cpp.s

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o: ../src/get_line.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/get_line.cpp

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/get_line.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/get_line.cpp > CMakeFiles/Progetto_finale.dir/src/get_line.cpp.i

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/get_line.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/get_line.cpp -o CMakeFiles/Progetto_finale.dir/src/get_line.cpp.s

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o: ../src/pgm_file.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/pgm_file.cpp

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/pgm_file.cpp > CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.i

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/pgm_file.cpp -o CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.s

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o

CMakeFiles/Progetto_finale.dir/src/tools.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/tools.cpp.o: ../src/tools.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/tools.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/tools.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/tools.cpp

CMakeFiles/Progetto_finale.dir/src/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/tools.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/tools.cpp > CMakeFiles/Progetto_finale.dir/src/tools.cpp.i

CMakeFiles/Progetto_finale.dir/src/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/tools.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/tools.cpp -o CMakeFiles/Progetto_finale.dir/src/tools.cpp.s

CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/tools.cpp.o

CMakeFiles/Progetto_finale.dir/src/cell.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/cell.cpp.o: ../src/cell.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/cell.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/cell.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/cell.cpp

CMakeFiles/Progetto_finale.dir/src/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/cell.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/cell.cpp > CMakeFiles/Progetto_finale.dir/src/cell.cpp.i

CMakeFiles/Progetto_finale.dir/src/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/cell.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/cell.cpp -o CMakeFiles/Progetto_finale.dir/src/cell.cpp.s

CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/cell.cpp.o

CMakeFiles/Progetto_finale.dir/src/list.cpp.o: CMakeFiles/Progetto_finale.dir/flags.make
CMakeFiles/Progetto_finale.dir/src/list.cpp.o: ../src/list.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Progetto_finale.dir/src/list.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Progetto_finale.dir/src/list.cpp.o -c /home/nando/Scrivania/Progetto_Pretto/src/list.cpp

CMakeFiles/Progetto_finale.dir/src/list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Progetto_finale.dir/src/list.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nando/Scrivania/Progetto_Pretto/src/list.cpp > CMakeFiles/Progetto_finale.dir/src/list.cpp.i

CMakeFiles/Progetto_finale.dir/src/list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Progetto_finale.dir/src/list.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nando/Scrivania/Progetto_Pretto/src/list.cpp -o CMakeFiles/Progetto_finale.dir/src/list.cpp.s

CMakeFiles/Progetto_finale.dir/src/list.cpp.o.requires:
.PHONY : CMakeFiles/Progetto_finale.dir/src/list.cpp.o.requires

CMakeFiles/Progetto_finale.dir/src/list.cpp.o.provides: CMakeFiles/Progetto_finale.dir/src/list.cpp.o.requires
	$(MAKE) -f CMakeFiles/Progetto_finale.dir/build.make CMakeFiles/Progetto_finale.dir/src/list.cpp.o.provides.build
.PHONY : CMakeFiles/Progetto_finale.dir/src/list.cpp.o.provides

CMakeFiles/Progetto_finale.dir/src/list.cpp.o.provides.build: CMakeFiles/Progetto_finale.dir/src/list.cpp.o

# Object files for target Progetto_finale
Progetto_finale_OBJECTS = \
"CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o" \
"CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o" \
"CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o" \
"CMakeFiles/Progetto_finale.dir/src/tools.cpp.o" \
"CMakeFiles/Progetto_finale.dir/src/cell.cpp.o" \
"CMakeFiles/Progetto_finale.dir/src/list.cpp.o"

# External object files for target Progetto_finale
Progetto_finale_EXTERNAL_OBJECTS =

../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/tools.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/cell.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/src/list.cpp.o
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/build.make
../bin/Progetto_finale: CMakeFiles/Progetto_finale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/Progetto_finale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Progetto_finale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Progetto_finale.dir/build: ../bin/Progetto_finale
.PHONY : CMakeFiles/Progetto_finale.dir/build

CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/project_app.cpp.o.requires
CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/get_line.cpp.o.requires
CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/pgm_file.cpp.o.requires
CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/tools.cpp.o.requires
CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/cell.cpp.o.requires
CMakeFiles/Progetto_finale.dir/requires: CMakeFiles/Progetto_finale.dir/src/list.cpp.o.requires
.PHONY : CMakeFiles/Progetto_finale.dir/requires

CMakeFiles/Progetto_finale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Progetto_finale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Progetto_finale.dir/clean

CMakeFiles/Progetto_finale.dir/depend:
	cd /home/nando/Scrivania/Progetto_Pretto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nando/Scrivania/Progetto_Pretto /home/nando/Scrivania/Progetto_Pretto /home/nando/Scrivania/Progetto_Pretto/build /home/nando/Scrivania/Progetto_Pretto/build /home/nando/Scrivania/Progetto_Pretto/build/CMakeFiles/Progetto_finale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Progetto_finale.dir/depend
