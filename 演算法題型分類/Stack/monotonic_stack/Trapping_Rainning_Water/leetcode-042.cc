/* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it can trap after raining.
 * 0 <= n <= 3 * 1e4, 0 <= height[i] <= 1e5
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: 
 * The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped.
 */
class Solution {
public:
    int trap(vector<int>& hgt) {
        stack<int> mts;
        int sum_area=0;
        for(int pvt=0; pvt<hgt.size(); pvt++){
            while(mts.empty()==0 and hgt[mts.top()]<=hgt[pvt]){
                int bound=mts.top(); mts.pop();
                if(mts.empty()==0)
                sum_area+=(min(hgt[pvt],hgt[mts.top()])-hgt[bound])*(pvt-mts.top()-1); 
            }
            mts.push(pvt);
        }
        return sum_area;
    }
};