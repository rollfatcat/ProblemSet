/* 給定Ｎ個人，每個人都會有自己的敵人清單(ｐ個敵人)，輸出最多可以邀請的朋友個數？
 * 關係遞推：敵人的敵人＝朋友，敵人的朋友＝敵人。
 * 解題關鍵：DSU＋LazyEvalute
 * 題目盲點：某個 Component 發生矛盾才該 Componet 不需計算但不代表整個 forst 不須計算
 *         矛盾只會影響這個 Component 同一群的成員和屬於該群假想敵所在的成員
 */

#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=200;
int  root[MaxN<<1|1];
int  size[MaxN<<1|1];
bool conf[MaxN<<1|1];
 
int FindRoot(int x){ return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
 
int main(){
	int caseT, N, p, u, v;
 
	scanf("%d\n",&caseT);
	while(caseT-->0){
		for(int u=1;u<=(MaxN<<1);u++)
			root[u]=u, conf[u]=size[u]=0;
 
		scanf("%d\n",&N);
		for(int u=1;u<=N;u++){
			scanf("%d",&p);
			while(p-->0){
				scanf("%d",&v);
                // 成員編號超過Ｎ時就無視
				if(v>N) continue;
				int Ru=FindRoot(u);
				int Rv=FindRoot(v);
				int Eu=FindRoot(u+N);
				int Ev=FindRoot(v+N);
				if(Ru==Rv)
					conf[Ru]=conf[Rv]=true,
					conf[Eu]=conf[Ev]=true;
				else{ /* 假想敵的編號一定會超過Ｎ，所以合併時以編號較小者為主，方便檢查 */
					(Eu>Rv)? root[Eu]=Rv: root[Rv]=Eu;
					(Ev>Ru)? root[Ev]=Ru: root[Ru]=Ev;
				}
			}
		}
 
		int ans=0;
        // 當 這個群的代表 和 該群代表的假想敵 都不出現矛盾時才需要計算
		for(int u=1;u<=N;u++){
			int Eu=FindRoot(u);
			int Ru=FindRoot(Eu+N);
			size[Eu]+= (conf[Eu]==0 and conf[Ru]==0);
		}
		for(int u=1;u<=N;u++)
			if(root[u]==u){
				int Eu=FindRoot(u+N);
				ans+= max(size[u],size[Eu]);
				root[Eu]=u;
			}
		printf("%d\n",ans);
	}
}