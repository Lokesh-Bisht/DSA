#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the count of distinct elements in every window 
 * of size 'k' in the array.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

vector<int> countDistinct(vector<int>& nums, int n, int k) {
  unordered_map<int, int> map;
  vector<int> ans;
  int count = 0;
  for (int i = 0; i < k; ++i) {
    if (map.find(nums[i]) == map.end()) {
      count++;
    }
    map[nums[i]]++;
  }
  ans.push_back(count);
  for (int i = k; i < n; ++i) {
    map[nums[i - k]]--;
    if (map[nums[i - k]] == 0) count--;
    if (map[nums[i]] == 0) count++;
    map[nums[i]]++;
    ans.push_back(count);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, num;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    vector<int> ans = countDistinct(nums, n, k);
    for (auto ele: ans) {
      cout << ele << " ";
    }
    cout << '\n';
  }
}