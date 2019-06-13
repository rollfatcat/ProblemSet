// 堪根定理實作：連續整數之間和X軸的交點
#include<iostream>
#include<cmath>
using namespace std;

int coff[6];
inline long get_func(long x){return coff[5]*x*x*x*x*x+coff[4]*x*x*x*x+coff[3]*x*x*x+coff[2]*x*x+coff[1]*x+coff[0];}
int main(){
  while(cin>>coff[5]){
    int zeroCnt=(coff[5]==0);
    for(int i=4;i>=0;i--)
      cin>>coff[i], zeroCnt+=(coff[i]==0);
    if(zeroCnt==6){ puts("Too many... = =\""); continue; }
    /* -2147483647 ≦ x^6 ≦ 2147483647
     * 因此，我們可以推出Ｘ的範圍介於，-35.9 ≦ Ｘ ≦ 35.9。
     * 所以從 -36 代值到函數裡，直到 x=36 為止，這樣就可以跑遍所有可能的範圍了。
     */
    int rootCnt=0, idx=-36;
    long pre_v, now_v;
    while(idx<=36 and (now_v=get_func(idx))==0)
      printf("%d %d\n",idx,idx), idx++, rootCnt++;
    for(idx++,pre_v=now_v;idx<=36;idx++){
      now_v=get_func(idx);
      if(now_v==0)  printf("%d %d\n",idx,idx), rootCnt++;
      else if((pre_v<0 and now_v>0) or (pre_v>0 and now_v<0)) printf("%d %d\n",idx-1,idx), rootCnt++;
      pre_v=now_v;
    }
    if(rootCnt==0) puts("N0THING! >\\\\\\<");
  }
}