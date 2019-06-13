/* 點數不多，可以枚舉三個點看能不能構成三角形(不共線)，題目保證不會出現『重合』的點
 * 排容：C(N,3)-#(共線的組合)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;
int posx[MAXN];
int posy[MAXN];
inline bool OnLine(int x1,int y1,int x2,int y2){
  if(x1==0 and x2==0) return true; // 有一個維度的向量值＝0時必定是共線
  if(y1==0 and y2==0) return true;
  return x1*y2==x2*y1; // 相乘＝
}
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d %d",&posx[i],&posy[i]);
  int ans_cnt=N*(N-1)*(N-2)/6;
  for(int i=0;i<N-2;i++)
    for(int j=i+1;j<N-1;j++){
      int vec1_x=posx[i]-posx[j],
          vec1_y=posy[i]-posy[j];
      for(int k=j+1;k<N;k++){
        int vec2_x=posx[i]-posx[k],
            vec2_y=posy[i]-posy[k];
        if(OnLine(vec1_x,vec1_y,vec2_x,vec2_y))
          ans_cnt--;
      }
    }
  printf("%d\n",ans_cnt);
}