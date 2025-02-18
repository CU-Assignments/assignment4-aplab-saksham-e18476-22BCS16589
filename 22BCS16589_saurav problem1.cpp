//
//  main.cpp
//  Advance p exp 3
//
//  Created by saurav saha on 13/02/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        // Base case: If n is 1, return [1]
        if (n == 1) {
            return {1};
        }

        // Recursively construct the beautiful array for the first half (odd numbers)
        vector<int> odd = beautifulArray((n + 1) / 2);

        // Recursively construct the beautiful array for the second half (even numbers)
        vector<int> even = beautifulArray(n / 2);

        // Combine the two halves:
        // Multiply odd numbers by 2 and subtract 1 to get odd numbers in the range [1, n]
        // Multiply even numbers by 2 to get even numbers in the range [1, n]
        vector<int> result;
        for (int num : odd) {
            result.push_back(2 * num - 1);
        }
        for (int num : even) {
            result.push_back(2 * num);
        }

        return result;
    }
};

// Helper function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Main method to test the solution
int main() {
    Solution solution;

    int n1 = 4;
    vector<int> result1 = solution.beautifulArray(n1);
    cout << "Example 1 Output: ";
    printArray(result1); // Output: [2, 1, 4, 3]

    int n2 = 5;
    vector<int> result2 = solution.beautifulArray(n2);
    cout << "Example 2 Output: ";
    printArray(result2); // Output: [3, 1, 2, 5, 4]

    return 0;
}
