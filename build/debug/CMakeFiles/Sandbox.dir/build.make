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
CMAKE_SOURCE_DIR = /home/scott/dev/World_of_Bij

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scott/dev/World_of_Bij/build/debug

# Include any dependencies generated for this target.
include CMakeFiles/Sandbox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sandbox.dir/flags.make

CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o: ../../sandbox/Run.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o -c /home/scott/dev/World_of_Bij/sandbox/Run.cpp

CMakeFiles/Sandbox.dir/sandbox/Run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sandbox/Run.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sandbox/Run.cpp > CMakeFiles/Sandbox.dir/sandbox/Run.cpp.i

CMakeFiles/Sandbox.dir/sandbox/Run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sandbox/Run.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sandbox/Run.cpp -o CMakeFiles/Sandbox.dir/sandbox/Run.cpp.s

CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o: ../../sandbox/SandboxApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o -c /home/scott/dev/World_of_Bij/sandbox/SandboxApp.cpp

CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sandbox/SandboxApp.cpp > CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.i

CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sandbox/SandboxApp.cpp -o CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.s

CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o: ../../sources/Core/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o -c /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp

CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp > CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.i

CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp -o CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o: ../../sources/Objects/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/Player.cpp

CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/Player.cpp > CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/Player.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o: ../../sources/Objects/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/Entity.cpp

CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/Entity.cpp > CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/Entity.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o: ../../sources/Objects/RectangleObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/RectangleObj.cpp

CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/RectangleObj.cpp > CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/RectangleObj.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o: ../../sources/Objects/LosangeObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/LosangeObj.cpp

CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/LosangeObj.cpp > CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/LosangeObj.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o: ../../sources/Objects/StarObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/StarObj.cpp

CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/StarObj.cpp > CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/StarObj.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o: ../../sources/Objects/OctogoneObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/OctogoneObj.cpp

CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/OctogoneObj.cpp > CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/OctogoneObj.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.s

CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o: ../../sources/Objects/MovingObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o -c /home/scott/dev/World_of_Bij/sources/Objects/MovingObj.cpp

CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Objects/MovingObj.cpp > CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.i

CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Objects/MovingObj.cpp -o CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.s

CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o: ../../sources/Core/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o -c /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp

CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp > CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.i

CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp -o CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.s

CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o: ../../sources/Core/Drawer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o -c /home/scott/dev/World_of_Bij/sources/Core/Drawer.cpp

CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Core/Drawer.cpp > CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.i

CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Core/Drawer.cpp -o CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.s

CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o: ../../sources/GameObject/Monsters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o -c /home/scott/dev/World_of_Bij/sources/GameObject/Monsters.cpp

CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/GameObject/Monsters.cpp > CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.i

CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/GameObject/Monsters.cpp -o CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.s

CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o: ../../sources/2DPhysics/Math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o -c /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp

CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp > CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.i

CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp -o CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.s

CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o: ../../sources/Texture/TextureBank.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o -c /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp

CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp > CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.i

CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp -o CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.s

CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o: ../../sources/Texture/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o -c /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp

CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp > CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.i

CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp -o CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.s

CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o: ../../sources/Zones/Zone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o -c /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp

CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp > CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.i

CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp -o CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.s

CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o: CMakeFiles/Sandbox.dir/flags.make
CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o: ../../sources/Zones/ZoneManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o -c /home/scott/dev/World_of_Bij/sources/Zones/ZoneManager.cpp

CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Zones/ZoneManager.cpp > CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.i

CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Zones/ZoneManager.cpp -o CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.s

# Object files for target Sandbox
Sandbox_OBJECTS = \
"CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o" \
"CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o" \
"CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o"

# External object files for target Sandbox
Sandbox_EXTERNAL_OBJECTS =

Sandbox: CMakeFiles/Sandbox.dir/sandbox/Run.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sandbox/SandboxApp.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Core/Engine.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/Player.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/Entity.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/RectangleObj.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/LosangeObj.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/StarObj.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/OctogoneObj.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Objects/MovingObj.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Core/Camera.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Core/Drawer.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/GameObject/Monsters.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/2DPhysics/Math.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Texture/TextureBank.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Texture/Texture.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Zones/Zone.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/sources/Zones/ZoneManager.cpp.o
Sandbox: CMakeFiles/Sandbox.dir/build.make
Sandbox: CMakeFiles/Sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/scott/dev/World_of_Bij/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable Sandbox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sandbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sandbox.dir/build: Sandbox

.PHONY : CMakeFiles/Sandbox.dir/build

CMakeFiles/Sandbox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sandbox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sandbox.dir/clean

CMakeFiles/Sandbox.dir/depend:
	cd /home/scott/dev/World_of_Bij/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scott/dev/World_of_Bij /home/scott/dev/World_of_Bij /home/scott/dev/World_of_Bij/build/debug /home/scott/dev/World_of_Bij/build/debug /home/scott/dev/World_of_Bij/build/debug/CMakeFiles/Sandbox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sandbox.dir/depend

