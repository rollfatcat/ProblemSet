/* You are given two integer arrays nums1 and nums2 both of unique elements, 
 * where nums1 is a subset of nums2.
 * Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
 * If it does not exist, return -1 for this number.
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> table;
        stack<int> mts;
        for(int now=0; now<nums2.size(); now++){
            while(mts.empty()==0 and nums2[mts.top()]<nums2[now]){
                table[nums2[mts.top()]]=nums2[now];
                mts.pop();
            }
            mts.push(now);
        }
        vector<int> ans;
        for(int x:nums1)
            ans.push_back( (table.find(x)==table.end())? -1: table[x] );
        return ans;
    }
};