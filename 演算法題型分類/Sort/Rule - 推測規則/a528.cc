/* 大數(字串)排序
 * (1) 正數一定比負數大
 * (2) 字串長度
 * (3) 直接比字串
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
string number[MaxN];

bool Smaller(string& a,string& b){
	if(a[0]=='-' ^ b[0]=='-') return a[0]=='-';
	
  bool nagtive= a[0]=='-';
	if(a.length()!=b.length()) 
		return nagtive? a.length()>b.length(): a.length()<b.length();
	return nagtive? a>b: a<b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N;
	while(cin>>N){
		for(int i=0;i<N;i++)
			cin>>number[i];
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++)
				if( Smaller(number[j],number[i]) )
					swap(number[j],number[i]);
			cout<<number[i]<<'\n';
		}
	}
}