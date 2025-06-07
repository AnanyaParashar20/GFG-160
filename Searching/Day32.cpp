/*
Day 32 - K-th Element of Two Sorted Arrays

Problem Name:
Find the K-th Element of Two Sorted Arrays

Problem Statement:
Given two sorted arrays 'a' and 'b' and an integer 'k',
find the k-th smallest element in the combined sorted order
of the two arrays without merging them.

Approach:
- Use binary search on the smaller array 'a' to partition both arrays.
- Calculate mid1 (partition in 'a') and mid2 (partition in 'b') such that mid1 + mid2 = k.
- Track the left and right elements around partitions (l1, r1 from 'a' and l2, r2 from 'b').
- Check if the partitions are valid:
    - If l1 <= r2 and l2 <= r1, the k-th element is max(l1, l2).
- Adjust search space:
    - If l1 > r2, move left in 'a' (high = mid1 - 1).
    - Else move right in 'a' (low = mid1 + 1).
- Handle edge cases by considering INT_MIN and INT_MAX as boundaries.

Time Complexity: O(log(min(m, n))) where m, n are sizes of arrays.
Space Complexity: O(1)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();
        if (m > n) return kthElement(b, a, k);  // Ensure a is smaller
        
        int low = max(0, k - n), high = min(k, m);
        
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
            if (mid1 < m) r1 = a[mid1];
            if (mid2 < n) r2 = b[mid2];
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};
