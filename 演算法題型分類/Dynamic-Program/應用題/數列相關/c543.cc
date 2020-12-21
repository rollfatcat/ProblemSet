#include<bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
int DP[100001][10]={{1,1,1,1,1,1,1,1,1,1}};
int main(){
  // init
  for(int len=1;len<=100000;len++)
    for(int i=0;i<=9;i++)
      for(int j=i;j<=9;j++)
        DP[len][i]=(DP[len][i]+DP[len-1][j])%MOD;
  // Main Function
  for(char ss[100002];scanf("%s",ss)!=EOF;){
    int number=0,
        len=strlen(ss),
        last=0;
    bool legal=true;
    for(last=0;last<ss[0]-'0';last++)
      number=(number+DP[len-1][last])%MOD;
    for(int i=1;i<len;i++)
      for(legal&=(ss[i-1]<=ss[i]);legal and last<ss[i]-'0';last++)
        number=(number+DP[len-1-i][last])%MOD;

    if(legal==0) number--;
    printf("%d\n",number);
  }
}
/*
      25 ->    22
    3171 ->   504
   23456 ->  1365
   54321 ->  1875
88888888 -> 24301
*/
// 715+495+120+28+6+1+1-1
// 715+495+330+210+126-1
// 11440+6435+3432+1716+792+330+120+36+1-1
// 220+165+120