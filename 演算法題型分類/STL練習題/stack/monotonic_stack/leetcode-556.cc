/* Given a positive integer n, 
 * find the smallest integer which has exactly the same digits existing 
 * in the integer n and is greater in value than n. If no such positive integer exists, return -1.
 * Note that the returned integer should fit in 32-bit integer, 
 * if there is a valid answer but it does not fit in 32-bit integer, return -1.
 */
class Solution {
public:
    int nextGreaterElement(int n){
        
        vector<int> digit;
        for(int x=n; x>0; x/=10)
            digit.push_back(x%10);
        int ths=1, rhs=0;
        for(;ths<digit.size() and digit[ths-1]<=digit[ths]; ths++);
        if(ths==digit.size()) 
            return -1;
        for(; digit[rhs]<=digit[ths]; rhs++);
        swap(digit[ths],digit[rhs]);
        sort(digit.begin(),digit.begin()+ths,greater<int>());
        
        long long out=0;
        for(int i=digit.size()-1; i>=0; i--)
            out=10*out+digit[i];
        return (out>INT_MAX)? -1: out;
        
    }
};