/* 類似『工作排程』問題，只有當 所有需要優先於該工作完成前 的所有工作都做好才能更新
 * 這類型的題目必須避開『迴圈』，所以題目必定有保證不會發生該情況。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxS=100;
const int MaxE=100<<1;

int main(){
	for(int S,E;scanf("%d %d\n",&S,&E)!=EOF;){
		vector<int> edge[S];   // 從這個延伸出去的其他點(單向邊)
		vector<int> CntFrm(S); // 有多少的點連到這個點
		for(int fr,to;E--;)
			scanf("%d %d\n",&fr,&to),
			edge[fr].push_back(to),
			CntFrm[to]++;
		/* 初始化：起點的 CntFrm[0]=0 且 CntDpv[0]=1
         * 每次展開時 從該點延伸出去的其他點(to)需要加上從０抵達該點的方法數
         * 並檢查其他點(to)的 CntFrm[to] 是否已經可以加到 Queue 裡面作更新
         * 直到整個 Queue 都空掉。
         */
		vector<int> CntDpv(S);
		queue<int> Q;
		Q.push(0), CntDpv[0]=1;
		while(Q.empty()==0){
			int now=Q.front(); Q.pop();
			for(int to:edge[now]){
				CntDpv[to]+=CntDpv[now];
				if(--CntFrm[to]==0)
					Q.push(to);
			}
		}
		printf("%d\n",CntDpv[S-1]);
	}
}