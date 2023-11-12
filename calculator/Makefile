CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lboost_program_options

TARGET = calculator

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) main.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)
