/* 寺廟設計的系統中不包含位數４的號碼，請設計轉換機制，輸入Ｔ時可以將"正常號碼"轉為"寺廟號碼"，Ｆ則反之。
 * 解題核心：寺廟系統＝不包含位數４的９進位制轉換，正常號碼為 10 進位制
 * ９進位制 > 10 進位制 : 輸入時以字串讀取，便於把每個"位數"拆下來計算
 * ９進位制 < 10 進位制 : 輸入時以數字讀取，便於算每個"位數"(模９的餘數)
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxN=1e15;
// 給定９進位轉為 10 進位(注意給定的位數如果大於４，都要-1) ...
long NineToTen(string v){
	long ans=0;
	for(char c: v)
		ans=ans*9+c-(c>'4')-'0';
	return ans;
}
// 給定 10 進位轉為９進位(因為不存在４注意算出的位數如果大於3，都要+1)
string TenToNine(long v){
	string ss="";
	for(; v>0; v/=9)
    ss=(char)(v%9+(v%9>=4)+'0')+ss;
  return ss;
}
// 核心： 不存在 4 的 10 進位制 = 9進位制
int main(){
	// 題目時間卡在 0.3 s，必須加速讀取
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	char type;
	string num_s;
	long num_v;
	
	while(cin>>type){
		if(type=='F'){
			cin>>num_s; // ９進位制 > 10 進位制 : 輸入時以字串讀取，便於把每個"位數"拆下來計算
			cout<<NineToTen(num_s)<<'\n';
		}else{ // type=='T'
			cin>>num_v; // ９進位制 < 10 進位制 : 輸入時以數字讀取，便於算每個"位數"(模９的餘數)
			cout<<TenToNine(num_v)<<'\n';
		}
	}
}