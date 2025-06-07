/*
Day 29- Sorted and Rotated Minimum

Problem Name:
Find Minimum Element in a Sorted and Rotated Array

Problem Statement:
Given a sorted and rotated array 'arr' (without duplicates), 
find the minimum element in the array efficiently.

Approach:
- Use modified binary search:
  - Compare mid element with the rightmost element.
  - If arr[mid] < arr[right], minimum lies in the left half (including mid).
  - Else, minimum lies in the right half (excluding mid).
- Continue until left == right, which points to the minimum element.

Time Complexity: O(log n) due to binary search.
Space Complexity: O(1)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left];
    }
};
