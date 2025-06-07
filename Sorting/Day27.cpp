/*
Day 27 - Merge Without Extra Space

Problem:
Given two sorted arrays `a[]` and `b[]`, merge them in such a way that the elements after merging 
are sorted and stored in their respective arrays without using any extra space.

Constraints:
- Do not use any extra array or container.
- Both arrays should remain sorted after merging.

Approach:
- Use two pointers from end of `a` and start of `b`.
- Swap elements when a[i] > b[j] to move larger elements to the right.
- Finally, sort both arrays individually to complete the merge.

Time Complexity: O((n + m) * log(n + m))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int i = a.size() - 1;
        int j = 0;

        // Compare and swap elements if a[i] > b[j]
        while (i >= 0 && j < b.size()) {
            if (a[i] < b[j]) break;
            swap(a[i--], b[j++]);
        }

        // Sort both arrays individually
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
