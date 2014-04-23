# Chris Miller (imperator@pax-imperia.com), CS124
# Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
# Academic endorsement.  This code is not licensed for commercial use.
# 20140422, Chapter 18 Programming Challenge 1 - 5, 7

CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall -g
SOURCES=ch18pc1-5,7.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch18pc1-5,7

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fv $(EXECUTABLE) $(OBJECTS)
