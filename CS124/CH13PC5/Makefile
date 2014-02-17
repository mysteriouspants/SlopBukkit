CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall -c
SOURCES=main.cpp retail_item.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch13pc5

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@
	
.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm ch13pc5 main.o retail_item.o