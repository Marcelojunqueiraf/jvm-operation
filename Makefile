TARGET = jvm 
FLAGS = -Wall -std=c++17 -lm -Wno-unknown-pragmas
LEITOR = ./leitor/leitor.cpp ./leitor/utf8.cpp 
EXTRA = FrameStack/frameStack.cpp JVM/jvm.cpp MethodArea/methodArea.cpp Instruction/instructions.cpp Heap/heap.cpp
all:
	g++ $(FLAGS) $(EXTRA) $(LEITOR) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)