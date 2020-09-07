/* 給定ＡＢ，輸出落在範圍內數列數字的個數？
 * 解題關鍵：二分搜的STL
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxM=1e18;
int main(){
	vector<long> num={0,1,2,3};
	while(num.back()<=MaxM)
		num.push_back(num.back()+num[num.size()-2]+num[num.size()-3]);
	long N, M;
	scanf("%ld %ld\n",&N,&M);
	N=upper_bound(num.begin(),num.end(),M)-lower_bound(num.begin(),num.end(),N);
	printf("%d\n",N);
}