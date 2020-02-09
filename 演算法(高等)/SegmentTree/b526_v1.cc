// 一般解法(48ms)：考慮『線段重疊』時的3種情況
/* 把全部的區間做排序(利用pair和proirty_queue)
 * 依序取出兩個線段討論重疊時的情況，假設前者區間為a 後者區間為b
 * (1) a.L<=a.R<b.L<=b.R (兩線段毫無重疊):直接輸出區間a內的個數並把區間b丟回priorty_queue
 * (2) a.L<=b.L<=a.R<=b.R(兩線段重疊): 計算[a.L,b.L]區間內的個數，並且把新的區間(a.R<b.R]丟回priorty_queue
 * (3) a.L<=b.L<=b.R<a.R (前者包覆後者): 計算[a.L,b.L]區間內的個數，並且把新的區間(b.R<a.R]丟回priorty_queue
 */
#include<bits/stdc++.h>
using namespace std ;

typedef pair<int,int> PII ;
priority_queue< PII ,vector<PII> ,greater<PII> > pq ;

#define l first
#define r second

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int n ,m ;
  scanInt(n),
  scanInt(m);

	//input -----------------
  for(int i=0,l,r; i<m; i++)
		scanInt(l),
		scanInt(r),
		pq.push( make_pair(l,r) );

  //solve -----------------
  /* 分情況討論重疊的處理
   */
  int ans=0;
  while(pq.size()>1){
    auto a=pq.top(); pq.pop();
    auto b=pq.top(); pq.pop();
    if( a.r<b.l ){ //a.l<=a.r<b.l<=b.r
			ans+=a.r-a.l+1;
			pq.push(b);
    }else if(b.l<=a.r and a.r<=b.r ){ 	//a.l<=b.l<=a.r<=b.r
      ans+=b.l-a.l;
      if(a.r+1<=b.r)
        pq.push(make_pair(a.r+1,b.r)) ;
    }else{ // a.l<=b.l<=b.r<a.r
			ans+=b.l-a.l ;
      pq.push(make_pair(b.r+1,a.r)) ;
    }
  }
	if(!pq.empty()){
		auto a=pq.top();  pq.pop();
		ans+=a.r-a.l+1;
	}
  //output ----------------
  printf("%d\n",n-ans);
}