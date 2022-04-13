#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of size 'n'. Check if it contains a 
 * triplet that sums upto zero.
 * TC: O(n2 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

bool findTripletSum(vector<int>& nums, int n) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n-3; ++i) {
    int currentElement = nums[i];
    int l = i + 1, r = n - 1;
    while (l < r) {
      if (nums[l] + nums[r] + currentElement == 0) return true;
      if (nums[l] + nums[r] + currentElement > 0) r--;
      else l++;
    }
  }
  return false;
}