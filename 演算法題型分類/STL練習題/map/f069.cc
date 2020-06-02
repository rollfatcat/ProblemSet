/* 給定體重Ｗ和Ｎ種食物名稱和熱量，Ｍ次的進食後問攝取的總熱量是否超過體重的40倍？
 * 需要<map>建立名稱和熱量的關係，之後做計算時輸入名稱後即可知道每單位的食物熱量
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	long N, M, W, v;
	string ss;
	while(cin>>N>>W){
		map<string,long> memo;
		for(int i=0;i<N;i++){
			cin>>ss>>v;
			memo[ss]=v;
		}
		long sum=0;
		for(cin>>M;M--;){
			cin>>ss>>v;
			sum+=memo[ss]*v;
		}
		cout<<( (sum>40*W)? "Euan eats too much.\n": "Euan you are doing a great job!\n" );
	}
}