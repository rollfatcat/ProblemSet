/* 給定地圖(由'W''L'構成)並輸出對應座標相連(附近８格)的水域面積
 * 利用 BFS 走遍相連的區域，並紀錄過程中『走過』的格子後標記為相同的面積數。
 * 有問到才從該格子展開並且記錄，若已經紀錄過則直接輸出答案。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
int cnt[MaxN][MaxN]={};
vector<string> mapss(MaxN);

int N, M;
struct NODE{
	int x, y;
	NODE(int x=0,int y=0):x(x),y(y){}
} now, ask;

inline NODE StrToPos(string ss,NODE out=NODE()){
	int idx=0;
	for(;idx<ss.length() and ss[idx]!=' ';idx++)
		out.x=10*out.x+ss[idx]-'0';
	for(idx++;idx<ss.length() and ss[idx]!=' ';idx++)
		out.y=10*out.y+ss[idx]-'0';
	out.x--, out.y--;
	return out;
}
inline int QueryCnt(){
	if(cnt[ask.x][ask.y]==-1){
		queue<NODE> memo; // For record
		queue<NODE> Q;    // For BFS
		for(Q.push(ask); Q.empty()==0; Q.pop()){
			now=Q.front();
			if(mapss[now.x][now.y]=='L') continue;
			memo.push(now);
			mapss[now.x][now.y]='L';
			if(now.x>0   and now.y>0   and mapss[now.x-1][now.y-1]=='W') Q.push(NODE(now.x-1,now.y-1));
			if(now.x>0                 and mapss[now.x-1][now.y  ]=='W') Q.push(NODE(now.x-1,now.y  ));
			if(now.x>0   and now.y+1<M and mapss[now.x-1][now.y+1]=='W') Q.push(NODE(now.x-1,now.y+1));
			if(              now.y>0   and mapss[now.x  ][now.y-1]=='W') Q.push(NODE(now.x  ,now.y-1));
			if(              now.y+1<M and mapss[now.x  ][now.y+1]=='W') Q.push(NODE(now.x  ,now.y+1));
			if(now.x+1<N and now.y>0   and mapss[now.x+1][now.y-1]=='W') Q.push(NODE(now.x+1,now.y-1));
			if(now.x+1<N               and mapss[now.x+1][now.y  ]=='W') Q.push(NODE(now.x+1,now.y  ));
			if(now.x+1<N and now.y+1<M and mapss[now.x+1][now.y+1]=='W') Q.push(NODE(now.x+1,now.y+1));
		}
		for(int sz=memo.size();memo.empty()==0;memo.pop())
			cnt[memo.front().x][memo.front().y]=sz;
	}
	return cnt[ask.x][ask.y];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseT;
	string ss;
	cin>>caseT; 
	getline(cin,ss); 
	getline(cin,ss);
	while(caseT--){
		for(N=0;getline(cin,ss) and ss[0]>'9';N++){
			mapss[N]=ss;
			for(int i=0;i<ss.length();i++)
				cnt[N][i]=-1;
		}
		M=mapss[0].length();
		do{		
			ask=StrToPos(ss), cout<<QueryCnt()<<'\n';
		}while(getline(cin,ss) and ss!="");
		
		if(caseT) cout<<'\n'; // 測資間的輸出以空白隔開
	}
}