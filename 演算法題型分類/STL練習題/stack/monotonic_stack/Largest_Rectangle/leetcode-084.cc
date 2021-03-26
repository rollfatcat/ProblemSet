/* Given an array of integers heights representing the histogram's bar height 
 * where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 * 1 <= heights.length <= 1e5, 0 <= heights[i] <= 1e4
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans_area=0;
        int pvt=0;
        stack<int> mts;
        for(; pvt<heights.size(); pvt++){
            while(mts.empty()==0 and heights[mts.top()]>=heights[pvt]){
                int nowH=heights[mts.top()];
                mts.pop();
                ans_area=max(ans_area, (mts.empty())? nowH*pvt: nowH*(pvt-mts.top()-1) );
            }
            mts.push(pvt);
        }
        
        while(mts.empty()==0){
            int nowH=heights[mts.top()];
            mts.pop();
            ans_area=max(ans_area, (mts.empty())? nowH*pvt: nowH*(pvt-mts.top()-1) );
        }
        
        return ans_area;
        
    }
};