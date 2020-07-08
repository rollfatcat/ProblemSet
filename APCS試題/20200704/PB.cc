/* 給定Ｎ顆骰子和Ｍ次操作，輸出Ｎ個骰子的上面
 * 每顆骰子的初始狀態：(up,right,down,left,front,back)=(1,2,6,5,4,3)
 * 操作為２個數字(ａ,ｂ)分為３類：ｂ=-1時骰子ａ往前滾一面 / ｂ=-2時骰子ａ往右滾一面 / ｂ>0時交換骰子ａ和骰子ｂ的狀態
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100+1;
const int MaxM=100;

struct DICE{
	int up,right,down,left,front,back; // 上右下左前後
	DICE(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0):up(a),right(b),down(c),left(d),front(e),back(f){}
	DICE Right(){ return DICE(left,up,right,back,front,back); }
	DICE Forwd(){ return DICE(back,right,front,left,up,down); }
} dices[MaxN];
int main(){
	int N, M, a, b;
	scanf("%d %d\n",&N,&M);
	
	for(int i=1;i<=N;i++)
		dices[i]=DICE(1,2,6,5,4,3);
	while(M--){
		scanf("%d %d\n",&a,&b);
		if(b==-2) dices[a]=dices[a].Right();
		if(b==-1) dices[a]=dices[a].Forwd();
		if(b>0) swap(dices[a],dices[b]);
	}
	for(int i=1;i<=N;i++)
		printf("%d ",dices[i].up);
}
