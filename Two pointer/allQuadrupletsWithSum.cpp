#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'x'. Find all  
 * unique quadruplets that sums upto 'x'.
 * 
 * TC: O(n3 + nlogn)
 * SC: O(n)
 * AC: O(n2)
 */

vector<vector<int>> findAllUniqueQuadruplets(vector<int>& nums, int n, int x) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n-3; ++i) {
    for (int j = i + 1; j < n-2; ++j) {
      int l = j + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[j] + nums[l] + nums[r];
        if (sum == x) {
          ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
          // skip duplicates
          while (l < r && nums[l] == nums[l + 1]) ++l;
          while (l < r && nums[r] == nums[r - 1]) --r;
          l++, r--;
        }
        else if (sum > x) r--;
        else l++;
      }
      // skip duplicates
      while (j < n - 2 && nums[j] == nums[j + 1]) ++j;
      while (i < n - 3 && nums[i] == nums[i + 1]) ++i;
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
    vector<vector<int>> ans = findAllUniqueQuadruplets(nums, n, k);
    for (int i = 0; i < ans.size(); ++i) {
      for (auto quadruple : ans[i]) {
        cout << quadruple << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}