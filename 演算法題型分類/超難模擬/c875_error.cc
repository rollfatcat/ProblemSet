// 這個想法是錯誤的
/* 題目只能透過『移除罐子』
 * 從最低點開始移除左右兩側，過程中可能出現 local minimum 已經被更新過，導致左右兩邊變低，
 * 所以要判斷自己是不是比較低的一端才開始移除。
 */
#include<iostream>
using namespace std;

int h[1000000], N, U, D;
struct nn{ int h,p;
  bool operator<(const nn other)const{ return h<other.h; }
};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int updateH(int hi,int lo){
  int dis=h[hi]-h[lo], num=0;
  if(dis>D)
    num=dis-D, h[hi]-=num;
  return num;
}
int main(){

  scanInt(N), scanInt(U), scanInt(D);
  D/=U;

  vector<nn> pos;
  for(int i=0;i<N;i++)
    scanInt(h[i]), h[i]/=U;
  // local_min
  if(h[0]<h[1]) pos.push_back({h[0],0});
  for(int i=1;i<N-1;i++)
    if(h[i-1]>h[i] and h[i]<h[i+1])
      pos.push_back({h[i],i});
  if(h[N-2]>h[N-1]) pos.push_back({h[N-1],N-1});
  sort(pos.begin(),pos.end());
  long cnt=0;
  int dis, num;
  for(int i=0;i<pos.size();i++){
    // 往右更新
    for(int idx=pos[i].p+1; 0<idx and idx<N;){
      if(h[idx]>h[idx-1]) num=updateH(idx,idx-1), idx++;
      else num=updateH(idx-1,idx), idx--;

    }
    //往左更新
    for(int idx=pos[i].p-1; idx>=0 and idx<N-1;){
      if(h[idx]>h[idx+1]) num=updateH(idx,idx+1), idx--;
      else num=updateH(idx+1,idx), idx++;
      if(num>0) cnt+=num;
      else break;
    }
  }
  printf("%ld\n",cnt);
}