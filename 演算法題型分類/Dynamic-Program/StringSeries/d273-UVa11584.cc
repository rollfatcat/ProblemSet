#include<bits/stdc++.h>
using namespace std;
#define MaxN 1001

char ss[1002];
inline bool isPalindrome(int l, int r){
  for(; l<r ; l++, r--)
    if(ss[l]!=ss[r])
      return false;
  return true;
}

int main(){
  int caseNum, DP[MaxN]={0};

  scanf("%d",&caseNum);
  while(caseNum--){
    scanf("%s",ss+1);
    // 窮舉每一個字元的位置當作現在判斷字串的最尾端
    int L;
    for(L=1;ss[L]!='\0';L++){
      DP[L]=L;
      for(int i=1;i<=L;i++) // 枚舉每一個字元的位置當作現在判斷字串的開頭
        if(isPalindrome(i,L)) // 測試看看該字串能不能構成『迴文』
          DP[L]=min(DP[L],DP[i-1]+1);
    }
    printf("%d\n",DP[L-1]);
  }
}