#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the smallest window in the string 'S' consisting of 
 * all the characters(including duplicates) of the string 'P'.
 * Return "-1" in case there is no such window present. In case there 
 * are multiple such windows of same length, return the one with the 
 * least starting index. 
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(26)
 */

string smallestWindowContainingAllCharacters(string s, string p) {
  unordered_map<char, int> map, map2;
  int minLen = INT_MAX;
  int count = 0, start = 0, idx = 0;
  for (int i = 0; i < p.size(); ++i) map[p[i]]++;
  for (int i = 0; i < s.size(); ++i) {
    map2[s[i]]++;
    if (map.find(s[i]) != map.end()) {
      if (map2[s[i]] <= map[s[i]]) {
        count++;
      }
    }
    while (count == p.size() && start < s.size()) {
      if (map.find(s[start]) != map.end()) {
        if (map2[s[start]] >= map[s[start]]) {
          if (minLen > i - start + 1) {
            minLen = i - start + 1;
            idx = start;
          }
        }
        if (map2[s[start]] <= map[s[start]]) count--;
      }
      map2[s[start]]--;
      start++;
    }
  }
  return minLen == INT_MAX ? "-1" : s.substr(idx, minLen);
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, p;
    cin >> s >> p;
    cout << smallestWindowContainingAllCharacters(s, p) << '\n';
  }
  return 0;
}