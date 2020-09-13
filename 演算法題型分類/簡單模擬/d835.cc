/* 給定多行字串當作羽球比賽的輸入，輸出在１１分賽制和２１賽分制下的每場比分
 * 解題關鍵：簡單模擬(每場比賽結束的判斷條件？)
 * 比賽結束的判斷條件：(1)一方先獲得１１/２１分而另一方未得１０/２０分 (2)雙方得分皆高於１０/２０分且分差２分以上
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int A, B, end_score;
	
	vector<string> keep;
	A=B=0; end_score=10;
	for(string ss; cin>>ss; keep.push_back(ss)){
		for(char ch:ss){
			A+= ch=='W';
			B+= ch=='L';
			if( ( A==end_score+1 and B<end_score ) or 
			    ( B==end_score+1 and A<end_score ) or
			    ( abs(A-B)>=2 and A>=end_score and B>=end_score)
			  ){
				cout<<A<<':'<<B<<'\n';
				A=B=0;
			}
		}
	}
	cout<<A<<':'<<B<<'\n'<<'\n';
	
	A=B=0; end_score=20;
	for(string ss:keep)
		for(char ch:ss){
			A+= ch=='W';
			B+= ch=='L';
			if( ( A==end_score+1 and B<end_score ) or 
			    ( B==end_score+1 and A<end_score ) or
			    ( abs(A-B)>=2 and A>=end_score and B>=end_score)
			  ){
				cout<<A<<':'<<B<<'\n';
				A=B=0;
			}
		}
	cout<<A<<':'<<B<<'\n';	
}
