// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4211763
/* 找到 global minimum 往左右更新到底
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int h[1000000], N, U, D;
struct nn{ int h,p;
  bool operator<(const nn other)const{ return h<other.h; }
};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}

int main(){
  scanInt(N),
  scanInt(U),
  scanInt(D);
  D/=U;
  for(int i=0;i<N;i++)
    scanInt(h[i]), h[i]/=U;
  // global_minimum
  int minH=h[0], pos=0;
  for(int i=1;i<N;i++)
    if(minH>h[i])
      minH=h[i], pos=i;
  long cnt=0;
  int dis, num;
  for(int idx=pos+1; 0<idx and idx<N;){
    if(h[idx]-h[idx-1]>D) // 右側比自己高，移除右側罐子，繼續往右邊更新
      num=h[idx]-h[idx-1]-D, h[idx]=h[idx-1]+D, cnt+=num, idx++;
    else if(h[idx-1]-h[idx]>D) // 右側比自己低，移除自己罐子，往後退一步確認自己和左側仍落於合法範圍
      num=h[idx-1]-h[idx]-D, h[idx-1]=h[idx]+D, cnt+=num, idx--;
    else // 高度差都落在合法範圍，繼續往右更新
      idx++;
  }
  // 往左更新到底
  for(int idx=pos-1; idx>=0 and idx<N-1;){
    if(h[idx]-h[idx+1]>D) //左側比自己高，移除左側罐子，繼續往左邊更新
      num=h[idx]-h[idx+1]-D, h[idx]=h[idx+1]+D, cnt+=num, idx--;
    else if(h[idx+1]-h[idx]>D) //左側比自己低，移除自己罐子，往後退一步確認自己和右側仍落於合法範圍
      num=h[idx+1]-h[idx]-D, h[idx+1]=h[idx]+D, cnt+=num, idx++;
    else // 高度差都落在合法範圍，繼續往下更新
      idx--;
  }
  printf("%ld\n",cnt);
}