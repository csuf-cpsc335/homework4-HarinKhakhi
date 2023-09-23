#include "searching_algorithms.h"

#include<iostream>
using namespace std;

int randomized_select(vector<int> nums, int k, int start, int end){
    if(start > end) return -1;

    int pos = partition(nums, start, end);

    int left_size = pos - start;
    if(k < left_size)
        return randomized_select(nums, k, start, pos-1);
    else if(k > left_size)
        return randomized_select(nums, k-left_size-1, pos+1, end);

    return nums[pos];
}