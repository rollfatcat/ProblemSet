/* Given a non-empty array of integers, every element appears "three" times except for one, 
 * which appears exactly once. Find that single one.
 * 轉換為二進位之後檢查哪些位數的個數無法被3整除，類似題：e319 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit_cnt(32,0);
        for(unsigned int x:nums) // 為了避開負數導致無法做 shift 的問題改為 unsigned int 讀取資料
            for(int i=0;x;x>>=1,i++)
                bit_cnt[i]+=x&1;
        int ans=0;
        for(int i=0;i<bit_cnt.size();i++)
            if(bit_cnt[i]%3)
                ans|=1<<i;
        return ans;
    }
};