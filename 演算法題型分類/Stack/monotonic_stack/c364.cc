/* 給定Ｎ位同學的身高，相鄰的同學間存在鄙視鏈(高歧視矮)，輸出每位同學的鄙視身高總和？
 * 解題關鍵：monotonic stack(單調棧)，維護的身高呈現非嚴格遞增
 * 往左和往右延伸直到身高不低於自己時鄙視鏈會停止，答案為範圍內的身高總和(前綴和)
 * 備用測資(遇到一樣的數字時要注意處理)
 * 10
 * 1 1 2 2 1 1 2 2 1 1
 * 10
 * 1 1 2 2 3 3 2 2 1 1
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxH=1e9;
int  hgt[MaxN+2];
long prS[MaxN+2];
long ans[MaxN+1];
 
int main(){
	int N;
	scanf("%d",&N);
	// input & prefixsum
	hgt[0]=hgt[N+1]=MaxH+1;
	for(int i=1;i<=N;i+=1){
		scanf("%d",&hgt[i]);
		prS[i]=prS[i-1]+hgt[i];
	}
	prS[0]=0;
	// monotonic stack to find the previous greater number
	stack<int> s; s.push(0);
	for(int i=1;i<=N;i+=1){
		while(hgt[s.top()]<hgt[i])
			s.pop();
		ans[i]=prS[i-1]-prS[s.top()];
		s.push(i);
	}
	// clear stack
	for(; s.empty()==0; s.pop());
	// monotonic stack to find the next greater number
	s.push(N+1);
	for(int i=N;i>0;i-=1){
		while(hgt[s.top()]<hgt[i])
			s.pop();
		ans[i]+=prS[s.top()-1]-prS[i];
		s.push(i);
	}
	for(int i=1;i<=N;i+=1)
		printf("%ld\n",ans[i]);
}