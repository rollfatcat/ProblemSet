/* struct 的練習題：分數的基礎功能：輸出分子分母/約分/加(減)法
 * 題目保證輸入的分數
 * (1) 1 ≤ 分子,分母 ≤ 100 
 * (2) 分數最多５個
 * (3) 運算符號只有＋/−
 * 輸出時分母須保持正數且當分子＝０時分母＝１
 */
#include<bits/stdc++.h>
using namespace std;

struct FRACT{
	int A, B;
	void Reduct(void){
		if(A==0){ B=1; return; }
		int x=__gcd(A,B); if(x<0) x=-x;
		A/=x, B/=x;
	}
	void SetValue(string ss,int idx=0){
		for(A=0;ss[idx]!='\/';idx++)
			A=10*A+ss[idx]-'0';
		for(B=0,idx++;ss[idx]!='\0';idx++)
			B=10*B+ss[idx]-'0';
		Reduct();
	}
	void Print(void){ printf("%d/%d",A,B); }
	void ADD(FRACT &rhs){
		A=A*rhs.B+rhs.A*B;
		B*=rhs.B;
		Reduct();
		
	}
} now, rhs;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string number, opt;
	cin>>number; now.SetValue(number);
	while(cin>>opt>>number){
		rhs.SetValue(number);
		if(opt[0]=='-')
			rhs.A*=-1;
		now.ADD(rhs);
	}
	now.Print();
}
/*
 1/3 - 1/2
 2/4 - 1/2
 */