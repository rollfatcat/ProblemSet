/* 給定Ｎ個數字，輸出 最大化的區間和乘積？題目保證每個數字介於(0,1000000)
 * 區間和乘積＝區間和乘上範圍內『最小的數字』
 * 解題關鍵：單調棧
 * 找到左右邊第一個小於目前數字＝這段範圍內的數字都大於等於目前的數字＝這個範圍的前綴和*目前數字
 */
#include<iostream>
#include<stack>
using namespace std;

const int MaxN=1e5+2;
const int MaxV=1e6;
long long num[MaxN];
long long prS[MaxN];

int main(){
	int N, L, R;
	
	scanf("%d\n",&N);
	num[0]=num[N+1]=-1; 
	prS[0]=0;
	for(int i=1;i<=N;i++){
		scanf("%ld",&num[i]);
		prS[i]=prS[i-1]+num[i];
	}
	long long ans=-1;
	stack<int> mts;
	mts.push(0);
	for(int pvt=1; pvt<=N+1; pvt++){
		while(num[mts.top()]>num[pvt]){
			long long now=num[mts.top()]; mts.pop();
			long long tmp=now*( prS[pvt-1]-prS[mts.top()] );
			if(ans<tmp){
				ans=tmp;
				L=mts.top()+1;
				R=pvt-1;
			}
		}
		mts.push(pvt);
	}
	printf("%lld\n%d %d\n",ans,L,R);
}