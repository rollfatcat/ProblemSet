// 排列產生所有數字後，題目給兩個數字(Ｎ和Ｋ)輸出第Ｎ大和第Ｋ大的最大公因數
#include<bits/stdc++.h>
using namespace std;

int Len, ball[6]={1,2,3,4,5,6}; // i 的集合為{12,123,1234,12345,123456}
vector<int> sequence[5];
vector<bool> use(6,0);
void DFS(int now,int num){ // 利用DFS產生所有的數字
  if(now==Len){
    sequence[Len-2].push_back(num);
    return;
  }
  for(int i=0;i<Len;i++)
    if(use[i]==0)
      use[i]=1,
      DFS(now+1,(num<<3)+(num<<1)+ball[i]),
      use[i]=0;
}
int main(){
  //
  for(Len=2;Len<=6;Len++)
    DFS(0,0),
    sort(sequence[Len-2].begin(),sequence[Len-2].end());
  //
  int caseT, qL, qR;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d %d",&Len,&qL,&qR);
    for(int i=0;i<5;i++)
      if(Len==sequence[i][0]){
        Len=i; break;
      }
    printf("%d\n",__gcd(sequence[Len][qL-1],sequence[Len][qR-1]));
  }
}