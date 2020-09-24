/* 給定２個位數不超過１０的十進位，輸出進位次數？
 * 解題關鍵：大數加法
 * 讀取時字串是由位數高到低，但大數加法需要對齊所以位數低的放在陣列前面的位置。 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=10;
char ss[2][MaxL+2];
int bit[2][MaxL], L[2];
int main(){
	while(scanf("%s %s\n",ss[0],ss[1])){
		/* 預設 ss[1] 是位數較長的 */
        L[0]=strlen(ss[0]);
		L[1]=strlen(ss[1]);
		if(L[0]>L[1]){
			swap( L[0], L[1]);
			swap(ss[0],ss[1]);
		}
        /* 儲存時需要反方向著存，位數越高放越後面 */
		for(int i=0;i<L[0];i++)
			bit[0][i]=ss[0][L[0]-1-i]-'0';
		for(int i=0;i<L[1];i++)
			bit[1][i]=ss[1][L[1]-1-i]-'0';
		if(ss[0][0]=='0' and ss[1][0]=='0')
			break;
		
		int carry_cnt=0;
		int carry=0;
		for(int i=0;i<L[0] and i<L[1];i++){
			carry=bit[0][i]+bit[1][i]+carry;
			carry_cnt+= carry>=10;
			carry= carry>=10;
		}
		for(int i=L[0];i<L[1];i++){
			carry=bit[1][i]+carry;
			carry_cnt+= carry>=10;
			carry= carry>=10;
		}
		(carry_cnt>1)? printf("%d carry operations.\n",carry_cnt):puts( (carry_cnt==1)?"1 carry operation.":"No carry operation.");
	}
}