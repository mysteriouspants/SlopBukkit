# Chris Miller (imperator@pax-imperia.com), CS124
# Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
# Academic endorsement.  This code is not licensed for commercial use.
# 20140217, Chapter 13 Programming Challenge 6

CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall -c
SOURCES=main.cpp inventory.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch13pc6

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@
	
.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm ch13pc6 main.o inventory.o