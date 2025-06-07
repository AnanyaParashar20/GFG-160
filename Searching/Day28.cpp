/*
Day 28 - Number of Occurrences

Problem Name:
Count Frequency of a Number in a Sorted Array

Problem Statement:
Given a sorted integer array 'arr' and a target value 'target',
find the total number of occurrences of the target in the array.

Approach:
- Use binary search twice:
  1. Find the first occurrence index of the target.
  2. Find the last occurrence index of the target.
- If the target is not found (first occurrence index == -1), return 0.
- Otherwise, frequency = last occurrence index - first occurrence index + 1.

Time Complexity: O(log n) due to binary search.
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int firstidx = -1, lastidx = -1;
        int mid;
        
        // Find first occurrence of target
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == target) {
                firstidx = mid;
                high = mid - 1;  // search left half for earlier occurrence
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (firstidx == -1) return 0;  // target not found
        
        low = 0; high = n - 1;
        
        // Find last occurrence of target
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == target) {
                lastidx = mid;
                low = mid + 1;  // search right half for later occurrence
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return lastidx - firstidx + 1;
    }
};
