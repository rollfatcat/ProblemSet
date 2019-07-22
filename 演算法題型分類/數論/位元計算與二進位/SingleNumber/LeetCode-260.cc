/* LeetCode-136 的加強版
 * Given an array of numbers nums, in which exactly two elements appear only once and 
 * all the other elements appear exactly twice. Find the two elements that appear only once.
 * 利用 XOR 可以求得 a^b 的答案，且已知 a≠b，我們可以找到 a b 從右邊數來第一個不同的位數：(a^b) & -(a^b)
 * 之後重新遍歷整個 vector 時把每個數字檢查這個位數是否為1 各自取 XOR 後即可以各自找到。
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums,int ret=0){
        for(int now:nums)
            ret^=now;
        int one_from_right=ret&-ret;
        int a=0, b=0;
        for(unsigned int now:nums)
            (now&one_from_right)? a^=now: b^=now;
        return {a,b};
            
    }
};