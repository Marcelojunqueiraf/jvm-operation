TARGET = jvm 
FLAGS = -Wall -std=c++17 -lm
LEITOR = ./leitor/leitor.cpp ./leitor/utf8.cpp 
EXTRA = FrameStack/frameStack.cpp JVM/jvm.cpp MethodArea/methodArea.cpp Instruction/instructions.cpp Heap/Heap.cpp
all:
	g++ $(FLAGS) $(EXTRA) $(LEITOR) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)