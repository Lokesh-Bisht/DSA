#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given two arrays'. Sort the first array nums1[] such that 
 * all the relative positions of the elements in the first array are 
 * the same as the elements in the second array nums2[].
 * 
 * nums1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
 * nums2 = {2, 1, 8, 3}
 * O/p: 2 2 1 1 8 8 3 5 6 7 9
 *  
 * TC: O(n * log n)
 * SC: O(n + m)
 * AC: O(n + m)
 */

vector<int> sortNums1ByNums2(vector<int>& nums1, vector<int>& nums2, int n, int m) {
  vector<int> ans, ans2;
  unordered_map<int, int> map;
  unordered_set<int> keys;
  for (int i = 0; i < m; ++i) keys.insert(nums2[i]);
  sort(nums1.begin(), nums1.end());
  for (int i = 0; i < n; ++i) {
    if (keys.find(nums1[i]) != keys.end()) {
      map[nums1[i]]++;
    } else {
      ans2.push_back(nums1[i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    int count = keys.find(nums2[i]) != keys.end() ? map[nums2[i]] : 0;
    for (int j = 0; j < count; ++j) ans.push_back(nums2[i]);
  }
  for (int i = 0; i < ans2.size(); ++i) ans.push_back(ans2[i]);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, num;
    cin >> n >> m;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums1.push_back(num);
    }
     for (int i = 0; i < m; ++i) {
      cin >> num;
      nums2.push_back(num);
    }
    vector<int> ans = sortNums1ByNums2(nums1, nums2, n, m);
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}