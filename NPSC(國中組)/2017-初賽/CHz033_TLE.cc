// 暴力法枚舉(起點,終點)當區間內的數字個數都是偶數時，總次數+1

#include<iostream>
using namespace std;
#define MAXN 1000001

int num[MAXN], Odd[2], Even[2];
int cnt[2][MAXN];
int main(){
  int N, pre, now;
  long long ans=0;
  scanf("%d",&N);
  Even[0]=Even[1]=N;
  // 初始化
  scanf("%d",&num[0]);
  Even[0]--, Odd[0]++;
  cnt[0][num[0]]++;
  for(int i=1;i<N;i++){
    scanf("%d",&num[i]);
    now=i&1, pre=now^1;

    cnt[pre][ num[i] ]++;
    (cnt[pre][ num[i] ]&1)?(Even[pre]--,Odd[pre]++):(Even[pre]++,Odd[pre]--);
    if(Odd[pre]==0) ans++;

    for(int j=0;j<i;j++){
      cnt[pre][ num[j] ]--;
      (cnt[pre][ num[j] ]&1)?(Even[pre]--,Odd[pre]++):(Even[pre]++,Odd[pre]--);
      if(Odd[pre]==0) ans++;

      cnt[now][ num[j] ]++;
      (cnt[now][ num[j] ]&1)?(Even[now]--,Odd[now]++):(Even[now]++,Odd[now]--);
    }
    cnt[pre][ num[i] ]--;
    (cnt[pre][ num[i] ]&1)?(Even[pre]--,Odd[pre]++):(Even[pre]++,Odd[pre]--);
    cnt[now][ num[i] ]++;
    (cnt[now][ num[i] ]&1)?(Even[now]--,Odd[now]++):(Even[now]++,Odd[now]--);

  }
  printf("%lld\n",ans);
}