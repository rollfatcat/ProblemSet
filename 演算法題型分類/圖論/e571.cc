/* 給定Ｎ個中文詞彙，在「接龍」的規則下輸出最長的接龍長度和可以構成該長度的所有起點詞彙？
 * 接龍：詞彙Ａ可以接在詞彙Ｂ前面：Ａ的最後一個中文字＝Ｂ的第一個字
 * 解題關鍵：UTF-8＋圖論(Cached Recursive)
 * UTF-8：比對中文字時需要以３個字元為單位 
 * 圖論(Cached Recursive)：
 *      有向邊建立：枚舉任選兩個詞彙，依據接龍規則判斷ＡtoＢ的邊
 *      Cached Recursive：枚舉每個詞彙作為起點，紀錄當目前的點可以走出去的最長距離(避免繞圓同時紀錄節點是否拜訪過)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=100;
const int MaxOneL=30;
char org_ss[MaxN][MaxOneL+2];
int orgLen[MaxN];
vector<int> to[MaxN];
inline bool IsConnect(int a,int b){
	return org_ss[a][orgLen[a]-3]==org_ss[b][0] and org_ss[a][orgLen[a]-2]==org_ss[b][1] and org_ss[a][orgLen[a]-1]==org_ss[b][2];
}
int N, ansLen;
int vis[MaxN];
int maxPath[MaxN];
int FindMaxPath(int now){
	if(vis[now]==0){
		vis[now]=1;
		for(int nxt:to[now])
			maxPath[now]=max(maxPath[now],FindMaxPath(nxt));
		maxPath[now]++;
	}
	return maxPath[now];
}
int main(){
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%s\n",org_ss[i]);
			orgLen[i]=strlen(org_ss[i]);
			to[i].clear();
		}
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++){
				if(IsConnect(i,j)) to[i].push_back(j);
				if(IsConnect(j,i)) to[j].push_back(i);
			}
		vector<int> memo;
		ansLen=1;
		for(int st=0; st<N; st++){
			fill(maxPath,maxPath+N,0);
			fill(vis,vis+N,0);
			if(ansLen<FindMaxPath(st))
				ansLen=maxPath[st], memo.clear();
			if(ansLen==maxPath[st])
				memo.push_back(st);
		}
		printf("%d\n",ansLen);
		if(ansLen==1) 
			puts("什麼爛表");
		else{
			for(int x:memo)
				printf("%s ",org_ss[x]);
			putchar('\n');
		}
	}
}