//
//  main.cpp
//  Advance p exp 3
//
//  Created by saurav saha on 13/02/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // Use multiset instead of priority_queue
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Step 1: Create events (start and end of buildings)
        vector<pair<int, int>> events; // {x, height}
        for (const auto& building : buildings) {
            int left = building[0], right = building[1], height = building[2];
            events.push_back({left, -height}); // Start event (negative height)
            events.push_back({right, height});  // End event (positive height)
        }

        // Step 2: Sort events by x-coordinate
        // If two events have the same x-coordinate, process the start event first
        sort(events.begin(), events.end());

        // Step 3: Use a multiset to track the current maximum height
        multiset<int> heights; // Multiset allows duplicates and sorted order
        heights.insert(0); // Initialize with ground level (height 0)
        int prevMaxHeight = 0; // Track the previous maximum height

        vector<vector<int>> skyline;

        for (const auto& event : events) {
            int x = event.first, height = event.second;

            if (height < 0) {
                // Start event: add the building's height to the multiset
                heights.insert(-height);
            } else {
                // End event: remove the building's height from the multiset
                heights.erase(heights.find(height));
            }

            // Step 4: Check if the current maximum height has changed
            int currMaxHeight = *heights.rbegin(); // Get the maximum height
            if (currMaxHeight != prevMaxHeight) {
                skyline.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return skyline;
    }
};

// Helper function to print the skyline
void printSkyline(const vector<vector<int>>& skyline) {
    for (const auto& point : skyline) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;
}

// Main method to test the solution
int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> buildings1 = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline1 = solution.getSkyline(buildings1);
    cout << "Example 1 Output: ";
    printSkyline(skyline1); // Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

    // Example 2
    vector<vector<int>> buildings2 = {{0, 2, 3}, {2, 5, 3}};
    vector<vector<int>> skyline2 = solution.getSkyline(buildings2);
    cout << "Example 2 Output: ";
    printSkyline(skyline2); // Output: [[0,3],[5,0]]

    return 0;
}
