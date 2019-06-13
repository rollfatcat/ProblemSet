// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4219236
#include<iostream>
#include<cstring>
using namespace std;

char ss[36000002],outss[36000000];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline bool scanStr(int &len){ for(len=0;(ss[len]=getchar())>='0' and ss[len]<='9';len++); ss[len]='\0'; return true;}
int BS(int l,int r,char ch){
	for(int m;l<=r;){
		m=(l+r)>>1;
		if(outss[m]>=ch)	l=m+1;
		else r=m-1;
	}
	return l;
}
int main(){

	for(int ssL,outL;scanStr(ssL) and scanInt(outL);){
		outss[0]=ss[0];
		int idx=1, now=0;
		for(; ss[idx]!='\0'; idx++){
			// O(n):找到比現在字元小且剩餘部分數量還夠
			// for(int rem=ssL-idx; now>=0 and ss[idx]>outss[now] and rem>=outL-now;now--);

			// BinarySearch找替換的字元還比較慢= =
			int rem=ssL-idx, need=outL-now, L_bound=outL-rem;
			if(rem>=need) // 只要剩餘的部分還有字元扣除需要 就可以挑戰已經選入的字元
				now=BS((L_bound>=0)?L_bound:0,now,ss[idx]),	outss[now]=ss[idx];
			else
				break;
		}
		while(idx<ssL)	outss[++now]=ss[idx++];
		for(int i=0;i<outL;i++)
			putchar(outss[i]);
		puts("");
	}
}