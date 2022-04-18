#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given two strings and an integer 'k'. Check if two strigs are 
 * k anagrams of each other or not. Two strings are called k-anagrams if:
 * 1. Both have same number of characters.
 * 2. Two strings can become anagram by changing atmost k characters in 
 * a string. 
 * 
 * TC: O(max(s, t))
 * SC: O(s + t)
 * AC: O(26)
 */

bool areKAnagrams(string s, string t, int k) {
  int freq[26], freq2[26];
  memset(freq, 0, sizeof freq);
  memset(freq2, 0, sizeof freq2);
  if (s.size() != t.size()) {
    return false;
  }
  for (int i = 0; i < s.size(); ++i) freq[s[i] - 'a']++;
  for (int i = 0; i < t.size(); ++i) freq2[t[i] - 'a']++;
  int diff = 0;
  for (int i = 0; i < 26; ++i) diff += abs(freq[i] - freq2[i]);
  diff /= 2;
  return diff <= k;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    string s, t;
    cin >> s >> t >> k;
    areKAnagrams(s, t, k) ? cout << "Yes" << '\n' : cout << "No" << '\n';
  }
  return 0;
}