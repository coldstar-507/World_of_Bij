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
CMAKE_BINARY_DIR = /home/scott/dev/World_of_Bij/build/release

# Include any dependencies generated for this target.
include CMakeFiles/WoB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WoB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WoB.dir/flags.make

CMakeFiles/WoB.dir/WoB.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/WoB.cpp.o: ../../WoB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WoB.dir/WoB.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/WoB.cpp.o -c /home/scott/dev/World_of_Bij/WoB.cpp

CMakeFiles/WoB.dir/WoB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/WoB.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/WoB.cpp > CMakeFiles/WoB.dir/WoB.cpp.i

CMakeFiles/WoB.dir/WoB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/WoB.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/WoB.cpp -o CMakeFiles/WoB.dir/WoB.cpp.s

CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o: ../../sources/Core/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o -c /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp

CMakeFiles/WoB.dir/sources/Core/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/Core/Engine.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp > CMakeFiles/WoB.dir/sources/Core/Engine.cpp.i

CMakeFiles/WoB.dir/sources/Core/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/Core/Engine.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Core/Engine.cpp -o CMakeFiles/WoB.dir/sources/Core/Engine.cpp.s

CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o: ../../sources/GameObject/SolideObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o -c /home/scott/dev/World_of_Bij/sources/GameObject/SolideObject.cpp

CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/GameObject/SolideObject.cpp > CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.i

CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/GameObject/SolideObject.cpp -o CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.s

CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o: ../../sources/GameObject/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o -c /home/scott/dev/World_of_Bij/sources/GameObject/Entity.cpp

CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/GameObject/Entity.cpp > CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.i

CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/GameObject/Entity.cpp -o CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.s

CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o: ../../sources/GameObject/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o -c /home/scott/dev/World_of_Bij/sources/GameObject/Player.cpp

CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/GameObject/Player.cpp > CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.i

CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/GameObject/Player.cpp -o CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.s

CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o: ../../sources/Core/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o -c /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp

CMakeFiles/WoB.dir/sources/Core/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/Core/Camera.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp > CMakeFiles/WoB.dir/sources/Core/Camera.cpp.i

CMakeFiles/WoB.dir/sources/Core/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/Core/Camera.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Core/Camera.cpp -o CMakeFiles/WoB.dir/sources/Core/Camera.cpp.s

CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o: ../../sources/2DPhysics/Math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o -c /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp

CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp > CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.i

CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/2DPhysics/Math.cpp -o CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.s

CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o: ../../sources/GameObject/MovingObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o -c /home/scott/dev/World_of_Bij/sources/GameObject/MovingObject.cpp

CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/GameObject/MovingObject.cpp > CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.i

CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/GameObject/MovingObject.cpp -o CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.s

CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o: ../../sources/Texture/TextureBank.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o -c /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp

CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp > CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.i

CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Texture/TextureBank.cpp -o CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.s

CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o: ../../sources/Texture/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o -c /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp

CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp > CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.i

CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Texture/Texture.cpp -o CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.s

CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o: CMakeFiles/WoB.dir/flags.make
CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o: ../../sources/Zones/Zone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o -c /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp

CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp > CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.i

CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scott/dev/World_of_Bij/sources/Zones/Zone.cpp -o CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.s

# Object files for target WoB
WoB_OBJECTS = \
"CMakeFiles/WoB.dir/WoB.cpp.o" \
"CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o" \
"CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o" \
"CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o" \
"CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o" \
"CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o" \
"CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o" \
"CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o" \
"CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o" \
"CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o" \
"CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o"

# External object files for target WoB
WoB_EXTERNAL_OBJECTS =

WoB: CMakeFiles/WoB.dir/WoB.cpp.o
WoB: CMakeFiles/WoB.dir/sources/Core/Engine.cpp.o
WoB: CMakeFiles/WoB.dir/sources/GameObject/SolideObject.cpp.o
WoB: CMakeFiles/WoB.dir/sources/GameObject/Entity.cpp.o
WoB: CMakeFiles/WoB.dir/sources/GameObject/Player.cpp.o
WoB: CMakeFiles/WoB.dir/sources/Core/Camera.cpp.o
WoB: CMakeFiles/WoB.dir/sources/2DPhysics/Math.cpp.o
WoB: CMakeFiles/WoB.dir/sources/GameObject/MovingObject.cpp.o
WoB: CMakeFiles/WoB.dir/sources/Texture/TextureBank.cpp.o
WoB: CMakeFiles/WoB.dir/sources/Texture/Texture.cpp.o
WoB: CMakeFiles/WoB.dir/sources/Zones/Zone.cpp.o
WoB: CMakeFiles/WoB.dir/build.make
WoB: CMakeFiles/WoB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/scott/dev/World_of_Bij/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable WoB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WoB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WoB.dir/build: WoB

.PHONY : CMakeFiles/WoB.dir/build

CMakeFiles/WoB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WoB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WoB.dir/clean

CMakeFiles/WoB.dir/depend:
	cd /home/scott/dev/World_of_Bij/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scott/dev/World_of_Bij /home/scott/dev/World_of_Bij /home/scott/dev/World_of_Bij/build/release /home/scott/dev/World_of_Bij/build/release /home/scott/dev/World_of_Bij/build/release/CMakeFiles/WoB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WoB.dir/depend

