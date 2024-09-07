CC = "/c/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/bin/clang.exe"
CFLAGS = -Wall -Wextra
TARGET = learning.exe
SRC = learning.c

all: $(TARGET)
	@echo "Build complete. Running executable..."
	@./$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)


clean:
	@rm -f $(TARGET)