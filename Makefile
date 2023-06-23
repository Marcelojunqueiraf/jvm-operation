TARGET = jvm
FLAGS = -Wall -std=c++17 -lm
EXTRA = FrameStack/frameStack.cpp JVM/jvm.cpp MethodArea/methodArea.cpp 
all:
	g++ $(FLAGS) $(EXTRA) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)