/* 第一個要求的是超車的事件個數，這可以簡單的用BIT解決。而我們要能依序求出所有的超車事件，
 * 當然不可能把所有事件都算出來再排序。考慮任何時間點的超車事件，一定是相鄰的兩輛車前面追過後面，
 * 所以其實可以維護一個 linked list ，代表目前的車輛的前後情形，並且即將發生的超車事件只有 n-1 種可能
 * ，所以可以維護所有超車事件的 set ，每次都取出最小的就是這次發生的超車事件，
 * 然後要把 linked list 維護好， set 也會需要刪掉兩個東西( 如果有的話 )和加入新的有可能發生的超車事件。
 */

#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define MAXN 250001
#define MOD 1000000

int N;
int srt[MAXN];// srt[x] = y :: x - this position, y - this position's car number
int chg[MAXN];// chg[x] = y :: x - car's number, y - car's position
int x[MAXN]; // the initial place of i'th car
int v[MAXN]; // the velocity of i'th car
int vsum[101]; // BIT的形式

struct EVENT{
  int b, f, dx, dv; // b,f is the number of the car( not position )
  EVENT(int i=0,int j=0,int k=0,int l=0):b(i),f(j),dx(k),dv(l){}
  bool operator<(const EVENT &rhs)const{
    if(dx*rhs.dv==rhs.dx*dv)
		  return (long)rhs.dv*(x[b]*dv+v[b]*dx)>(long)dv*(x[rhs.b]*rhs.dv+v[rhs.b]*rhs.dx);// becareful overflow
	  return dx*rhs.dv>rhs.dx*dv;
  }
};
priority_queue<EVENT,vector<EVENT>> PQ;
set<pair<int,int>> SET;
inline void PQ_PUSH(int b,int f){
  PQ.push( EVENT(b,f,x[f]-x[b],v[b]-v[f]) );
}
int main(){
  // 測資讀取
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d%d",&x[i],&v[i]),
    srt[i]=chg[i]=i;
  // 只要現在的車速比之前的車速快，最終一定可以超車
  int cnt=0;
	for(int i=N-1;i>=0;i--){
		for(int j=v[i]-1;j>0;j-=lowbit(j)) // BIT_query
		  cnt=(cnt+vsum[j])%MOD;
		for(int j=v[i];j<=100;j+=lowbit(j))// BIT_update
		  vsum[j]++;
	}
	printf("%d\n",cnt);

  // 找出前10000組的超車紀錄
  for(int i=1;i<N;i++)
    if(v[i]<v[i-1]){
      // Not to push the position, 'cause it has the probability to change
		  // PUSH( number of the car, the car infront of it ) -> not the position
      PQ_PUSH(i-1,i);
      SET.insert(make_pair(i-1,i));
    }
  for(int rem=10000;PQ.empty()==0 and rem; rem--){
    EVENT now=PQ.top(); PQ.pop();
		printf("%d %d\n", now.b+1, now.f+1 );

		// bbp car , bp car , fp car , ffp car
		int bbp=chg[now.b]-1,
		     bp=chg[now.b],
		     fp=chg[now.f],
		    ffp=chg[now.f]+1;

		swap( srt[bp], srt[fp] ); // the car on this pair of position if swap
		swap( chg[now.b], chg[now.f] ); // the position of this pair of car is swap

		if( bbp>=0 and v[srt[bbp]]>v[srt[bp]] and SET.count(make_pair(srt[bbp],srt[bp]))==0 )
				PQ_PUSH( srt[bbp], srt[bp] ),
				SET.insert( make_pair( srt[bbp], srt[bp] ) );

		if( ffp<N and v[srt[fp]]>v[srt[ffp]] and SET.count(make_pair(srt[fp],srt[ffp]))==0 )
				PQ_PUSH( srt[fp], srt[ffp] ),
				SET.insert( make_pair( srt[fp], srt[ffp] ) );

  }
}
/*
4
0 2
2 1
3 8
6 3
*/