#include<bits/stdc++.h>
using namespace std;

int main(){
  char ss[10];
  int N;
  vector<int> num;
  while(scanf("%s",ss)){
    if(ss[0]=='E') break; // 結束輸入
    scanf("%d",&N);
    if(ss[0]=='G'){ // GIVE：插入數字到目前數列中
      num.insert(lower_bound(num.begin(),num.end(),N),N);
    }else // FIND：查詢目前數列中第Ｋ大的數字
      printf("%d\n",num[num.size()-N]);
  }
}