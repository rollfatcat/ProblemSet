/* 給定Ｎ，將每個位數的數字按遞增排序生成Ａ，按遞減排序生成Ｂ，newＮ=Ａ-Ｂ，下次依照相同方法計算直到出現循環，問計算了多少次？
 * 解題關鍵：數字和字串轉換＋ set<int>
 * 產生循環的意思＝出現之前曾經過的數字(不一定是上一個)而本題的答案並非輸出循環長度而是計算次數
 */
#include <bits/stdc++.h>
using namespace std;


const int MaxN=1e9;
int IntToSS(int v,char Nss[],int NL=0){
	if(v==0) Nss[NL++]=0;
	for(; v>0; v/=10)
		Nss[NL++]=v%10;
	return NL;
}
int SSToInt(int NL,char Nss[]){
	int A=0, B=0;
	for(int i=0;i<NL;i++)
		A=(A<<3)+(A<<1)+Nss[i],
		B=(B<<3)+(B<<1)+Nss[NL-1-i];
	printf("%d - %d = %d\n",B,A,B-A);
	return B-A;
}

int main(){
	int now_v, pre_v, cycle;
	char vss[9];
	while(scanf("%d\n",&pre_v) and pre_v>0){
		printf("Original number was %d\n",pre_v);
		set<int> memo;
		for(cycle=1; true; cycle++){
			int L=IntToSS(pre_v,vss);
			sort(vss,vss+L);
			now_v=SSToInt(L,vss);
			if(memo.find(now_v)!=memo.end()) 
				break;
			pre_v=now_v;
			memo.insert(now_v);
		}
		printf("Chain length %d\n\n",cycle);
	}
}