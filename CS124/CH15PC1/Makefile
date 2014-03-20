# Chris Miller (imperator@pax-imperia.com), CS124
# Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
# Academic endorsement.  This code is not licensed for commercial use.
# 20140319, Chapter 15 Programming Challenge 1

CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall
SOURCES=ch15pc1.cpp employee.cpp production_worker.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch15pc1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@
	
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fv $(EXECUTABLE) $(OBJECTS)
