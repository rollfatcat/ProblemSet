/* 有Ｎ位市民(編號０到Ｎ-1)，市民必定屬於２個敵對的城市其一，給定數段關係輸出對應操作？
 *   １ Ａ Ｂ：設定ＡＢ為「友好關係」，若ＡＢ已是「敵對關係」輸出"-1"且此次操作無效。
 *   ２ Ａ Ｂ：設定ＡＢ為「敵對關係」，若ＡＢ已是「友好關係」輸出"-1"且此次操作無效。
 *   ３ Ａ Ｂ：查詢ＡＢ是否「友好關係」
 *   ４ Ａ Ｂ：查詢ＡＢ是否「敵對關係」
 * 關係遞推：
 *      Relation is mutual( symmetric and irreflexive ).
 *      IsFriend(Ａ,Ｂ) and IsFriend(Ｂ,Ｃ) so IsFriend(Ａ,Ｃ)
 *       IsEnemy(Ａ,Ｂ) and  IsEnemy(Ｂ,Ｃ) so IsFriend(Ａ,Ｃ) ... An enemy of a friend is an enemy.
 * 解題關鍵： DisjointSetUnion twist
 *      預設 敵對群體編號＝自己編號＋Ｎ
 * 		每個市民有兩個狀態：紀錄自己的友好群體編號 和 敵對群體編號
 *      設定關係 或是 確認關係時需要雙向確認(同屬相同友好群體 或是 擁有共同敵人)，其一符合即可。
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e4;
int N, root[MaxN<<1];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
 
int main(){
	int opt, A, B;
 
	while(scanf("%d\n",&N)!=EOF){
		/* 初始化：第ｉ位成員都是自己群體的代表且第ｉ位成員的敵對關係(第ｉ+Ｎ格)記錄為 ｉ+Ｎ */
        for(int i=0;i<(N<<1);i++)
			root[i]=i;
		while(scanf("%d %d %d\n",&opt,&A,&B)!=EOF and opt>0){
			/* Ａ的根節點 和 Ａ+Ｎ(Ａ的敵對)的根節點
             * Ｂ的根節點 和 Ｂ+Ｎ(Ｂ的敵對)的根節點
             * 設定關係 或是 確認關係時需要雙向確認其一符合即可。
             */
            int root_A=FindRoot(A);
			int root_B=FindRoot(B);
			int root_eA=FindRoot(A+N);
			int root_eB=FindRoot(B+N);
			switch(opt){
				case 1: // SetFriend(A,B)
					if(root_A==root_eB or root_B==root_eA)
						puts("-1");
					else if(root_A==root_B or root_eA==root_eB)
						continue;
					else
						root[root_B]=root_A,
						root[root_eB]=root_eA;
					break;
				case 2: // SetEnemy (A,B) 
					if(root_A==root_eB or root_B==root_eA)
						continue;
					else if(root_A==root_B or root_eA==root_eB)
						puts("-1");
					else
						root[root_eB]=root_A,
						root[root_eA]=root_B;
					break;
				case 3: // Check relation of Friend
					puts((root_A==root_B or root_eA==root_eB)? "1": "0");
					break;
				case 4: // Check relation of Enemy
					puts((root_A==root_eB or root_B==root_eA)? "1": "0");
					break;
			}
 
		}
	}
}
