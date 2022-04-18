#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'k'. Find three 
 * numbers in the array such that the sum is closest to 'k'. Return
 * the sum of the triplets.
 * Note: If their exists more than one answer then return the maximum sum.
 * 
 * nums = -7 9 8 3 1 1, k = 2
 * O/p: 2 {-7, 8, 1}
 *  
 * TC: O(n2 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

int closestTripletSum(vector<int>& nums, int n, int k) {
  sort(nums.begin(), nums.end());
  int ans = INT_MAX;
  for (int i = 0; i < n-2; ++i) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum == k) {
        return k;
      }
      if (sum > k) {
        int diff = sum - k;
        int curDiff = abs(ans - k);
        if (curDiff >= diff) {
          ans = sum;
        }
        r--;
      } else {
        int diff = k - sum;
        int curDiff = abs(ans - k);
        if (curDiff > diff) {
          ans = sum;
        }
        l++;
      }
    }
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
    cout << closestTripletSum(nums, n, k) << '\n';
  }
  return 0;
}