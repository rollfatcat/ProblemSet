/* 給定數個指令移動積木，輸出最後每堆積木的內容？
 * 指令類型(若ＡＢ位於同一堆則該指令作廢)：
 *    move A onto B : 移除積木Ａ上面的其他積木＋移除積木Ｂ上面的其他積木＋單獨將積木Ａ搬到積木Ｂ所在的 Stack
 *    move A over B : 移除積木Ａ上面的其他積木＋單獨將積木Ａ搬到積木Ｂ所在的 Stack 最上面。
 *    pile A onto B : 移除積木Ｂ上面的其他積木＋將積木Ａ以及他上方的其他積木移動到 積木Ｂ的上方。
 *    pile A over B : 將積木Ａ以及他上方的其他積木移動到積木Ｂ的上方(注意這邊是整疊移動不是Stack一個個Push)
 * 解題關鍵：Stack＋簡單模擬(考慮哪些狀態需要紀錄)：群(查並集的群)
 * 問題盲點：積木Ａ和積木Ｂ不一定會待在自己的 Stack 。
 * 模擬過程中需要紀錄的狀態：
 *    積木Ａ和積木Ｂ不一定會待在自己的 Stack ＝紀錄積木屬於哪一個 Stack
 *    pile 連帶該積木正方的其他積木一起移動  ＝除了紀錄積木屬於哪一個 Stack 還需要紀錄位於這個 Stack 的位置
 *    每個 Stack 內堆疊的積木和該 Stack 的長度，因為堆疊新的積木時是從後方放入。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=25;
int where[MaxN];
int Inpos[MaxN];
int Stack[MaxN][MaxN];
int Ssize[MaxN];
char opt[2][5];

/* 移除積木Ｘ上方的其他積木＝積木Ｘ所在的堆疊和該堆疊所在的位置 
 * 移除＝將其他積木放回他們所屬編號的堆疊上方
 * 移除積木Ｘ上方的其他積木後更新積木Ｘ所在的堆疊長度
 */
inline void ClearUp(int now_pile,int now_pos){
	for(int i=now_pos+1; i<Ssize[now_pile]; i++){
		int now_block=Stack[now_pile][i];
		where[now_block]=now_block;
		Inpos[now_block]=Ssize[now_block];
		Stack[now_block][ Ssize[now_block]++ ]=now_block;
	}
	Ssize[now_pile]=now_pos+1;
}
/* 將積木Ｘ上方的其他積木一起搬動到積木Ｙ所在的堆疊上方＝積木Ｘ所在的堆疊和該堆疊所在的位置和積木Ｙ所在的堆疊
 * 更新將積木Ｘ上方的積木(包含積木Ｘ)的狀態：屬於哪個堆疊，位於該堆疊的位置，積木Ｙ所在堆疊的內容和長度
 * 移除後積木Ｘ所在的堆疊長度下降
 */
inline void MoveTo(int pile_A,int pos_A,int pile_B){
	for(int i=pos_A; i<Ssize[pile_A]; i++){
		int now_block=Stack[pile_A][i];
		where[now_block]=pile_B;
		Inpos[now_block]=Ssize[pile_B];
		Stack[pile_B][ Ssize[pile_B]++ ]=now_block;
	}
	Ssize[pile_A]=pos_A;
}
 
int main(){
	int N, A, B;
	while(scanf("%d",&N)!=EOF){
		/* 初始化 */
    for(int i=0;i<N;i++)
			Stack[i][0]=where[i]=i, 
			Ssize[i]=1, Inpos[i]=0;
    /* 依據指令移動積木 */
		while(scanf("%s",opt[0]) and opt[0][0]!='q'){
			scanf("%d %s %d\n",&A,opt[1],&B);
			/* 若積木Ａ和積木Ｂ屬於同個堆疊，該次指令作廢 */
      if(where[A]==where[B]) continue;
			if(opt[0][0]=='m') ClearUp(where[A],Inpos[A]);
			if(opt[1][1]=='n') ClearUp(where[B],Inpos[B]);
			MoveTo(where[A],Inpos[A],where[B]);
		}
    /* 輸出每個堆疊的內容 */
		for(int i=0;i<N;i++){
			printf("%d:",i);
			for(int j=0;j<Ssize[i];j++)
				printf(" %d",Stack[i][j]);
			putchar('\n');
		}
	}
}