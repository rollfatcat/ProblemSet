/* Given a circular array (the next element of the last element is the first element of the array),
 * print the Next Greater Number for every element. 
 * The Next Greater Number of a number x is the first greater number to its traversing-order next 
 * in the array, which means you could search circularly to find its next greater number. 
 * If it doesn't exist, output -1 for this number.
 */
class Solution {
private:
    const int MaxN=1e4;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> table(nums.size(),-1);
        stack<int> mts;
        for(int now=0; now<nums.size(); now++){
            for(; mts.empty()==0 and nums[mts.top()]<nums[now]; mts.pop())
                table[mts.top()]=nums[now];
            mts.push(now);
        }
        for(int now=0; now<nums.size(); now++){
            for(; mts.empty()==0 and nums[mts.top()]<nums[now]; mts.pop())
                table[mts.top()]=nums[now];
            mts.push(now);
        }
        
        return table;
    }
};