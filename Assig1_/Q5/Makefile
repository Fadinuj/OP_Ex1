CXX = g++
CXXFLAGS = -Wall -pg -O2

TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run100:
	./$(TARGET) 42 100

run1000:
	./$(TARGET) 42 1000

run10000:
	./$(TARGET) 42 10000

profile:
	gprof $(TARGET) gmon.out > profile.txt
	cat profile.txt

clean:
	rm -f $(TARGET) gmon.out profile.txt
