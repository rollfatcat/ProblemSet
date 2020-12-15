/* 給定Ｎ段賽道的分數，最大化抵達終點時的分數總和？
 * 每個賽道都可以選擇要不要加速，加速後該賽道得分加倍但是無法獲得下一段賽道的分數
 * 解題關鍵：動態規劃
 * 狀態定義：現在時刻是否選擇加速，只會受到前一個時刻的選擇影響 ... 時刻ｘ選擇加速 ... 滾動陣列
 * 狀態轉移：現在選擇加速時代表前一刻只能是常速但這次獲得的分數翻倍
 *         現在選擇常速時代表 前一刻加速過且無法獲得這次分數 或是 前一刻常速但可以獲得這次分數
 * 初始狀態：分數都是０
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=40;
const int MaxP=1e2;
int dpv[2][2]; // 滾動陣列：時刻ｘ選擇加速
int main(){
  int N, P;
  while(scanf("%d",&N) and N>0){
  	dpv[0][0]=dpv[0][1]=0;
  	bool pre=1, now=0;
  	while(N-->0){
  		swap(pre,now);
  		scanf("%d",&P);
  		dpv[now][0]=max(dpv[pre][0]+P,dpv[pre][1]);
		dpv[now][1]=dpv[pre][0]+(P<<1);
  	}
  	printf("%d\n",max(dpv[now][0],dpv[now][1]));
  }
}