/*
Day 30 - Search in Rotated Sorted Array

Problem Name:
Search in Rotated Sorted Array

Problem Statement:
Given a rotated sorted array 'arr' and a target value 'key',
find the index of 'key' in the array. If not found, return -1.

Approach:
- Use modified binary search to handle rotation:
  - Check which half (left or right) is sorted.
  - If left half is sorted, check if key lies within that half.
    - If yes, search left half.
    - Else, search right half.
  - If right half is sorted, check if key lies within that half.
    - If yes, search right half.
    - Else, search left half.
- Continue until the element is found or search space is exhausted.

Time Complexity: O(log n)
Space Complexity: O(1)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[start] <= arr[mid]) {  // Left half sorted
                if (arr[start] <= key && key <= arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {  // Right half sorted
                if (arr[mid] <= key && key <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;  // Key not found
    }
};
