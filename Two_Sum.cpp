/**
 * Question:
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
 * find two numbers such that they add up to a specific target number. 
 * Let these two numbers be numbers[index1] and numbers[index2] 
 * where 1 <= first < second <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, 
 * as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution.
 * You may not use the same element twice.
 */

# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0, high=numbers.size()-1;
        int sum;
        while (low < high) {
            if ((sum = numbers[low] + numbers[high]) == target)
                return vector<int>({low + 1, high + 1});
            if (sum < target)
                low++;
            else 
                high--;
        }
        return vector<int>();
    }
};
