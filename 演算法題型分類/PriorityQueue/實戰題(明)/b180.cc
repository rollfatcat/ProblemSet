/* 給定Ｎ組客人的抵達時間(ｔ)和遊園時間(Ｔ)，客人從抵達時間往後最多等候３０分鐘，最少需要幾輛客車才能滿足所有客人？
 * 解題關鍵：貪婪法＋PriorityQueue
 * 從最早回來的客車中挑選一台給目前抵達的客人，最早回來的客車趕不上(或者沒有客車)時才不得已新增一台客車。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=60;
const int Maxt=60;
const int MaxT=60;
const int BOUND=30;

struct DATA{
	int t, T;
	bool operator<(const DATA &rhs)const{ 
		return (t==rhs.t)? T<rhs.T: t<rhs.t; 
	}
} data[MaxN];

int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i].t,&data[i].T);
		sort(data,data+N);
		
		priority_queue<int,vector<int>,greater<int>> PQ;
		for(int i=0;i<N;i++){
			if(PQ.empty() or PQ.top()>data[i].t+BOUND)
				PQ.push(data[i].t+data[i].T);
			else{
				PQ.push( max(PQ.top(),data[i].t)+data[i].T  );
				PQ.pop();
			}
		}
		printf("%d\n",PQ.size());
	}
}