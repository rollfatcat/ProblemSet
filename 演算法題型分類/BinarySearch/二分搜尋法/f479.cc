/* 給定第Ｎ天時第Ｋ個位置，輸出該位置出現的字元，若Ｋ超過第Ｎ天字串長度時輸出"#"。
 * 第１天時字串為"A"，之後每過一天會以「質數」方式成長，字串為"ABC"循環出現
 * 解題關鍵：建質數表＋前綴和＋二分搜尋法
 * Ｎ ≦ 10000 ... 需要找到 10000th 質數，根據質數特性只要由小到大枚舉且不會被根號範圍內的質數整除就能加入質數表
 * 根據Ｋ做二分搜尋法確認Ｋ落在哪一段質數長度，再依據３個一循環推斷字元。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxQ=1e4;
const int MaxN=1e4+1;
const int MaxK=1e9;
 
vector<int> prm={1,2,3, 5, 7,11}; // 10000th prime is 104729
vector<int> prS={1,3,6,11,18,29};
 
int main(){
	/* prime tabulation */
    for(int now=13; prm.size()<MaxN; now+=2){
		bool IsP=true;
		for(int i=2; prm[i]*prm[i]<=now and IsP; i++)
			IsP= (now%prm[i])>0;
		if(IsP) 
			prm.push_back(now),
			prS.push_back(prS.back()+now);
	}
	char ss[3]={'A','B','C'};
	int N, K;
	while(scanf("%d %d\n",&N,&K)!=EOF){
		if(prS[N-1]<K){ puts("#"); continue; }
		int tag=lower_bound(prS.begin(),prS.end(),K)-prS.begin();
		putchar( ss[(K-prS[tag-1]-1)%3] );
		putchar('\n');
	}
}