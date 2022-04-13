#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of distinct integers. Count the number
 * of triplets such that sum of triplets is less than 'sum'.
 * 
 * TC: O(n2 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

int findTripletSum(vector<int>& nums, int n, int sum) {
  sort(nums.begin(), nums.end());
  int count = 0;
  for (int i = 0; i < n-2; ++i) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      if (nums[i] + nums[l] + nums[r] < sum) {
        count += r - l;
        l++;
      }
      else {
        r--;
      }
    }
  }
  return count;
}