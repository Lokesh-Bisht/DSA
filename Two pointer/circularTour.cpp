#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Suppose there is a circle. There are N petrol pumps on 
 * that circle. You are given two arrays:
 * 
 * Petrol[i]: The amount of petrol that every petrol pump has.
 * Distance[i]: Distance from that petrol pump to the next petrol pump.
 * Assume for 1 litre petrol, the truck can go 1 unit of distance.
 * 
 * Find a starting point where the truck can start to get through the 
 * complete circle without exhausting its petrol in between.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(1)
 */

int findStartingPoint(vector<int>& petrol, vector<int>& distance, int n) {
  int start = 0, end = 1;
  int curPetrol = petrol[0] - distance[0];
  while (start != end || curPetrol < 0) {
    while (start != end && curPetrol < 0) {
      curPetrol -= petrol[start] - distance[start];
      start = (start + 1) % n;
      if (start == 0) return -1;
    }
    curPetrol += petrol[end] - distance[end];
    end = (end + 1) % n;
  }
  return start;
}