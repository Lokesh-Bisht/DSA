#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'k'. Chef if the 
 * array can be divided into pairs such that sum of every pair is 
 * divisible by k.
 *  
 * TC: O(n)
 * SC: O(n)
 * AC: O(k)
 */

bool canAllPairsDivideK(vector<int>& nums, int n, int k) {
  unordered_map<int, int> freq;
  for (int i = 0; i < n; ++i) {
    freq[nums[i] % k]++;
  }
  if (freq[0] % 2) {
    return false;
  }
  for (int i = 0; i < k; ++i) {
    if (freq[i] != freq[k - i]) {
      return false;
    }
  }
  return true;
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
    canAllPairsDivideK(nums, n, k) ? cout << "Yes" << '\n' : cout << "No" << '\n';
  }
  return 0;
}