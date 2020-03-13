/* 給定字串由'0'-'9'構成且長度不超過30
 * 題目給定５個規則，若違規則輸出哪條違背，若都沒有違規則輸出'0'
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=30;
int cnt[10], L;
bool illegal, rule5;
char ss[MaxL+2];
int main(){
	while(scanf("%s\n",ss)!=EOF){
		illegal=rule5=cnt[0]=cnt[1]=0;
		for(L=0;ss[L]!='\0';L++){
			cnt[ss[L]-'0']++;
			rule5|=(L>1 and ss[L]=='1' and ss[L-1]=='0' and ss[L-2]=='1');
				
		}
		
		if(cnt[0]+cnt[1]<L) illegal=1,printf("1 ");
		if(8>L or L>12)     illegal=1,printf("2 ");
		if(cnt[0]<2)        illegal=1,printf("3 ");
		if(cnt[1]<3)        illegal=1,printf("4 ");
		if(rule5==0)        illegal=1,printf("5 ");
		if(illegal==0)      printf("0 ");
		putchar('\n');
	}
}