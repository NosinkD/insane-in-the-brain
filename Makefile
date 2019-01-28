CC = gcc
CXX = g++

INCLUDES = -I$(project_inc)
LIBRARIES = -L$(project_lib_x86)

project_inc = C:/Users/Genesis/Desktop/insande-in-the-brain-repo/include
project_lib_x86 = C:/Users/Genesis/Desktop/insande-in-the-brain-repo/lib/x86/debug

sdl2 = C:/Users/Genesis/Desktop/insande-in-the-brain-repo
sdl2_inc = $(sdl2)/include
sdl2_lib_x86 = $(sdl2)/lib/x86/debug

sdl2_image = C:/Users/Genesis/Desktop/insande-in-the-brain-repo
sdl2_image_inc = $(sdl2_image)/include
sdl2_image_lib_x86 = $(sdl2_image)/lib/x86/debug

glad = C:/Users/Genesis/Desktop/insande-in-the-brain-repo
glad_inc = $(glad)/include

CFLAGS = -Wall -g $(INCLUDES)
CXXFLAGS = -std=c++14 -Wall -g $(INCLUDES)
LDFLAGS = $(LIBRARIES) -llibSDL2 -llibSDL2main -llibSDL2_image -lopengl32 -lglu32 -lgdi32

TARGET = ./build/x86/debug/main.exe

cpp_files = ./source/main.cpp
cpp_files += ./source/Director.cpp
cpp_files += ./source/Demo.cpp
cpp_files += ./source/GameObject.cpp
cpp_files += ./source/Scene.cpp
cpp_files += ./source/Transform.cpp
cpp_files += ./source/SpriteRenderer.cpp
cpp_files += ./source/Video.cpp
cpp_files += ./source/Input.cpp
cpp_files += ./source/File.cpp

objects = $(cpp_files:.cpp=.o) ./source/glad.o
headers =

w_x86: $(TARGET)

$(TARGET): $(objects) 
	$(CXX) -o $@ $^ $(LDFLAGS)
	make clean

.PHONY : clean
clean :
	-rm $(objects)