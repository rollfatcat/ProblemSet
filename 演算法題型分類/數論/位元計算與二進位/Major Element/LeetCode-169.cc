class Solution {
public:
    /* Boyer–Moore majority vote algorithm(摩爾投票算法)
     * 假設 majority element 的數量過半時，刪去一個數列中的兩個不同的數字，不會影響該數列的 majority element。
     */
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int cnt = 1;
        
        // Boyer-Moore Voting Algorithm
        for (int i=1; i<nums.size();i++){
            if(res==nums[i])
                cnt++;
            else if(cnt>0)
                cnt--;
            else
                res=nums[i],
                cnt++;
        }
        return res;
    }
};