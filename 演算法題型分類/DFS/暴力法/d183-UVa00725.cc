/* 查詢時給定商數Ｎ，問有多少組的Ａ除以Ｂ剛好等於查詢的商數？
 * '０'-'９'每個字元各用一次組成兩個數字ＡＢ。
 */
#include<bits/stdc++.h>
using namespace std;

bool use[10]={};
string one="          ";
vector<string> memo[80];

void DFS(int A,int B,int depth){
	if(depth==5){
		if(A%B==0)
			memo[A/B].push_back(one);
		return;
	}
	A*=10, B*=10;
	for(int i=0;i<=9;i++)
		for(int j=i+1;j<=9;j++)
			if(use[i]==0 and use[j]==0){
				use[i]=use[j]=1;
				one[ depth ]=i+'0'; 
				one[depth+5]=j+'0';
				DFS(A+i,B+j,depth+1);
				
				one[ depth ]=j+'0'; 
				one[depth+5]=i+'0';
				DFS(A+j,B+i,depth+1);
				use[i]=use[j]=0;
			}
}
int main(){
	/* 預跑：暴力法填入格子，
   * 枚舉Ａ、Ｂ時確保Ａ＞Ｂ所以第一次選定時一次選兩個但不交換 
   * 之後遞迴時也是一次選兩個但可以互換。
   */
  for(int i=1;i<=9;i++)
		for(int j=i-1;j>=0;j--){
			one[0]=i+'0'; 
			one[5]=j+'0';
			use[i]=use[j]=1;
			DFS(i,j,1);
			use[i]=use[j]=0;
		}
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;
	while(cin>>N and N>0)
		if(memo[N].size()==0)
			cout<<"There are no solutions for "<<N<<".\n\n";
		else
			for(string one:memo[N])
				cout<<one[0]<<one[1]<<one[2]<<one[3]<<one[4]<<" / "<<one[5]<<one[6]<<one[7]<<one[8]<<one[9]<<" = "<<N<<'\n';
}