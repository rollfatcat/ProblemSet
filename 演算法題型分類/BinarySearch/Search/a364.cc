/* 給定Ｎ，需要依照題目的規定的進位制從十位數作轉換，輸出三個係數值(ａ>ｂ>ｃ≧０)？
 * 進位制規則：Ｎ＝Ｃ(ａ,３)+Ｃ(ｂ,２)+Ｃ(ｃ,１)，且 Ｃ(ｍ,ｎ)=０,if ｍ<ｎ
 * 解題關鍵：二分搜尋法STL
 * Ｎ ≧ Ｃ(ａ,３), 最大化ａ 並且 Ｎ-Ｃ(ａ,３) ≧ Ｃ(ｂ,２), 最大化ｂ
 * 進位制轉換時依序從最大項數的係數開始扣除，Ｃ(ｍ,ｎ)時ｎ＝3,2,1。
 * 觀察當Ｎ=０時輸出的答案是210，可以知道要找到的ｍ算出的Ｃ(ｍ,ｎ)≦ Ｎ。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=10;
const int MaxN=5e2;
int main(){

  /* 根據CM3定義：Ｃ(0,3)=Ｃ(1,3)=Ｃ(2,3)=0  
   * 根據CM2定義：Ｃ(0,2)=Ｃ(1,2)=0  
   * 題目保證Ｎ≦ 500，計算出所有的項數值在範圍內的。
   */
  vector<int> CM3={0,0,0};
	vector<int> CM2={0,0};
  for(int i=3;CM3.back()<=MaxN;i++) 
		CM3.push_back(i*(i-1)*(i-2)/6);
	for(int i=2;CM2.back()<=MaxN;i++) 
		CM2.push_back(i*(i-1)>>1);
	
	int Q, N, c3, c2;
	scanf("%d\n",&Q);
	while(Q-->0){
		scanf("%d\n",&N);
		c3=upper_bound(CM3.begin(),CM3.end(),N)-CM3.begin();
		c2=upper_bound(CM2.begin(),CM2.end(),N-CM3[c3-1])-CM2.begin()-1;
		printf("%d%d%d\n",c3,c2,N-CM3[c3-1]-CM2[c2]);
	}
}