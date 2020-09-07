#include<bits/stdc++.h>
using namespace std;

const long MaxN=9e9;
vector<long> leng={0};
vector<long> base={0};
int main(){
	long cnt=9;
	for(int L=1; leng.back()<MaxN; cnt*=10,L++)
		base.push_back(base.back()+cnt),
		leng.push_back(leng.back()+cnt*L);
	for(long N; scanf("%ld\n",&N)!=EOF;){
		int L=lower_bound(leng.begin(),leng.end(),N)-leng.begin();
		int number=(N-1-leng[L-1])/L+base[L-1]+1;
		for(int t=0;t<L-1-(N-1-leng[L-1])%L;t++)
			number/=10;
		printf("%d\n",number%10);
	}
}