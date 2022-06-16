/**
 * Given two integers n and k, 
 * return all possible combinations of k numbers out of the range [1, n].
 * You may return the answer in any order.
 */

class Solution {
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combs = new ArrayList<List<Integer>>();
        combination(combs, new ArrayList<Integer> (), n, k, 1);  
        return combs;
    }
    
    public static void combination(List<List<Integer>> combs, List<Integer> comb, int n, int k, int i) {
        if (k == 0) {
            combs.add(new ArrayList<Integer>(comb));
            return;
        }       
        for (int num=i; num<=n - k + 1; num++) {
            comb.add(num);
            combination(combs, comb, n, k-1, num+1);
            comb.remove(comb.size()-1);
        }
    }
}
