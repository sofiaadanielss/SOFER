# C++
CC = C:/raylib/w64devkit/bin/g++.exe

# Raylib
RAYLIB_PATH = C:/raylib/raylib

# Flags
CFLAGS = -Wall -std=c++17 -Iinclude -I$(RAYLIB_PATH)/src

# Windows
LDFLAGS = -L$(RAYLIB_PATH)/src -lraylib -lopengl32 -lgdi32 -lwinmm

# Folders
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Exe
TARGET = game

# Build
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET).exe $(OBJ) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f src/*.o
	rm -f $(TARGET).exe

