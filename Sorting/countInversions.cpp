#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using ll = long long;

/**
 * Problem: Given an array of integers. Find the inversion count in the
 * array. For an array, inversion count indicates how far (or close) the 
 * array is from being sorted. If array is already sorted then the 
 * inversion count is 0. 
 * 
 * Formally, two elements nums[i] and nums[j] form an inversion 
 * if nums[i] > nums[j] and i < j.
 * 
 * TC: O(n * log n)
 * SC: O(n)
 * AC: O(n)
 */

ll merge(vector<int>& nums, int l, int mid, int r) {
  vector<int> temp;
  int i = l, j = mid + 1;
  ll inversionsCount = 0;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      temp.push_back(nums[i++]);
    } else {
      // all the elements in the left subarray are sorted > nums[i]
      inversionsCount += mid - i + 1;
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
  return inversionsCount;
}

ll mergeSort(vector<int>& nums, int l, int r) {
  ll inversionsCount = 0;
  if (l < r) {
    int mid = (l + r) / 2;
    inversionsCount += mergeSort(nums, l, mid);
    inversionsCount += mergeSort(nums, mid + 1, r);
    inversionsCount += merge(nums, l, mid, r);
  }
  return inversionsCount;
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
    ll inversionsCount = mergeSort(nums, 0, n-1);
    cout << inversionsCount << '\n';
  }
  return 0;
}