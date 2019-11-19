.SUFFIXES: .cpp .o
PEOPLE = shared_ref.o weak_pointer.o human.o student.o smart_obj.o
TEST_FILE = test.o $(PEOPLE)
CXX = g++
TEST = test
$(TEST):$(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)

clean:
	rm -rf $(TEST) $(TEST_FILE)

test.o:test.cpp
student.o:student.cpp
human.o:human.cpp
shared_ref.o:shared_ref.cpp
smart_obj.o:smart_obj.cpp
weak_pointer.o:weak_pointer.cpp
