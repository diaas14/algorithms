/** 
  * Question:
  * Given an array, rotate the array to the right by k steps, 
  * where k is non-negative.
  */

class Solution {
    
public:
    void rotate(vector<int>& nums, int k) {
        // removing redundant rotations
        k = k % nums.size();
        // number of possible cycles
        int cycles = __gcd((int)nums.size(), k), idx{}, temp{}, prev{};
        for (int i=0; i<cycles; i++) {
            idx = i;
            prev = nums[idx];
            do {
                // storing the number at (idx + k) % nums.size()
                // as it gets replaced
                temp = nums[(idx + k) % nums.size()];
                // assigning it the number originally at pos idx
                // that is currently stores at prev
                nums[(idx + k) % nums.size()] = prev;
                idx = (idx + k) % nums.size();
                prev = temp;
            } while (idx != i); // loop until the cycle is complete
        }
    }
};
