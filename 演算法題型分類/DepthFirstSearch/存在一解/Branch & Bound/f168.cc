/* 給定Ｎ件物品的價值，輸出是否能將所有物品價值均分成３份？
 * 每件物品的價值最高是1e7，但物品最多16件。
 * 解題核心：Recursive+BranchCut，類似 d375-UVa10364，如何快速收斂找到答案？
 * 盲點：遞迴時枚舉每件物品『選或不選』依序挑滿２組均值的方式(第３組不需挑選因為未被挑到的物品價值和必定是均值)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=16;
const int MaxV=1e7;
int N, sumv, avg; 
int item[MaxN];

bool compare(int a,int b){ return a>b; }
bool DFS(int a,int b,int c,int idx){
	/* 最後一件物品時，最大餘量必須符合該物品的價值 */
    if(idx==N-1) return a==item[idx];
	/* 若目前最大餘量也無法滿足第 idx 件物品代表分配錯誤 */
    if(item[idx]>a) return false;
	/* 第 idx 件物品分配給第ａ堆，遞迴時維護大到小的三堆餘量 */
	if(a-item[idx]<c){ 
		if(DFS(b,c,a-item[idx],idx+1)) 
			return true; 
	}else if(a-item[idx]<b){ 
		if(DFS(b,a-item[idx],c,idx+1)) 
			return true; 
	}else{
		if(DFS(a-item[idx],b,c,idx+1)) 
			return true;
	}
	/* 第 idx 件物品分配給第ｂ堆，遞迴時維護大到小的三堆餘量 */
	if(b>=item[idx]){
		if(b-item[idx]< c and DFS(a,c,b-item[idx],idx+1)) return true;
		if(b-item[idx]>=c and DFS(a,b-item[idx],c,idx+1)) return true;
	}
	/* 第 idx 件物品分配給第ｃ堆，遞迴時維護大到小的三堆餘量 */
	if(c>=item[idx] and DFS(a,b,c-item[idx],idx+1)) return true;
	/* 若上述都沒有 return true 則預設 return false 代表不存在一組解 */
	return false;
}
int main(){
	while(scanf("%d\n",&N)!=EOF){
		sumv=0;
		for(int i=0;i<N;i++)
			scanf("%d",&item[i]), 
			sumv+=item[i];
		avg=sumv/3;
		sort(item,item+N,compare);
		/* 以下兩者情況不需做遞迴即能知道無法均分：
		 * (1)總價值對３取餘數不為０ 
		 * (2)價值最高的物品超過平均價值
		 */
		if(sumv%3 or item[0]>avg){ puts("NO"); continue; }
		/* 遞迴時枚舉每件物品，並記錄三堆價值的餘量(由大到小)
		 * 基於均分的要求，每件物品必定得分配給三堆其中的某一堆(若餘量能大於等於該物品的價值時)
		 * 快速收斂：先將物品價值由大到小排序，每次遞迴時優先把物品分配給餘量最大的那一堆
		 */
		(DFS(avg,avg,avg-item[0],1))? puts("YES"): puts("NO");
	}
}