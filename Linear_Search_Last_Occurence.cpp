/**
 * Question:
 * You have been given an array of size N consisting of integers. 
 * In addition you have been given an element M you need to find and 
 * print the index of the last occurrence of this element M 
 * in the array if it exists in it, otherwise print -1. 
 * Consider this array to be 1 indexed.
 */

class Solution {
  int lastOccurence(vector<int> arr, int num) {
    int pos=-1;
    for (int i=0; i<arr.size(); i++) {
      if (arr[i] == num) pos = i+1;
    }
    return pos;
  }
}
