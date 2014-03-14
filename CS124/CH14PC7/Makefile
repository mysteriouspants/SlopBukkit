# Chris Miller (imperator@pax-imperia.com), CS124
# Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
# Academic endorsement.  This code is not licensed for commercial use.
# 20140313, Chapter 14 Programming Challenge 7

CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall
SOURCES=ch14pc7.cpp month.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch14pc7

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@
	
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fv $(EXECUTABLE) $(OBJECTS)
