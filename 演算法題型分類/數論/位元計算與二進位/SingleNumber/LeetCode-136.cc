/* Given a non-empty array of integers, every element appears "twice" except for one. 
 * Find that single one.
 * 利用 XOR 位元運算的特性：x^x=0，類似題：d708
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums)
                ans^=x;
        return ans;
    }
};