/* 偏難的動態規劃題目( 不知需要紀錄的規則和狀態轉移的方式 )
 * 標準動態規劃題型( 觀察題目給予的方法數可知：方法數一定是算出來的且需要用long去紀錄 )
 * 解法可以視為ZJ-c188的加強版(因為有規定能使用的最大數字)，換句話說，若沒有『限制』時這題可以視為ZJ-c188。
 * 需要紀錄的狀態：DP[總和][分解的個數]＝方法數，至於『限制使用的最大數字』則在最外層用一個迴圈限制
 */
#include<bits/stdc++.h>
using namespace std;

const int MAX_sum=501;
const int MAX_cnt=51;
const int MAX_num=101;
int main(){
    
    int caseT;
    int sumN, cntN, maxN;
    scanf("%d\n",&caseT);
    while(caseT--){
        scanf("%d %d %d",&sumN,&cntN,&maxN);
        long DP[MAX_sum][MAX_cnt]={{1}}; // DP[0][0]=1
        for(int i=1;i<=maxN;i++)
            for(int j=i;j<=sumN;j++)
                for(int k=1;k<=cntN;k++)
                    DP[j][k]+=DP[j-i][k-1];
        for(int j=1;j<=sumN;j++,puts("")){
            printf("%2d :",j);
            for(int k=1;k<=cntN;k++)
                printf("%ld ",DP[j][k]);
        }
        
        printf("%ld\n",DP[sumN][cntN]);
    }
}