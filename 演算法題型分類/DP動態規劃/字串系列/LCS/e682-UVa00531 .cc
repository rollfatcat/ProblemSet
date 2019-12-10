/* 經典最長共同子字串問題, 比較單位從字元變為字串
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=100+1;
vector<string> Ass, Bss;
int LCS[MaxN][MaxN]; // 所有單詞長度少於30個字元。每句話少於100個單詞，且至少有一個共同詞。
int dir[MaxN][MaxN]; // 1＝左上角, 2＝左, 3＝上

inline void BackTrace(int x,int y){
	if(x==1){ cout<<Ass[0]; return; }
	if(y==1){ cout<<Bss[0]; return; }
	if(dir[x][y]==1){
		BackTrace(x-1,y-1);
		cout<<' '<<Ass[x-1];
	}else if(dir[x][y]==2)
		BackTrace(x,y-1);
	else
		BackTrace(x-1,y);
}
int main(){
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	
	string ss;
	while(cin>>ss){
		Ass.clear(), Bss.clear();
		Ass.push_back(ss);
		while(cin>>ss and ss!="#")
			Ass.push_back(ss);
		while(cin>>ss and ss!="#")
			Bss.push_back(ss);
		//
		memset(LCS,0,sizeof(LCS));
		for(int i=0;i<Ass.size();i++)
			for(int j=0;j<Bss.size();j++)
				if(Ass[i]==Bss[j]){
					dir[i+1][j+1]=1;
					LCS[i+1][j+1]=LCS[i][j]+1;
				}else if(LCS[i+1][j]>LCS[i][j+1]){
					dir[i+1][j+1]=2;
					LCS[i+1][j+1]=LCS[i+1][j];
				}else{
					dir[i+1][j+1]=3;
					LCS[i+1][j+1]=LCS[i][j+1];
				}
		// BackTrace
		BackTrace(Ass.size(),Bss.size());
		cout<<'\n';
	}
}

