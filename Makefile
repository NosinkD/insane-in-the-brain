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

# Windows
W_INCLUDES = -IC:/Users/Genesis/Desktop/insane-in-the-brain-repo/include
# Windows x86 
DEBUG_W_x86_TARGET = main_debug.exe
DEBUG_W_x86_LIBRARIES = -LC:/Users/Genesis/Desktop/insane-in-the-brain-repo/lib/x86/debug
DEBUG_W_x86_LDFLAGS = $(DEBUG_W_x86_LIBRARIES) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32 -lglew32

# Objects
w_debug_x86: $(DEBUG_W_x86_TARGET)

# *.o files rule generator from *.cpp for w_debug_x86
$(DEBUG_BUILD_x86_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(W_INCLUDES) -c $< -o $@

# Application rule generator for w_debug_x86
$(DEBUG_W_x86_TARGET): $(DEBUG_OBJ_x86_FILES)
	$(CXX) -o $(DEBUG_BUILD_x86_DIR)/$@ $^ $(DEBUG_W_x86_LDFLAGS)

# Clear all generated files
clean:
	rm $(DEBUG_OBJ_x86_FILES)



