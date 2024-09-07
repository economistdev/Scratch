# Default settings
CFLAGS = -Wall -Wextra
SRC = learning.c

# Detect if we're on WSL or macOS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)  # WSL
    ifneq ($(shell grep -i microsoft /proc/version),)  # Detect WSL
        CC = "/c/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/bin/clang.exe"
        TARGET = learning.exe
    else  # Regular Linux (not WSL)
        CC = clang
        TARGET = learning.out
    endif
else ifeq ($(UNAME_S),Darwin)  # macOS
    CC = clang
    TARGET = learning.out
endif

# Build target
all: $(TARGET)
	@echo "Build complete. Running executable..."
	@./$(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean rule
clean:
	@rm -f $(TARGET)
