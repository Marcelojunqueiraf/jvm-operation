TARGET = exec
FLAGS = -Wall -std=c++11 -lm -Wno-unknown-pragmas
LEITOR = ./leitor/leitor.cpp ./leitor/utf8.cpp
EXIBIDOR = ./exibidor/exibidor.cpp
EXTRA = FrameStack/frameStack.cpp JVM/jvm.cpp MethodArea/methodArea.cpp Instruction/instructions.cpp Heap/heap.cpp common/converters.cpp
all:
	g++ $(FLAGS) $(EXTRA) $(LEITOR) $(EXIBIDOR) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)