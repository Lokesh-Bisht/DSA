#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Merge overlapping intervals.
 * {(1, 9), (2, 4)}
 * {(1, 9)}
 * 
 * TC: O(n * log n)
 * SC: O(n)
 * AC: O(n)
 */

bool cmp(pair<int, int> num1, pair<int, int> num2) {
  if (num1.first == num2.first) return num1.second < num2.second;
  return num1.first < num2.first;
}

vector<pair<int, int>> mergeOverlappingIntervals(
  vector<pair<int, int>>& intervals, int n) {
    sort(intervals.begin(), intervals.end(), cmp);
    int start = intervals[0].first, end = intervals[0].second;
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; ++i) {
      if (end >= intervals[i].first) {
        end = max(end, intervals[i].second);
      } else {
        ans.push_back({start, end});
        start = intervals[i].first;
        end = intervals[i].second;
      }
    }
    ans.push_back({start, end});
    return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
      int num1, num2;
      cin >> num1 >> num2;
      intervals.push_back({num1, num2});
    }
    vector<pair<int, int>> ans = mergeOverlappingIntervals(intervals, n);
    for (auto pair : ans) {
      cout << pair.first << " " << pair.second << '\n';
    }
  }
  return 0;
}