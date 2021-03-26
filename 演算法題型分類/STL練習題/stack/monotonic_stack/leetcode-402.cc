/* Given a non-negative integer num represented as a string, 
 * remove k digits from the number so that the new number is the smallest possible.
 * Note: The length of num is less than 10002 and will be ≥ k.
 *       The given num does not contain any leading zero.
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2.
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        for(int pvt=0; num[pvt]!='\0'; pvt++){
            while(res.empty()==0 and res.back()>num[pvt] and k>0){
                res.pop_back(); 
                k-=1;
            }
            res.push_back(num[pvt]);
        }
        for(; k>0; k-=1)
            res.pop_back();
        int zero_idx=0;
        for(; res[zero_idx]=='0'; zero_idx+=1);
        
        return (res=="" or zero_idx==res.length())? "0": res.substr(zero_idx); 
    }
};