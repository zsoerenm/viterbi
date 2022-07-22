# Makefile for viterbi codec.
#
# Created by: Min Xu <mxu@scu.edu> or <xukmin@gmail.com>
# Date: 01/30/2015

TARGET = libviterbi.so

all: $(TARGET)

clean:
	$(RM) *.o $(BINS)

test: viterbi_test
	./viterbi_test

viterbi.o: viterbi.cpp viterbi.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

viterbi_wrapper.o: viterbi_wrapper.cpp viterbi.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

viterbi_test.o: viterbi_test.cpp viterbi.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

viterbi_test: viterbi_test.o viterbi.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

$(TARGET): viterbi_wrapper.o viterbi.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -shared $^ -o $(TARGET)

.PHONY: all clean test

