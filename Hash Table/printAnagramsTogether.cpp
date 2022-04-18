#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given an array of strings, return all groups of strings 
 * that are anagrams. The groups must be created in order of their 
 * appearance in the original array. 
 * {act,god,cat,dog,tac}
 * O/P :  act cat tac
 *        god dog 
 * 
 * TC: O(n * |s| log |s|)
 * SC: O(n * |s|)
 * AC: O(n * |s|)
 */

vector<vector<string>> getAnagrams(vector<string>& words, int n) {
  unordered_map<string, vector<string>> map;
  vector<vector<string>> ans;
  for (auto word : words) {
    string temp = word;
    sort(temp.begin(), temp.end());
    map[temp].push_back(word);
  }
  ans.resize(map.size());
  int i = 0;
  for (auto it = map.begin(); it != map.end(); ++it) {
    ans[i++] = it->second;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; ++i) {
      string str;
      cin >> str;
      words.push_back(str);
    }
    vector<vector<string>> anagramsList = getAnagrams(words, n);
    for (auto anagrams : anagramsList) {
      for (auto anagram : anagrams) {
        cout << anagram << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}