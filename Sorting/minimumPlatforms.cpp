#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given arrival and departure times of all trains that reach 
 * a railway station. Find the minimum number of platforms required 
 * for the railway station so that no train is kept waiting.
 * 
 * Consider that all the trains arrive on the same day and leave on the 
 * same day. Arrival and departure time can never be the same for a train 
 * but we can have arrival time of one train equal to departure time of 
 * the other. At any given instance of time, same platform can not be 
 * used for both departure of a train and arrival of another train. In 
 * such cases, we need different platforms.
 * 
 * arrival = {0900, 0940, 0950, 1100, 1500, 1800}
 * depature = {0910, 1200, 1120, 1130, 1900, 2000}
 * O/p: 3
 *  
 * TC: O(n * log n)
 * SC: O(n)
 * AC: O(n)
 */


int getPlatformsNeeded(vector<int>& arrival, vector<int>& departure, int n) {
  int ans = 1;
  int i = 1, j = 0, platformsNeeded = 1;
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());
  while (i < n && j < n) {
    if (arrival[i] <= departure[j]) {
      i++;
      platformsNeeded++;
    } else {
      j++;
      platformsNeeded--;
    }
    ans = max(ans, platformsNeeded);
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
    vector<int> arrival, departure;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      arrival.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
      cin >> num;
      departure.push_back(num);
    }
    cout << getPlatformsNeeded(arrival, departure, n) << '\n';
  }
  return 0;
}