// 燈泡問題：地圖大小只有6x6
#include <bits/stdc++.h>
using namespace std;

const int oo=1<<30;
int R, C;
int mv[5]={1, -1, 0, 0, 0};
struct data_map{
	bool mp[8][8];
	int MatchPre(int nowR, int s){
		if(nowR==R+1){
			for(int i=1;i<=C;i++)
			  if(mp[R][i])
			    return oo;
			return s;
		}
		for(int i=1;i<=C;i++)
		  if(mp[nowR-1][i]){
		    s++;
			  for(int j=0;j<=4;j++)
			    mp[ nowR+mv[j] ][ i+mv[4-j] ]^=1;
		  }
		return MatchPre(nowR+1,s);
	}
	int TryRow(int nowC, int s){
	  // 複製一個，並且對該物件的(1,l)的燈按下去
		data_map copy=*this;
		for(int i=0;i<=4;i++)
		  copy.mp[ 1+mv[i] ][ nowC+mv[4-i] ]^=1;
		if( nowC==C ) return min( MatchPre(2,s), copy.MatchPre(2,s+1) );
		else  return min( TryRow(nowC+1,s), copy.TryRow(nowC+1, s+1) );
	}
};
int main(){
	while(cin>>R>>C){
		string L[7];
		data_map m;
		for(int i=1;i<=R;i++)
		  cin>>L[i];
		for(int i=1;i<=R;i++)
		  for(int j=1;j<=C;j++)
		    m.mp[i][j]=(L[i][j-1]=='O');
		int minCnt=m.TryRow(1,0);
		if(minCnt==oo) puts("Can not");
		else  cout<<"Minimum Steps :"<<minCnt<<'\n';
	}
}