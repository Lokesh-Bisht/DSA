#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Print all unique numbers in range 'l' to 'r'. Unique numbers
 * are those numbers that have distinct numbers in its digits.
 * 
 * l = 10 r = 20
 * O/p: 10 12 13 14 15 16 17 18 19 20
 *  
 * TC: O(n)
 * SC: O(1)
 * AC: O(n)
 */


vector<int> uniqueNumbers(int l, int r) {
  vector<int> ans;
  for (int i = l; i <= r; ++i) {
    string str = to_string(i);
    unordered_set<int> uniqueDigits(str.begin(), str.end());
    if (uniqueDigits.size() == str.size()) {
      ans.push_back(i);
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
    int l, r;
    cin >> l >> r;
    vector<int> ans = uniqueNumbers(l, r);
    for (auto ele : ans) {
      cout << ele << " ";
    }
    cout << '\n';
  }
  return 0;
}