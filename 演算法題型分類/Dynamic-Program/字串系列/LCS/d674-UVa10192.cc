/* 輸入的字串包含空白字元, 需使用 getline() 讀取
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxL=100;
string ss[2];
int dpv[MaxL][MaxL];

inline int LCS(int L1,int L2){
	if(L1<0 or L2<0) return 0;
	if(dpv[L1][L2]==-1)
		dpv[L1][L2]=(ss[0][L1]==ss[1][L2])? LCS(L1-1,L2-1)+1:max(LCS(L1-1,L2),LCS(L1,L2-1));
	return dpv[L1][L2];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseI=1;
	while(getline(cin,ss[0]) and ss[0][0]!='#'){
		getline(cin,ss[1]);
		for(int i=0;i<ss[0].length();i++)
			for(int j=0;j<ss[1].length();j++)
				dpv[i][j]=-1;
		cout<<"Case #"<<caseI++<<" you can visit at most "<<LCS(ss[0].length()-1,ss[1].length()-1)<<" cities.\n";
	}
}



