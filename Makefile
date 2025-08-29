CXX = g++
CXXFLAGS = -std=c++17 -I./src -I./src/imgui -I./src/imgui-sfml -I/usr/include/SFML -I./model/headers -I./model/src 
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -pthread

SRC = src/main.cpp $(wildcard src/imgui/*.cpp)\
	 $(wildcard src/imgui-sfml/*.cpp)\
	 $(wildcard model/src/*.cpp)\
	 $(wildcard model/src/Utils/*.cpp)\
	 $(wildcard model/src/CQualities/*.cpp)

OBJ = $(SRC:.cpp=.o)
TARGET = A1

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
