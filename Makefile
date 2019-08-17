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

# Detectin OS
OS = $(shell uname -s | tr A-Z a-z)

# Linux
L_INCLUDES = -I/usr/include
# Linux x86
DEBUG_L_X86_LIBRARIES = -L/usr/lib 
DEBUG_L_X86_LIBRARIES += -lSDL2main -lSDL2 -lSDL2_image -lOpenGL -lGLEW

# Application rule generator for L_debug_x86
l_debug_x86: $(DEBUG_OBJ_x86_FILES)
	$(CXX) -o $(DEBUG_BUILD_x86_DIR)/main.out $(DEBUG_L_X86_LIBRARIES) $^

# Windows
W_INCLUDES = -I./include
# Windows x86 
DEBUG_W_x86_LIBRARIES = -L./lib/x86/debug 
DEBUG_W_x86_LIBRARIES += -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32 -lglew32

# Application rule generator for w_debug_x86
w_debug_x86: $(DEBUG_OBJ_x86_FILES)
	$(CXX) -o $(DEBUG_BUILD_x86_DIR)/main.exe $^ $(DEBUG_W_x86_LIBRARIES)

# Compilation
INCLUDES =
ifeq ($(OS),linux)
	INCLUDES = $(L_INCLUDES)
endif
ifeq ($(OS), msys_nt-10.0)
	INCLUDES = $(W_INCLUDES)
endif

# *.o files rule generator from *.cpp for w_debug_x86
$(DEBUG_BUILD_x86_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clear all generated files
clean:
	rm -f $(DEBUG_OBJ_x86_FILES)
	rm -f $(DEBUG_BUILD_x86_DIR)/*exe
	rm -f $(DEBUG_BUILD_x86_DIR)/*out