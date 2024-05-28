CXX=g++
CXXFLAGS=-g -Wall -pg
PROGS=max_subarray_sum_1 max_subarray_sum_2 max_subarray_sum_3

.PHONY: all clean

all: $(PROGS)

max_subarray_sum_1: max_subarray_sum_1.cpp
	$(CXX) $(CXXFLAGS) -o max_subarray_sum_1 max_subarray_sum_1.cpp

max_subarray_sum_2: max_subarray_sum_2.cpp
	$(CXX) $(CXXFLAGS) -o max_subarray_sum_2 max_subarray_sum_2.cpp

max_subarray_sum_3: max_subarray_sum_3.cpp
	$(CXX) $(CXXFLAGS) -o max_subarray_sum_3 max_subarray_sum_3.cpp

clean:
	rm -f $(PROGS) gmon.out

# exapmle of usage "gprof":
# ./max_subarray_sum_1 42 10000
# gprof max_subarray_sum_1 gmon.out > analysis.txt