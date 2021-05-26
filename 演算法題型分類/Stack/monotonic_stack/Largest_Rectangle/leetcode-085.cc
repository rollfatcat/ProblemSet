/* Given a rows x cols binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing only 1's and return its area.
 * 0 <= row, cols <= 200, matrix[i][j] is '0' or '1'.
 * Input: matrix = [["1","0","1","0","0"],
                    ["1","0","1","1","1"],
                    ["1","1","1","1","1"],
                    ["1","0","0","1","0"]]
 * Output: 6
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) 
            return 0;
        
        int R=matrix.size();
        int C=matrix[0].size();
        vector<vector<int>> cot_one(R,vector<int>(C));
        
        for(int c=0; c<C; c++)
            cot_one[0][c]= matrix[0][c]=='1';
        for(int r=1;r<R;r++)
            for(int c=0; c<C; c++)
                if(matrix[r][c]=='1')
                    cot_one[r][c]=cot_one[r-1][c]+1;
        
        int maxArea=0; 
        for(int r=0;r<R;r++){
            stack<int> mts;
            for(int c=0;c<C;c++){
                while(mts.empty()==0 and cot_one[r][mts.top()]>cot_one[r][c]){
                    int H=cot_one[r][mts.top()];
                    mts.pop();
                    maxArea=max(maxArea,(mts.empty())? H*c: H*(c-mts.top()-1));
                }
                mts.push(c);
            }
            
            while(mts.empty()==0){
                int H=cot_one[r][mts.top()];
                mts.pop();
                maxArea=max(maxArea,(mts.empty())? H*C: H*(C-mts.top()-1));
            }
        }
        return maxArea;
    }       
};