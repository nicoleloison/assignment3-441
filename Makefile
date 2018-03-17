CXX=clang++-3.5
CXXFLAGS = -Wall -Werror -std=c++11
LDLIBS = -lpthread

SOURCES = readmap.cpp calcpath.cpp showresults.cpp

%: %.cxx
    $(CXX) $(CXXFLAGS) -o $@.out $^ $(LDLIBS)
ifneq (,$(findstring r,  $(MAKEFLAGS)))
    ./$@.out
endif

all: $(SOURCES)

.PHONY: clean

clean:
    find . -name "*.out" -delete