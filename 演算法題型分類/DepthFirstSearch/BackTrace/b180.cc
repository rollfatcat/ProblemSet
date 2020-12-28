/* 給定Ｎ組客人的抵達時間(ｔ)和遊園時間(Ｔ)，客人從抵達時間往後最多等候３０分鐘，最少需要幾輛客車才能滿足所有客人？
 * 解題關鍵：Sort + DepthFirstSearch(BackTrace) + CutBrach
 * Sort : 題目給定的客人並未依照抵達時間排序，找到最佳答案時模擬過程需要排序抵達時間。
 *        同個時間抵達的客人遊園時間小於３０分鐘，有機會只透過少量客車就滿足所有人要求＝抵達時間相同時依照遊園時間排序。
 * CutBranch : 計算時盡量從現有的車輛中挑選一台作為使用，「新增車輛」的遞迴呼叫順序放到最後。
 *             目前使用的車輛＋剩餘的客人數量＜最佳數量，才可以「新增一輛新車」遞迴處理下個客人
 * BackTrace : 維護現有使用中的客車回到園區的時間，才能確保該組客人能否選擇搭乘這個客車
 *             客人選擇某輛客車的允許條件：客車返回時間小於等於客人抵達時間＋３０分鐘
 *                客車先回來，則新的回程時間為該客人抵達時間＋遊園時間
 *                客人先抵達，則新的回程時間為該客車返回時間＋遊園時間
 *             遞迴回來時需要「恢復這輛車原本的返回時間」，所以遞迴前要把這個值複製後才能覆蓋回來。
 */ 
#include<bits/stdc++.h>
using namespace std;

const int MaxN=60;
const int Maxt=60;
const int MaxT=60;
const int BOUND=30;
int bike_back[MaxN];

struct DATA{
	int t, T;
	bool operator<(const DATA &rhs)const{ 
		return (t==rhs.t)? T>rhs.T: t>rhs.t; 
	}
} data[MaxN];
void BackTrace(int customID,int& nowCnt,int& minCnt){
	if(customID==-1){ minCnt=min(minCnt,nowCnt); return; }
	for(int i=0;i<nowCnt;i++)
		if(bike_back[i]<=data[customID].t+BOUND){
			int temp=bike_back[i];
			bike_back[i]=max(bike_back[i],data[customID].t+data[customID].T;
			BackTrace(customID-1,nowCnt,minCnt);
			bike_back[i]=temp;
		}
	if(nowCnt+customID<minCnt){
		bike_back[nowCnt++]=data[customID].t+data[customID].T;
		BackTrace(customID-1,nowCnt,minCnt);
		nowCnt--;
	}
}
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i].t,&data[i].T);
		sort(data,data+N);
		
		int nowCnt=0, minCnt=N;
		BackTrace(N-1,nowCnt,minCnt);
		printf("%d\n",minCnt);
	}
}