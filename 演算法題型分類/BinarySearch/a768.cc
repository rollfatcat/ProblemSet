// 題目給定3000個邊長(長度不會有重複，邊長不會超過2^30)，問可以形成『直角三角形』的組合數量
// 解題：枚舉直角三角形的相互垂直的兩個邊，算出第三邊，若第三邊是整數(題目保證輸入是整數)
// 才再二分搜尋法是否存在數列中 = 3000x3000x__lg(3000) = 1e8
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3001;
int main(){
  int N;
  long len[MAXN];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%ld",&len[i]);
  sort(len,len+N);
  int ans_cnt=0;
  for(int i=0;i<N-1;i++)
    for(int j=i+1;j<N;j++){
      long side_2=len[i]*len[i]+len[j]*len[j],
           side_1=sqrt(side_2);
      if(side_1*side_1==side_2){
        int tag=lower_bound(len+j,len+N,side_1)-len;
        if(len[tag]==side_1)
          ans_cnt++;
      }
    }
  printf("%d\n",ans_cnt);
}