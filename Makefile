#OBJS specifies which files to compile as part of the project 
OBJS = 	./source/*.cpp

#CC specifies which compiler we're using 
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
WINDOWS_INCLUDE =
WINDOWS_LIBS_x86 =

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -std=c++11 c++ default
# -w suppresses all warnings 
# -g GDB Support
COMPILER_FLAGS = -std=c++14 -w -g -Wall

#LINKER_FLAGS specifies the libraries we're linking against 
WINDOWS_LINK_x86 =

#OBJ_NAME specifies the name of our exectuable 
WINDOWS_OUTPUT = ./build/main.exe

#This is the target that compiles our executable 
w_x86 : $(OBJS) 
	$(CC) $(OBJS) $(WINDOWS_INCLUDE) $(WINDOWS_LIBS_x86) $(COMPILER_FLAGS) $(WINDOWS_LINK_x86) -o $(WINDOWS_OUTPUT)