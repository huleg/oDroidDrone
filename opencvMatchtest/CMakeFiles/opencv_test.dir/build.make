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
CMAKE_SOURCE_DIR = /home/odroid/oDroidDrone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/oDroidDrone

# Include any dependencies generated for this target.
include CMakeFiles/opencv_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_test.dir/flags.make

CMakeFiles/opencv_test.dir/opencv_test.cpp.o: CMakeFiles/opencv_test.dir/flags.make
CMakeFiles/opencv_test.dir/opencv_test.cpp.o: opencv_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/oDroidDrone/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/opencv_test.dir/opencv_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_test.dir/opencv_test.cpp.o -c /home/odroid/oDroidDrone/opencv_test.cpp

CMakeFiles/opencv_test.dir/opencv_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test.dir/opencv_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/oDroidDrone/opencv_test.cpp > CMakeFiles/opencv_test.dir/opencv_test.cpp.i

CMakeFiles/opencv_test.dir/opencv_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test.dir/opencv_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/oDroidDrone/opencv_test.cpp -o CMakeFiles/opencv_test.dir/opencv_test.cpp.s

CMakeFiles/opencv_test.dir/opencv_test.cpp.o.requires:
.PHONY : CMakeFiles/opencv_test.dir/opencv_test.cpp.o.requires

CMakeFiles/opencv_test.dir/opencv_test.cpp.o.provides: CMakeFiles/opencv_test.dir/opencv_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/opencv_test.dir/build.make CMakeFiles/opencv_test.dir/opencv_test.cpp.o.provides.build
.PHONY : CMakeFiles/opencv_test.dir/opencv_test.cpp.o.provides

CMakeFiles/opencv_test.dir/opencv_test.cpp.o.provides.build: CMakeFiles/opencv_test.dir/opencv_test.cpp.o

# Object files for target opencv_test
opencv_test_OBJECTS = \
"CMakeFiles/opencv_test.dir/opencv_test.cpp.o"

# External object files for target opencv_test
opencv_test_EXTERNAL_OBJECTS =

opencv_test: CMakeFiles/opencv_test.dir/opencv_test.cpp.o
opencv_test: CMakeFiles/opencv_test.dir/build.make
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_ts.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.8
opencv_test: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.8
opencv_test: CMakeFiles/opencv_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable opencv_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_test.dir/build: opencv_test
.PHONY : CMakeFiles/opencv_test.dir/build

CMakeFiles/opencv_test.dir/requires: CMakeFiles/opencv_test.dir/opencv_test.cpp.o.requires
.PHONY : CMakeFiles/opencv_test.dir/requires

CMakeFiles/opencv_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_test.dir/clean

CMakeFiles/opencv_test.dir/depend:
	cd /home/odroid/oDroidDrone && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/oDroidDrone /home/odroid/oDroidDrone /home/odroid/oDroidDrone /home/odroid/oDroidDrone /home/odroid/oDroidDrone/CMakeFiles/opencv_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_test.dir/depend

