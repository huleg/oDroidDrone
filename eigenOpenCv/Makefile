CXX = g++ -O3 -g -std=c++11 -mfpu=neon -funsafe-math-optimizations
CPPFLAGS = $(shell pkg-config --cflags opencv )
LIBS = $(shell pkg-config --libs opencv ) -pthread


DEPS = feature.hpp odometry.hpp common.hpp imu.hpp quaternionAlias.hpp imuFromFile.hpp lkTracker.hpp videoIO.hpp telemetry.hpp geometricTransform.hpp
OBJ  = feature.o   odometry.o   common.o   imu.o                       imuFromFile.o   lkTracker.o   videoIO.o   telemetry.o   geometricTransform.o



all: test

%.o: %.x $(DEPS)
	$(CXX) $(CPPFLAGS) -c -o $@ $< $(LIBS)

test: test.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

opencvTest: opencvTest.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

eigenTest: eigenTest.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

imuTest: imuTest.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

matlabUnitTest: matlabUnitTest.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

lkdemo: lkdemo.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

simpleOdometry: simpleOdometry.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

videoIOTest: videoIOTest.o videoIO.o videoIO.hpp
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

telemetryTest: telemetryTest.o $(OBJ) $(DEPS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIBS)

clean:
	$(RM) test egienTest opencvTest imuTest *.o
