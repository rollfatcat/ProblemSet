/* 給定２個字串，輸出最長共同子字串的長度？
 */
#include<iostream>
#include<cstring>
using namespace std;

const int MaxN=1e2+1;
char ss[2][MaxN];
int dp[MaxN][MaxN]={};
int main(){
  
  scanf("%s\n%s\n",ss[0],ss[1]);
  for(int i=0; ss[0][i]!='\0'; i++)
    for(int j=0; ss[1][j]!='\0'; j++)
      dp[i+1][j+1]= (ss[0][i]==ss[1][j])? dp[i][j]+1: max(dp[i+1][j],dp[i][j+1]);
  printf("%d\n",dp[ strlen(ss[0]) ][ strlen(ss[1] )] );
}