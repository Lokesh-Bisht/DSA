#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given an array of size 'n'. Find top 'k' frequent elements
 * which have the highest frequency in the array. 
 * 
 * Note: Print the elements according to the frequency count (from 
 * highest to lowest) and if the frequency is equal then larger number 
 * will be given preference.
 * 
 * nums = {1, 1, 2, 2, 3, 3, 3, 4}, k = 2
 * O/p: {3, 2}
 *  
 * TC: O(nlogn)
 * SC: O(n)
 * AC: O(n)
 */

bool cmp(pair<int, int> num1, pair<int, int> num2) {
  if (num1.second == num2.second) return num1.first > num2.first;
  return num1.second > num2.second;
}

vector<int> topKFrequenElements(vector<int>& nums, int n, int k) {
  unordered_map<int, int> map;
  for (int i = 0; i < n; ++i) {
    map[nums[i]]++;
  }
  vector<pair<int, int>> freq(map.begin(), map.end());
  sort(freq.begin(), freq.end(), cmp);
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    ans.push_back(freq[i].first);
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
    vector<int> ans = topKFrequenElements(nums, n, k);
    for (auto ele : ans) {
      cout << ele << " ";
    }
    cout << '\n';
  }
  return 0;
}