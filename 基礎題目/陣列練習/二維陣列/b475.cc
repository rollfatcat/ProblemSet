// 只放置一個發射器，問最佳的放置地點(最大化覆蓋數量)數量和可以覆蓋的場合數量
// 1≤d≤20，1≤n≤20， 0≤x≤128, 0≤y≤128, 0<k≤1000000
/* 讀到一個點座標時，根據反推可以cover到這個點的發射器位置並累加上可覆蓋場合數量
 * 這個做法的前提是d範圍不能太大且陣列型態只需要int(單格加起來最大是20x1000000)
 */
#include<bits/stdc++.h>
using namespace std;

int cnt[129][129];
int main(){
  int R, N;
  int x, y, num, inx, iny;
  scanf("%d%d",&R,&N);
  for(int i=0;i<N;i++){
    scanf("%d%d%d",&x,&y,&num);
    for(int j=-R;j<=R;j++)
      for(int k=-R;k<=R;k++){
        inx=x+j, iny=y+k;
        if(0<=inx and inx<=128 and 0<=iny and iny<=128)
          cnt[inx][iny]+=num;
      }
  }
  int ans_sum=0, ans_cvr=0;
  for(int j=0;j<=128;j++)
    for(int k=0;k<=128;k++){
      if(cnt[j][k]>ans_cvr ) ans_cvr=cnt[j][k], ans_sum=1;
      else if(cnt[j][k]==ans_cvr) ans_sum++;
    }
  printf("%d %d\n",ans_sum,ans_cvr);
}