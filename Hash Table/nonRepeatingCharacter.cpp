#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the first non-repeating character in String 'str'. If 
 * there is no such character then return '$'.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(26)
 */

int findFirstNonRepeatingCharacter(string str) {
  int freq[26];
  memset(freq, 0, sizeof freq);
  for (int i = 0; i < str.size(); ++i) {
    freq[str[i] - 'a']++;
  }
  for (int i = 0; i < str.size(); ++i) {
    if (freq[str[i] - 'a'] == 1) {
      return str[i];
    }
  }
  return '$';
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    cout << findFirstNonRepeatingCharacter(str) << '\n';
  }
}