#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given two unsorted arrays of distinct elements. Find all 
 * pairs from both arrays whose sum is equal to 'x'.
 * 
 * Note: All pairs should be printed in increasing order of u. For eg. 
 * for two pairs (u1,v1) and (u2,v2), if u1<u2 then 
 * 
 * TC: O(n * log n)
 * SC: O(n)
 * AC: O(n)
 */

bool cmp(pair<int, int> num1, pair<int, int> num2) {
  if (num1.first == num2.first) return num1.second < num2.second;
  return num1.first < num2.first;
}

vector<pair<int, int>> findAllPairs(vector<int>& nums1, vector<int>& nums2, 
int n, int m, int x) {
  unordered_set<int> keys;
  for (int i = 0; i < n; ++i) {
    keys.insert(nums1[i]);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < m; ++i) {
    if (keys.find(x - nums2[i]) != keys.end()) {
      ans.push_back({x - nums2[i], nums2[i]});
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, num, x;
    cin >> n >> m >> x;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums1.push_back(num);
    }
    for (int i = 0; i < m; ++i) {
      cin >> num;
      nums2.push_back(num);
    }
    vector<pair<int, int>> ans = findAllPairs(nums1, nums2, n, m, x);
    for (auto pair : ans) {
      cout << pair.first << " " << pair.second << '\n';
    }
  }
  return 0;
}