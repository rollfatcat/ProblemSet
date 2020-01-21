/* 給定1-100個字串(整行讀取)，根據『字典序』輸出相同的『變位字』
 * 因為字串中包含空白, 所以讀取時需要getline()且統計時得避開空白的情況
 * 排序後, 暴力法判斷任意兩個字串的字母頻率是否相同
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100+2;
vector<string> ss(MaxN);
vector<int> one(26);
vector<vector<int>> cnt(MaxN,one);

inline bool CntEqual(int a,int b){
	for(int i=0;i<26;i++)
		if(cnt[a][i]!=cnt[b][i])
			return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseT, N;
	cin>>caseT; 
	getline(cin,ss[0]);
	getline(cin,ss[0]);
	while(caseT--){
		for(N=0;getline(cin,ss[N]) and ss[N]!="";N++);
		sort(ss.begin(),ss.begin()+N);
		for(int i=0;i<N;i++){
			fill(cnt[i].begin(),cnt[i].end(),0);
			for(int j=0;ss[i][j]!='\0';j++)
				if(ss[i][j]!=' ')
					cnt[i][ss[i][j]-'a']++;
		}
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
				if(CntEqual(i,j))
					cout<<ss[i]<<" = "<<ss[j]<<'\n';
	}
}