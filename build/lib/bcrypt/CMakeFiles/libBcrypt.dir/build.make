# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/haocui/inventory-management-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haocui/inventory-management-system/build

# Include any dependencies generated for this target.
include lib/bcrypt/CMakeFiles/libBcrypt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/bcrypt/CMakeFiles/libBcrypt.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/bcrypt/CMakeFiles/libBcrypt.dir/progress.make

# Include the compile flags for this target's objects.
include lib/bcrypt/CMakeFiles/libBcrypt.dir/flags.make

lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o: lib/bcrypt/CMakeFiles/libBcrypt.dir/flags.make
lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o: /Users/haocui/inventory-management-system/lib/bcrypt/bcrypt.cpp
lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o: lib/bcrypt/CMakeFiles/libBcrypt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/inventory-management-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o -MF CMakeFiles/libBcrypt.dir/bcrypt.cpp.o.d -o CMakeFiles/libBcrypt.dir/bcrypt.cpp.o -c /Users/haocui/inventory-management-system/lib/bcrypt/bcrypt.cpp

lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libBcrypt.dir/bcrypt.cpp.i"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/inventory-management-system/lib/bcrypt/bcrypt.cpp > CMakeFiles/libBcrypt.dir/bcrypt.cpp.i

lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libBcrypt.dir/bcrypt.cpp.s"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/inventory-management-system/lib/bcrypt/bcrypt.cpp -o CMakeFiles/libBcrypt.dir/bcrypt.cpp.s

lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o: lib/bcrypt/CMakeFiles/libBcrypt.dir/flags.make
lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o: /Users/haocui/inventory-management-system/lib/bcrypt/blowfish.cpp
lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o: lib/bcrypt/CMakeFiles/libBcrypt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/inventory-management-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o -MF CMakeFiles/libBcrypt.dir/blowfish.cpp.o.d -o CMakeFiles/libBcrypt.dir/blowfish.cpp.o -c /Users/haocui/inventory-management-system/lib/bcrypt/blowfish.cpp

lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libBcrypt.dir/blowfish.cpp.i"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/inventory-management-system/lib/bcrypt/blowfish.cpp > CMakeFiles/libBcrypt.dir/blowfish.cpp.i

lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libBcrypt.dir/blowfish.cpp.s"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/inventory-management-system/lib/bcrypt/blowfish.cpp -o CMakeFiles/libBcrypt.dir/blowfish.cpp.s

# Object files for target libBcrypt
libBcrypt_OBJECTS = \
"CMakeFiles/libBcrypt.dir/bcrypt.cpp.o" \
"CMakeFiles/libBcrypt.dir/blowfish.cpp.o"

# External object files for target libBcrypt
libBcrypt_EXTERNAL_OBJECTS =

lib/bcrypt/liblibBcrypt.a: lib/bcrypt/CMakeFiles/libBcrypt.dir/bcrypt.cpp.o
lib/bcrypt/liblibBcrypt.a: lib/bcrypt/CMakeFiles/libBcrypt.dir/blowfish.cpp.o
lib/bcrypt/liblibBcrypt.a: lib/bcrypt/CMakeFiles/libBcrypt.dir/build.make
lib/bcrypt/liblibBcrypt.a: lib/bcrypt/CMakeFiles/libBcrypt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/haocui/inventory-management-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblibBcrypt.a"
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && $(CMAKE_COMMAND) -P CMakeFiles/libBcrypt.dir/cmake_clean_target.cmake
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libBcrypt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/bcrypt/CMakeFiles/libBcrypt.dir/build: lib/bcrypt/liblibBcrypt.a
.PHONY : lib/bcrypt/CMakeFiles/libBcrypt.dir/build

lib/bcrypt/CMakeFiles/libBcrypt.dir/clean:
	cd /Users/haocui/inventory-management-system/build/lib/bcrypt && $(CMAKE_COMMAND) -P CMakeFiles/libBcrypt.dir/cmake_clean.cmake
.PHONY : lib/bcrypt/CMakeFiles/libBcrypt.dir/clean

lib/bcrypt/CMakeFiles/libBcrypt.dir/depend:
	cd /Users/haocui/inventory-management-system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haocui/inventory-management-system /Users/haocui/inventory-management-system/lib/bcrypt /Users/haocui/inventory-management-system/build /Users/haocui/inventory-management-system/build/lib/bcrypt /Users/haocui/inventory-management-system/build/lib/bcrypt/CMakeFiles/libBcrypt.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/bcrypt/CMakeFiles/libBcrypt.dir/depend

