/*  Given a non-negative integer N, 
 * find the largest number that is less than or equal to N with monotone increasing digits.
 * an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
 * Input: N = 10     Output: 9
 * Input: N = 1234   Output: 1234
 * Input: N = 332    Output: 299
 */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int x;
        
        vector<int> digit;
        for(x=N; x>9; x/=10)
            digit.push_back(x%10);
        digit.push_back(x);
        for(x=digit.size()-1; x>0 and digit[x]<=digit[x-1]; x-=1);
        if(x==0) return N;
        
        for(int i=x-1;i>=0;i--) digit[i]=9;
        for(; x<digit.size()-1 and digit[x]==digit[x+1]; x+=1)
            digit[x]=9;
        digit[x]-=1;
        x=0;
        for(int i=digit.size()-1; i>=0; i-=1)
            x=10*x+digit[i];
        return x;
    }
};