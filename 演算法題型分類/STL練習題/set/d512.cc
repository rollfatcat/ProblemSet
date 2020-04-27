/* 給定Ｎ個數字，挑選Ｋ個數字加起來，問可以湊出多少不同數字？
 * (1) 0.2s，Ｎ≦ 19，遞迴枚舉每個數字選或不選，將加總後的數字以set紀錄。 
 * (2) 27ms，一邊確保『不重複』的數字( 以set紀錄 )加上新數字後也不會重複
 *          從 set 中取出數字需要從尾端依序讀取，避免相加後的新數字放回 set 時又被重復計算
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=19;
int main(){
	for(int N,x;scanf("%d\n",&N)!=EOF;){
		set<long> memo;
		memo.insert(0);
		for(int i=0;i<N;i++){
			scanf("%d",&x);
			set<long>::iterator it=memo.end();
			for(it--;it!=memo.begin();it--)
				if( memo.find(*it+x)==memo.end() )
					memo.insert(*it+x);
			if( memo.find(*it+x)==memo.end() )
					memo.insert(*it+x);
		}
		printf("%lu\n",memo.size()-1);
	}
}