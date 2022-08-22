/* 給定Ｎ，計算１到Ｎ內任意選擇２個數字相乘是平方數的組合
 * 解題關鍵：歸納法 + gcd()
 * 枚舉每個數字，除了自己以外還可以和符合什麼樣條件的數字搭配 ... 任意２個平方數的組合乘以「放大倍數」
 *  {12,27} = 3*{4,9}
 *  {16,36} = 4*{4,9} = 1*{16,36}
 *  枚舉任意２個平方數的組合，避免重複計算到，所以必須符合「互質」時累加「放大倍數」
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
int main(){
	int N, ans;
	
	cin>>N;
	ans=N;
	for(int a=1; a*a<=N; a++)
		for(int b=a+1; b*b<=N; b++)
			if( __gcd(a,b)==1 )
				ans+= N/(b*b)<<1;
	cout<<ans;
}