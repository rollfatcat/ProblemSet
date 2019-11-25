/* 讓 PQ 裡的數字全部扣除Ｘ時, 等同新推入的數字+Ｘ
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxOptN=3e5;
struct DATA{
	long val; int pos;
	DATA(long v=0,int p=0): val(v),pos(p){}
	inline bool operator<(const DATA &rhs)const{ return val>rhs.val; }
};
inline void scanInt(int &x){char ch;for(x=0;'0'<=(ch=getchar_unlocked()) and ch<='9'; x=(x<<3)+(x<<1)+ch-'0');}
inline void scanLong(long &x){char ch;for(x=0;'0'<=(ch=getchar_unlocked()) and ch<='9'; x=(x<<3)+(x<<1)+ch-'0');}
inline void PrintInt(int x,int L=0){
	if(x==0){ puts("0"); return; }
	char ss[20];
	for(;x>0;ss[L++]=x%10+'0',x/=10);
	for(;L--;putchar_unlocked(ss[L]));
	putchar('\n');
}
 
int main(){
	int OptN;
	scanInt(OptN);
 
	int front=0, rear=0;
	vector<long> Q;
	priority_queue<DATA,vector<DATA>> PQ;
	long number, base=0;
	for(int opt; OptN--; ){
		scanInt(opt),
		scanLong(number);
		if(opt==2){
			base+=number;
			while(PQ.empty()==0 and PQ.top().val<=base)
				Q[PQ.top().pos]=-1,
				PQ.pop();
			while(front<rear and Q[front]==-1)
				front++;
			PrintInt(rear-front-PQ.size());
		}else
			Q.push_back(number),
			PQ.push(DATA(number+base,rear++));
	}
 
}