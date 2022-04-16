#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the first repeating element.
 * 1 5 3 4 3 5 6
 * O/P => 5
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int findFirstRepeatingElement(vector<int>& nums, int n) {
  unordered_map<int, int> map;
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    map[nums[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    if (map[nums[i]] > 1) {
      ans = i + 1;
      break;
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
    int n, num;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    cout << findFirstRepeatingElement(nums, n) << '\n';
  }
}