#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'x'. Check if 
 * the array contains a triplet that sums upto 'x'.
 * TC: O(n2 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

bool findTripletSum(vector<int>& nums, int n, int x) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n-2; ++i) {
    int currentElement = nums[i];
    int l = i + 1, r = n - 1;
    while (l < r) {
      if (nums[l] + nums[r] + currentElement == x) return true;
      if (nums[l] + nums[r] + currentElement > x) r--;
      else l++;
    }
  }
  return false;
}