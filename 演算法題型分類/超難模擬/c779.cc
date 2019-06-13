// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4211763
/* 想法同 c875 那題是要移除讓相鄰高度差在合理範圍，而這題是墊高
 * (X) 找到所有 local_minimum 排序後從最低點朝左右更新，直到範圍內都合法
 *     上述的想法可以通過 c875 測資但是這題只能通過 90%
 * (O) 找到 global maximum 往左右更新到底
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int h[30], N, D;
struct nn{ int h,p;
  bool operator<(const nn other)const{ return h>other.h; }
};
inline char scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c;}
int main(){

  for(N=0;scanInt(h[N++])==' ';);
  scanInt(D);
  // 找到最高點往左右更新到底
  int maxh=h[0], pos=0;
  for(int i=1;i<N;i++)
    if(h[i]>maxh)
      maxh=h[i], pos=i;
  int cnt=0, dis, num;
  // 往右更新到底
  for(int idx=pos+1; 0<idx and idx<N;){
    if(h[idx]-h[idx-1]>D) //右側比自己高，讓自己墊高，往後退一步確認自己和左側仍落於合法範圍
      num=h[idx]-h[idx-1]-D, h[idx-1]=h[idx]-D, cnt+=num, idx--;
    else if(h[idx-1]-h[idx]>D) // 右側比自己低，讓右側墊高，繼續往右邊更新
      num=h[idx-1]-h[idx]-D, h[idx]=h[idx-1]-D, cnt+=num, idx++;
    else // 高度差都落在合法範圍，繼續往下更新
      idx++;
  }
  // 往左更新到底
  for(int idx=pos-1; idx>=0 and idx<N-1;){
    if(h[idx]-h[idx+1]>D) //左側比自己高，讓自己墊高，往後退一步確認自己和右側仍落於合法範圍
      num=h[idx]-h[idx+1]-D, h[idx+1]=h[idx]-D, cnt+=num, idx++;
    else if(h[idx+1]-h[idx]>D) //左側比自己低，讓左側墊高，繼續往左邊更新
      num=h[idx+1]-h[idx]-D, h[idx]=h[idx+1]-D, cnt+=num, idx--;
    else // 高度差都落在合法範圍，繼續往下更新
      idx--;
  }
  printf("%d\n",cnt);
}
