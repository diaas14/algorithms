/**
 * Question:
 * Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 */
 
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1, high=n, mid;
        while (low<high) {
            mid = low + (high - low)/2;
            if (isBadVersion(mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};
