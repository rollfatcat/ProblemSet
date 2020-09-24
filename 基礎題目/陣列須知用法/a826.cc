/* 給定Ｎ條預測規則，輸出 train_data 的答對題數和當下狀態的結果和依據規則(衝突時採優先偵測)？
 * 預測規則的型態：只要 氣溫/濕度是... 就是Ｙ/Ｎ
 * 解題關鍵：二維陣列(建立數字和資料字串的對應關係)
 * 狀態有２個維度，每個維度各有３種選項：Temperature、Humidity，所以需要二維陣列(２個維度)記錄所有的組合。
 * train_data : 需要紀錄每筆資料的 Temperature、Humidity、result(以數字代表)。
 * 輸入的規則：當 氣溫/濕度是... 就是Ｙ/Ｎ
 *           固定一個維度時，將另一個維度的所有選項(未被其他規則標記號碼時)都標記為目前規則的號碼和結果。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxRule=5;
int data[10][3]={{1,0,1},{1,1,1},{1,0,1},{2,2,0},{2,2,0},{2,2,0},{2,2,0},{2,0,0},{2,1,0},{0,0,1}};
int rule[3][3]; // Temperature x Humidity
bool rsp[3][3];

int main(){
	int N, T, H;
	char type, result;
	char input[10];
	
	scanf("%d\n",&N);
	memset(rule,0,sizeof(rule)); // default is 0
	memset(rsp ,0,sizeof(rsp )); // default is No
	for(int rule_i=1; rule_i<=N; rule_i++){
		scanf("%c %s %c\n",&type,input,&result);
		result= result=='Y';
		int level=('d'<input[0])+(input[0]=='h');
		if(type=='T'){
			if(rule[level][0]==0) 
				rule[level][0]=rule_i, rsp[level][0]=result;
			if(rule[level][1]==0) 
				rule[level][1]=rule_i, rsp[level][1]=result;
			if(rule[level][2]==0) 
				rule[level][2]=rule_i, rsp[level][2]=result;
		}else{
			if(rule[0][level]==0) 
				rule[0][level]=rule_i, rsp[0][level]=result;
			if(rule[1][level]==0) 
				rule[1][level]=rule_i, rsp[1][level]=result;
			if(rule[2][level]==0) 
				rule[2][level]=rule_i, rsp[2][level]=result;
		}
	}
	/* 輸出 train_data 的答對次數 */
	int ac_cnt=0;
	for(int i=0;i<10;i++)
		ac_cnt+= rsp[data[i][0]][data[i][1]]==data[i][2];
	printf("%d\n",ac_cnt);
	
	scanf("%d %d\n",&T,&H);
	T= (20<=T)+(28<=T);
	H= (30<=H)+(60<=H);
	printf("%d\n%c\n",rule[T][H],rsp[T][H]? 'Y':'N');
	
}