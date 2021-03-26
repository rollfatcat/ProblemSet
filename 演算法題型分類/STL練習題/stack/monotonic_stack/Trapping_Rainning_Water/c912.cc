/* 給定字串代表路面的坑洞線，下雨後會在低窪處(高度不為０的部分)積水，輸出積水的面積？
 * 高度為０的地方會因為和下水道相連而讓積水流失。
 * 解題關鍵：monotonic stack(單調棧)
 * 低窪＝根據目前高度往左/右找到第一個大於目前高度的 bar
 * 需要額外處理『與下水道相連的低窪處』(高度為０) -> 清空 stack -> 讓位於高度為０的 bar 左側部分不存在
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=1e4;
char ss[MaxL+2];
vector<int> hgt;
 
int main(){
	// string to histogram
	scanf("%s",ss);
	for(int i=0, nowH=0; ss[i]!='\0'; i++)
		if(ss[i]=='H')
			hgt.push_back(nowH);
		else if(ss[i]=='U')
			nowH+=1;
		else if(ss[i]=='D')
			nowH-=1;
	// monotonic stack
	int ansArea=0;
	stack<int> mts;
	for(int pvt=0; pvt<hgt.size(); pvt++){
		// 無法形成積水＝清空 stack
		if(hgt[pvt]==0){
			while(mts.empty()==0)
				mts.pop();
			continue;
		}
		// 低窪＝左右高於目前的高度
		while(mts.empty()==0 and hgt[mts.top()]<=hgt[pvt]){
			int base=hgt[mts.top()]; mts.pop();
			if(mts.empty()==0) // 需要存在左側邊界才能形成「低窪」
				ansArea+=(min(hgt[pvt],hgt[mts.top()])-base)*(pvt-mts.top()-1);
		}
		mts.push(pvt);
	}
	printf("%d\n",ansArea);
}