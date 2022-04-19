#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given two sorted (in non-decreasing order) arrays. Merge the 
 * two arrays into one sorted array in non-decreasing order without
 * using any extra space.
 * 
 * TC: O((n + m) * log (n + m))
 * SC: O(n)
 * AC: O(1)
 */


int nextGap(int gap) {
  if (gap <= 1) {
    return 0;
  }
  return gap / 2 + gap % 2;
}


// Use the gap method
void merge(vector<int>& nums1, vector<int>& nums2, int n, int m) {
  int gap = nextGap(n + m);
  while (gap > 0) {
    int i = 0, j = gap > n ? gap - n : 0;
    // comparing elements in the first array
    for (; i < n-gap; ++i) {
      if (nums1[i] > nums1[i + gap]) {
        swap(nums1[i], nums1[i + gap]);
      }
    }
    // comparing elements in the first and second array
    for (; i < n && j < m; ++i, ++j) {
      if (nums1[i] > nums2[j]) {
        swap(nums1[i], nums2[j]);
      }
    }
    // comparing elements in the second array
    if (j < m) {
      for (j = 0; j < m-gap; ++j) {
        if (nums2[j] > nums2[j + gap]) {
          swap(nums2[j], nums2[j + gap]);
        }
      }
    }
    gap = nextGap(gap);
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      nums1.push_back(num);
    }
    for (int i = 0; i < m; ++i) {
      int num;
      cin >> num;
      nums2.push_back(num);
    }
    merge(nums1, nums2, n, m);
    for (int i = 0; i < n; ++i) cout << nums1[i] << " ";
    for (int j = 0; j < m; ++j) cout << nums2[j] << " ";
    cout << '\n';
  }
  return 0;
}