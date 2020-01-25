/* 給定５２張牌的資訊和起始的發牌員，輸出4位玩家排序後的手牌
 * 牌序：花色(C/D/S/H)＞數字(2.../T/J/Q/K/A)，stuct＋內建的sort函數
 */
#include<bits/stdc++.h>
using namespace std;

int dict[256]]={};
char P[4]={'S','W','N','E'};
char ss[55];
struct CARD{
	char clr, ch; int val;
	CARD(char clr='.',char c='.',int v=0):clr(clr),ch(c),val(v){}
	inline bool operator<(const CARD &rhs)const{
		return (dict[clr]==dict[rhs.clr])? val<rhs.val: dict[clr]<dict[rhs.clr];
	}
};
int main(){
	/* 將字母轉到對應的數字：卡片數字的T/J/Q/K/A 和 卡片花色的C/D/S/H 和 玩家順序的S/W/N/E
	 * 花色和玩家方位的'S'是共用，所以設定卡片花色的對應數值時以Ｓ＝０為基準設定其他的花色C/D/H數值
	 */
	dict['T']=10; dict['J']=11;
	dict['Q']=12; dict['K']=13;
	dict['A']=14;
	dict['S']=0;  dict['W']=1;
	dict['N']=2;  dict['E']=3;
	dict['C']=-2; dict['D']=-1;
	dict['H']=1;
	while(scanf("%s",ss) and ss[0]!='#'){
		int now=(dict[ss[0]]+1)&3;
		vector<CARD> players[4];
		scanf("%s",ss);
		for(int i=0;i<26;i++,now=(now+1)&3)
			players[now].push_back(CARD(ss[i<<1],ss[i<<1|1],('A'<=ss[i<<1|1])? dict[ss[i<<1|1]]: ss[i<<1|1]-'0'));
		scanf("%s",ss);
		for(int i=0;i<26;i++,now=(now+1)&3)
			players[now].push_back(CARD(ss[i<<1],ss[i<<1|1],('A'<=ss[i<<1|1])? dict[ss[i<<1|1]]: ss[i<<1|1]-'0'));
		for(int i=0;i<4;i++){
			sort(players[i].begin(),players[i].end());
			printf("%c:",P[i]);
			for(int j=0;j<players[i].size();j++)
				printf(" %c%c",players[i][j].clr,players[i][j].ch);
			putchar('\n');
		}
	}
}