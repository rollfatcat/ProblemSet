/* 給定Ｎ位玩家的資料(名稱/血量/傷害/等量的物品/下一位傳導者)，依據傷害的傳導途徑輸出沿途玩家的剩餘血量和物品？
 * 玩家只能保留和血量相同的物品數量，多出來的物品會依照輸入順序捨棄，若血量歸零時則輸出"dead"。
 * 從第Ｓ位玩家開始擴散傷害，每位玩家只會受到傷害一次，若傷害重複傳導到同一位玩家時就結束傳導。
 * 解題關鍵：struct＋模擬
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxL=10+2;
const int MaxT=10;
struct OBJ{
	char name[MaxL];
	int item_n, hp, dmg, nxt;
	char item[MaxT][MaxL];
} player[MaxN];
 
int main(){
	int N, S;
	scanf("%d %d",&N,&S);
	for(int i=0; i<N; i+=1){
		scanf("%s",player[i].name);
		scanf("%d %d",&player[i].hp,&player[i].dmg);
		player[i].item_n=player[i].hp;
		for(int j=0; j<player[i].item_n; j+=1)
			scanf("%s",player[i].item[j]);
		scanf("%d",&player[i].nxt);
	}
	for(S-=1; player[S].hp==player[S].item_n; S=player[S].nxt-1){
		printf("%s",player[S].name);
		player[S].hp-=player[S].dmg;
 
		if(player[S].hp<=0){ puts(" dead."); continue; }
 
		printf(" %d",player[S].hp);
		for(int i=0; i<player[S].hp; i+=1)
			printf(" %s",player[S].item[i]);
		putchar('\n');
	}
}