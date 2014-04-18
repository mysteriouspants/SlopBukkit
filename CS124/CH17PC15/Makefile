# Chris Miller (imperator@pax-imperia.com), CS124
# Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
# Academic endorsement.  This code is not licensed for commercial use.
# 20140417, Chapter 17 Programming Challenge 15

CXX=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall
SOURCES=ch17pc15.cpp linked_list.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ch17pc15

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fv $(EXECUTABLE) $(OBJECTS)
