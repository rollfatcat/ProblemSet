/* 給定Ｑ次的操作，第(2)(3)種操作輸出對應的值(不存在時輸出-1)
 * 1 x   : 將ｘ加入數列Ａ
 * 2 x k : 數列Ａ中小於等於ｖ的所有數字第Ｋ大
 * 3 x k : 數列Ａ中大於等於ｖ的所有數字第Ｋ小
 * 解題關鍵：在線查詢-關聯性容器(multiset)數字可以存在多個重複的值
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxQ=2e5;
const int MaxK=5;
const long MaxX=1e18;
multiset<long> pool;
multiset<long> :: iterator it;
 
int main(){
	int Q, o, K;
	long v, ans;
	
	cin>>Q;
	while(Q-->0){
		cin>>o>>v;
		if(o==1){
			pool.insert(v);
		}else{
			cin>>K;
			if(o==2){ // 小於等於ｖ的數字中第Ｋ大
				it=pool.upper_bound(v);
				for( ;0<K and it!=pool.begin(); K--)
					it=prev(it);
				ans=(0<K)? -1: (*it);
			}else{ // o==3 : 大於等於ｖ的數字中第Ｋ小
				it=pool.lower_bound(v);
				for(K--;0<K and it!=pool.end(); K--)
					it=next(it);
				ans=(it==pool.end())? -1: (*it);
			}
			cout<<ans<<'\n';
		}
	}
}