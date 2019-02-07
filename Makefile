CC = gcc
CXX = g++

W_INCLUDES = -I$(w_project_inc)
L_INCLUDES = -I$(l_project_inc)

W_LIBRARIES = -L$(w_project_lib_x86)
L_LIBRARIES = -L$(l_project_lib_x86)

w_project_inc = C:/Users/Genesis/Desktop/insane-in-the-brain-repo/include
l_project_inc = /usr/include

w_project_lib_x86 = C:/Users/Genesis/Desktop/insane-in-the-brain-repo/lib/x86/debug
l_project_lib_x86 = /usr/lib32

CFLAGS = -Wall -g $(L_INCLUDES)
CXXFLAGS = -std=c++14 -Wall -g -w -Wl,-subsystem,windows $(L_INCLUDES)

W_LDFLAGS = $(W_LIBRARIES) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32 -lglew32
L_LDFLAGS = $(L_LIBRARIES) -lSDL2main -lSDL2 -lSDL2_image -lOpenGL -lGLEW

W_TARGET = ./build/x86/debug/main.exe

L_TARGET = ./build/x86/debug/main.out

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

objects = $(cpp_files:.cpp=.o)
headers =

w_x86: $(W_TARGET)

l_x86: $(L_TARGET)

$(L_TARGET) : $(objects) 
	$(CXX) -o $@ $^ $(L_LDFLAGS)
	make clean

$(W_TARGET): $(objects) 
	$(CXX) -o $@ $^ $(W_LDFLAGS)
	make clean

.PHONY : clean
clean :
	-rm $(objects)