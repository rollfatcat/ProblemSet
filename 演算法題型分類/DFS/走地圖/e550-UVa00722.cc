/* 題目的解法就是單純DFS, 計算走道的格子數
 * 讀取格式時不會告知地圖的長寬, 停止條件是當getline()讀取到空白字串。
*/
#include<bits/stdc++.h>
using namespace std;

const int MaxR=99;
const int MaxC=99;
struct NODE{ 
	int x,y; 
	NODE(int x=0,int y=0):x(x),y(y){}
} st, now;

int main(){
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	
	int caseT;
	string ss;
	cin>>caseT;
	while(caseT--){
		cin>>st.x>>st.y;
		st.x--, st.y--;
		vector<string> mapss;
		for(getline(cin,ss); getline(cin,ss) and ss!="";mapss.push_back(ss));
		
		// 利用 Stack 模擬 DFS
		int ans=0;
		stack<NODE> S;
		S.push(st);
		while(S.empty()==0){
			now=S.top(); S.pop();
			if(mapss[now.x][now.y]=='1') 
				continue;
			ans++;
			mapss[now.x][now.y]='1';
			if(now.x>0 and mapss[now.x-1][now.y]=='0')
				S.push(NODE(now.x-1,now.y));
			if(now.y>0 and mapss[now.x][now.y-1]=='0')
				S.push(NODE(now.x,now.y-1));
			if(now.x+1<mapss.size() and mapss[now.x+1][now.y]=='0')
				S.push(NODE(now.x+1,now.y));
			if(now.y+1<mapss[now.x].size() and mapss[now.x][now.y+1]=='0')
				S.push(NODE(now.x,now.y+1));
		}
		cout<<ans<<'\n';
	}
}