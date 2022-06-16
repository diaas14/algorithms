/**
 * Given an array nums of distinct integers, 
 * return all the possible permutations.
 * You can return the answer in any order.
 */

class Solution {
    
    static void permutation(List<List<Integer>> list, List<Integer> nums, List<Integer> perm) {
        if (nums.size() == 0) {
            list.add(new ArrayList<Integer>(perm));
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            int num = nums.get(i);
            perm.add(num);
            nums.remove(i);
            permutation(list, nums, perm);
            perm.remove(perm.size()-1);
            nums.add(i, num);
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List <Integer> numbers = new ArrayList<Integer>(nums.length);
        for (int i : nums){
            numbers.add(i);
        }
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        permutation(list, numbers, new ArrayList()); 
        return list;
    }
}
