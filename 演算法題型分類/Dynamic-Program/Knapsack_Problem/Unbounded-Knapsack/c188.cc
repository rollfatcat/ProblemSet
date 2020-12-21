#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 201

long long int M[MaxN][MaxN];
long long int DP1(int max, int sum){
	if(M[max][sum]==0)
		for(int i=(max<sum)?max:sum; i>0 ;i--)
			M[max][sum]+=DP1(i,sum-i);
	return M[max][sum];
}
long long int DP2(int max, int sum){
	if(M[max][sum]==0)
		if(max>sum)
			M[max][sum]=DP2(sum,sum);
		else
			M[max][sum]=DP2(max,sum-max)+DP2(max-1,sum);
	return M[max][sum];
}
int main(){
	memset(M,0,sizeof(M));
	for(int i=1;i<MaxN;i++)
		M[i][0]=M[i][1]=M[1][i]=1;
	M[0][0]=1;
	int n, m;
	while(cin>>n>>m)
		cout<<DP2(n,m)<<endl;
}