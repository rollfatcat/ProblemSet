/* 題目：石像必須先依照高度，再依照重量由小到大排序，目標是『最小化』搬動石像的次數。
 * 為了最小化搬動次數必須維護『輸入次序』(當高度和重量相等時就比較輸入時的順序)
 * 最後依照完成排序後的順序和原先的次序取差值的總和即可。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4;
struct ITEM{
  int w,h,o;
  bool operator<(const ITEM &rhs)const{
    if(h!=rhs.h) return h<rhs.h;
    if(w!=rhs.w) return w<rhs.w;
    return o<rhs.o;
  }
} org[MAXN];


int main(){
  int N;
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d %d",&org[i].h,&org[i].w),
      org[i].o=i;
    sort(org,org+N);
    int sum=0, x;
    for(int i=0;i<N;i++)
      x=org[i].o-i,
      sum+=(x<0)?-x:x;
    printf("%d\n",sum);
  }
}
