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
CMAKE_SOURCE_DIR = /Users/haocui/invManSys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haocui/invManSys/build

# Include any dependencies generated for this target.
include CMakeFiles/inv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/inv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/inv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inv.dir/flags.make

CMakeFiles/inv.dir/main.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/main.cpp.o: /Users/haocui/invManSys/main.cpp
CMakeFiles/inv.dir/main.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inv.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/main.cpp.o -MF CMakeFiles/inv.dir/main.cpp.o.d -o CMakeFiles/inv.dir/main.cpp.o -c /Users/haocui/invManSys/main.cpp

CMakeFiles/inv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/main.cpp > CMakeFiles/inv.dir/main.cpp.i

CMakeFiles/inv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/main.cpp -o CMakeFiles/inv.dir/main.cpp.s

CMakeFiles/inv.dir/inventoryManagement.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/inventoryManagement.cpp.o: /Users/haocui/invManSys/inventoryManagement.cpp
CMakeFiles/inv.dir/inventoryManagement.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/inv.dir/inventoryManagement.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/inventoryManagement.cpp.o -MF CMakeFiles/inv.dir/inventoryManagement.cpp.o.d -o CMakeFiles/inv.dir/inventoryManagement.cpp.o -c /Users/haocui/invManSys/inventoryManagement.cpp

CMakeFiles/inv.dir/inventoryManagement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/inventoryManagement.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/inventoryManagement.cpp > CMakeFiles/inv.dir/inventoryManagement.cpp.i

CMakeFiles/inv.dir/inventoryManagement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/inventoryManagement.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/inventoryManagement.cpp -o CMakeFiles/inv.dir/inventoryManagement.cpp.s

CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o: /Users/haocui/invManSys/lib/bcrypt/bcrypt.cpp
CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o -MF CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o.d -o CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o -c /Users/haocui/invManSys/lib/bcrypt/bcrypt.cpp

CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/bcrypt/bcrypt.cpp > CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.i

CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/bcrypt/bcrypt.cpp -o CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.s

CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o: /Users/haocui/invManSys/lib/bcrypt/blowfish.cpp
CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o -MF CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o.d -o CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o -c /Users/haocui/invManSys/lib/bcrypt/blowfish.cpp

CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/bcrypt/blowfish.cpp > CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.i

CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/bcrypt/blowfish.cpp -o CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui.cpp
CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui.cpp

CMakeFiles/inv.dir/lib/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui.cpp > CMakeFiles/inv.dir/lib/imgui/imgui.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_demo.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_demo.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_demo.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_demo.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_draw.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_draw.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_draw.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_draw.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_tables.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_tables.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_tables.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_tables.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_widgets.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_widgets.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_widgets.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_widgets.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_impl_glfw.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_impl_glfw.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_impl_glfw.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_impl_glfw.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/inv.dir/flags.make
CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o: /Users/haocui/invManSys/lib/imgui/imgui_impl_opengl3.cpp
CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/inv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o -MF CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o -c /Users/haocui/invManSys/lib/imgui/imgui_impl_opengl3.cpp

CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haocui/invManSys/lib/imgui/imgui_impl_opengl3.cpp > CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haocui/invManSys/lib/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.s

# Object files for target inv
inv_OBJECTS = \
"CMakeFiles/inv.dir/main.cpp.o" \
"CMakeFiles/inv.dir/inventoryManagement.cpp.o" \
"CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o" \
"CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o"

# External object files for target inv
inv_EXTERNAL_OBJECTS =

inv: CMakeFiles/inv.dir/main.cpp.o
inv: CMakeFiles/inv.dir/inventoryManagement.cpp.o
inv: CMakeFiles/inv.dir/lib/bcrypt/bcrypt.cpp.o
inv: CMakeFiles/inv.dir/lib/bcrypt/blowfish.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_demo.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_draw.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_tables.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_widgets.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_impl_glfw.cpp.o
inv: CMakeFiles/inv.dir/lib/imgui/imgui_impl_opengl3.cpp.o
inv: CMakeFiles/inv.dir/build.make
inv: /opt/homebrew/lib/libglfw.3.4.dylib
inv: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks/OpenGL.framework
inv: CMakeFiles/inv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/haocui/invManSys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable inv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inv.dir/build: inv
.PHONY : CMakeFiles/inv.dir/build

CMakeFiles/inv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inv.dir/clean

CMakeFiles/inv.dir/depend:
	cd /Users/haocui/invManSys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haocui/invManSys /Users/haocui/invManSys /Users/haocui/invManSys/build /Users/haocui/invManSys/build /Users/haocui/invManSys/build/CMakeFiles/inv.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/inv.dir/depend

