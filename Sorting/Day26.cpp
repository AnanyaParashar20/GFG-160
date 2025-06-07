/*
Day 68 - Non-overlapping Intervals

Problem:
Given a 2D array intervals[][] where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Approach:
- Sort intervals based on starting time.
- Use a greedy two-pointer approach to compare overlapping intervals.
- Count the number of intervals to remove based on end times.

Time Complexity: O(n log n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());  // Sort by starting times

        int n = intervals.size();
        int cnt = 0;
        int i = 0, j = 1;

        while (j < n) {
            int cs = intervals[i][0];  // Current start
            int ce = intervals[i][1];  // Current end

            int ns = intervals[j][0];  // Next start
            int ne = intervals[j][1];  // Next end

            if (ce <= ns) {
                // No overlap, move both pointers
                i = j;
                j++;
            } else if (ce <= ne) {
                // Overlap: remove the next one (current ends earlier)
                j++;
                cnt++;
            } else if (ce > ne) {
                // Overlap: remove the current one (next ends earlier)
                i = j;
                j++;
                cnt++;
            }
        }

        return cnt;
    }
};
