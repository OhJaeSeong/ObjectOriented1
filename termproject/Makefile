.SUFFIXES: .cpp .o

OBJECTS = block.o
MAIN = main.o $(OBJECTS)
CXX = g++
DATA = data
TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean : 
	rm -rf $(MAIN) $(TARGET)

