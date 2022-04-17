#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;

/**
 * Problem: Given an array of size 'n'. Find the total count of 
 * sub-arrays having their sum equal to 0.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

ll subArraysWithZeroSum(vector<int>& nums, int n) {
  unordered_map<int, int> freq;
  ll sum = 0, count = 0;
  freq[0]++;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
    if (freq.find(sum) != freq.end()) {
      count += freq[sum];
    }
    freq[sum]++;
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, num;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    cout << subArraysWithZeroSum(nums, n) << '\n';
  }
  return 0;
}