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

void merge(vector<int>& nums, int l, int mid, int r) {
  if (l < r) {
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
      if (nums[i] <= nums[j]) {
        temp.push_back(nums[i++]);
      } else {
        temp.push_back(nums[j++]);
      }
    }
    while (i <= mid) {
      temp.push_back(nums[i++]);
    }
    while (j <= r) {
      temp.push_back(nums[j++]);
    }
    for (int i = l, j = 0; i <= r; ++i, ++j) {
      nums[i] = temp[j];
    }
  }
}

void mergeSort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    merge(nums, l, mid, r);
  }
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
    mergeSort(nums, 0, n-1);
    for (auto num : nums) {
      cout << num << " ";
    }
    cout << '\n';
  }
  return 0;
}