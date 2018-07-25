CXX = g++


CXXFLAGS += -std=c++14 -g
all:main
	$(RM) *.o
	@main


main:main.o
	$(CXX) $^ -pthread -latomic -o $@
	
clean:
	$(RM) *.o main