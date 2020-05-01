/* 前置題：ZJ-d854
 * 把給定的數字拆解成『限定的個數』和『最大的數字』兩個限制下
 * 20 4 7 → Sum=20, Cnt=4, MaxNumber=7
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
        printf("%ld\n",DP[sumN][cntN]);
    }
}