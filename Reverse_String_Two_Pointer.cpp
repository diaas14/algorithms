/**
 * Question:
 * Write a function that reverses a string. 
 * The input string is given as an array of characters s.
 */
 
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right=s.size()-1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left++;
            right--;
        }
    }
};
