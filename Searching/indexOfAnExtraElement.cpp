#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given two sorted arrays of distinct elements. There is 
 * only 1 difference between the arrays. First array has one element 
 * extra added in between. Find the index of the extra element.
 * 
 * nums1 = 2 4 6 8 9 10 12
 * depature = 2 4 6 8 10 12
 * O/p: 4
 *  
 * TC: O(log n)
 * SC: O(n)
 * AC: O(1)
 */


int findIndex(vector<int>& nums1, vector<int>& nums2, int n) {
  int l = 0, r = n - 2;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums1[mid] == nums2[mid]) {
      l = mid + 1;
    } else if (nums1[mid + 1] == nums2[mid]) {
      r = mid - 1;
    }
    return l;
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
    vector<int> nums1, nums2;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums1.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums2.push_back(num);
    }
    cout << findIndex(nums1, nums2, n) << '\n';
  }
  return 0;
}