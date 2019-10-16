/* 給定一個由小到大的數列, 輸出剔除重複數字後且大到小的數列 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline void putInt(int x,int L=0){
	if(x==0){ 
		putchar_unlocked('0'); 
		return;
	}
	char ss[12];
	for(;x;x/=10)
		ss[L++]=x%10+'0';
	while(L--)
		putchar_unlocked(ss[L]);
}
int main(){
	
	int N, x;
	scanInt(N);
	
	vector<int> num(N);
	for(int i=0;i<N;i++)
		scanInt(num[i]);
	sort(num.begin(),num.end());
	for(int x:num)
		putInt(x), 
		putchar_unlocked(' ');
	putchar_unlocked('\n'), 
	putInt(num.back());
	
	for(int i=num.size()-2;i>=0;i--)
		if(num[i]!=num[i+1])
			putchar_unlocked(' '), 
			putInt(num[i]);
	putchar_unlocked('\n');
}