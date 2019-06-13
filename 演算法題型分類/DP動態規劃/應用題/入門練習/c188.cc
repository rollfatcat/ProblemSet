// 前置題：a144，DFS找出所有解
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 201

long long int M[MaxN][MaxN];
long long int DP(int sum, int max){
	if(sum<0 or max<0)
		return 0;
	if(M[max][sum]==0)
		for(int i=max;i>0;i--)
			M[max][sum]+=DP(sum-i,i);
	return M[max][sum];
}
int main(){

	memset(M,0,sizeof(M));
	for(int i=1;i<MaxN;i++)
		M[i][0]=M[i][1]=M[1][i]=1;
	M[0][0]=1;
	int n;
	while(cin>>n)
		cout<<DP(n,n)<<endl;
}