TARGET = jvm
FLAGS = -Wall -std=c++17 -m32 -lm
LEITOR = ./leitor/leitor.cpp ./leitor/utf8.cpp 
EXTRA = FrameStack/frameStack.cpp JVM/jvm.cpp MethodArea/methodArea.cpp Instruction/instructions.cpp
all:
	g++ $(FLAGS) $(EXTRA) $(LEITOR) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)