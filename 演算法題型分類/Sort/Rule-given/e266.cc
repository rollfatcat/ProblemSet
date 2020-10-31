/* 給定Ｎ張牌(每張牌包括花色和點數，ＧＧ代表鬼牌)，根據「鬼牌規則」移除後手上剩餘的牌？
 * 鬼牌規則：兩張牌若是相同點數且不是鬼牌則可以移除，移除時優先從花色小的開始(Ｃ>Ｄ>Ｈ>Ｓ)
 * 牌數不超過１００張且正常的牌不重複(會重複的只有鬼牌)
 * 解題關鍵：排序＋貪婪法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
int mapv[128];
struct CARD{
	char num, clr;
	CARD(char n=0,char c=0):num(n),clr(c){}
	bool const operator<(const CARD rhs)const{
		return mapv[num]==mapv[rhs.num] ? clr<rhs.clr: mapv[num]<mapv[rhs.num];
	}
} cards[MaxN];


int main(){
  for(char c='2';c<='9';c++)
  	mapv[c]=c-'0';
  mapv['A']=1;
  mapv['T']=10;
  mapv['J']=11;
  mapv['Q']=12;
  mapv['K']=13;
  
  int N, uN, GG_card;
  char clr, num;
  while(scanf("%d",&N) and N>0){
  	/* 讀取時因為鬼牌無法兩兩相同時移除，所以將鬼牌的張數額外統計不納入排序 */
    uN=GG_card=0;
  	while(N-->0){
  		scanf(" %c%c",&num,&clr);
  		if(num=='G'){ GG_card++; continue; }
  		cards[uN++]=CARD(num,clr);
  	}
  	sort(cards,cards+uN);
  	
    /* 自己和下一張(若存在)點數相同時則"移除"(跳過輸出)，否則輸出這張牌的點數和花色並紀錄手上的牌數多１ 
     * 以下部分Ｎ代表在移除規則後的手牌張數，題目要求鬼牌最後輸出，所以根據 GG_card 重複印出。
     * 特殊情況：當手牌張數＝０時要輸出"No card"
     */
    N=0;
    for(int i=0;i<uN;i++)
  		if(i+1<uN and cards[i].num==cards[i+1].num) 
  			i++;
  		else
  			printf("%c%c ",cards[i].num,cards[i].clr),N++;
  	
  	for(int i=0;i<GG_card;i++)
  		printf("GG ");
  	((N+GG_card)==0)? puts("No card"):putchar('\n');
  }
}
