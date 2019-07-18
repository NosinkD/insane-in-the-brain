# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -std=c++14 -g -Wall -Werror -Wl,-subsystem,windows

# Directories
SRC_DIR = source
DEBUG_BUILD_x86_DIR = build/x86/debug

# Files
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
DEBUG_OBJ_x86_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(DEBUG_BUILD_x86_DIR)/%.o,$(CPP_FILES))

# Linux
L_INCLUDES = -I/usr/include
# Linux x86
DEBUG_L_X86_TARGET = main_debug.out
DEBUG_L_X86_LIBRARIES = -L/usr/lib32
DEBUG_L_X86_LDFLAGS = $(DEBUG_L_x86_LIBRARIES) -lSDL2main -lSDL2 -lSDL2_image -lOpenGL -lGLEW

# Application rule generator for L_debug_x86
l_debug_x86: $(DEBUG_OBJ_x86_FILES)
	$(CXX) -o $(DEBUG_BUILD_x86_DIR)/$(DEBUG_L_X86_TARGET) $(DEBUG_L_x86_LDFLAGS) $^

# Windows
W_INCLUDES = -IC:/Users/Genesis/Desktop/insane-in-the-brain-repo/include
# Windows x86 
DEBUG_W_x86_TARGET = main_debug.exe
DEBUG_W_x86_LIBRARIES = -LC:/Users/Genesis/Desktop/insane-in-the-brain-repo/lib/x86/debug
DEBUG_W_x86_LDFLAGS = $(DEBUG_W_x86_LIBRARIES) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32 -lglew32

# Application rule generator for w_debug_x86
w_debug_x86: $(DEBUG_OBJ_x86_FILES)
	$(CXX) -o $(DEBUG_BUILD_x86_DIR)/$(DEBUG_W_X86_TARGET) $^ $(DEBUG_W_x86_LDFLAGS)

# Compilation
# *.o files rule generator from *.cpp for w_debug_x86
$(DEBUG_BUILD_x86_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(L_INCLUDES) -c $< -o $@

# Clear all generated files
clean:
	rm $(DEBUG_OBJ_x86_FILES)



