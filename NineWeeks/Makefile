.SUFFIXES: .cpp .o
PEOPLE = Vehicle.o bike.o car.o
TEST_FILE = main.o $(PEOPLE)
CXX = g++
TEST = main
$(TEST):$(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)

clean:
	rm -rf $(TEST) $(TEST_FILE)

main.o:main.cpp
Vehicle.o:Vehicle.cpp
car.o:car.cpp
bike.o:bike.cpp
