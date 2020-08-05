/* 給定兩個字串Ｓ和Ｔ，輸出可否刪除Ｔ字串中的某些字元後形成Ｓ字串？
 * 正解：爬行法，枚舉Ｓ中的每個字元，維護一個指標在Ｔ中由左到右移動並找到對應字元。
 * 誤用：LCS(Ｓ,Ｔ)=Ｓ，題目給的子序列是已知，並非是求最長的共同子序列？
 */
#include<bits/stdc++.h>
using namespace std;

string subss, orgss;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    while(cin>>subss>>orgss){
        int i1=0, i2=0;
        for(;i1<subss.length() and i2<orgss.length();i1++,i2++)
            for(;i2<orgss.length() and subss[i1]!=orgss[i2];i2++);
        puts((i1==subss.length() and i2<=orgss.length())?"Yes":"No");
    }
}