#include<bits/stdc++.h>
using namespace std;

int PrimeDay[]={103,107,113,223,307,313,317,503,523,607,613,617,823,907,1013,1103,1223};
vector<int>prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73};

inline bool Judge(int Y,int MD){ 
	if(Y==0) return true;
	int num=Y*10000+MD;
	for(int p:prime)
		if(num%p==0)
			return false;
	return true;
}
int main(){
	// 考量到『最大的日期』29991231，建表上限5476
	int bound=sqrt(29991231);
	vector<bool> IsPrime(bound+1,true);
	for(int p:prime)
		for(int j=2;p*j<=bound;j++)
			IsPrime[p*j]=0;
	for(int i=79;i<=bound;i+=2)
		if(IsPrime[i])
			prime.push_back(i);
	//
	for(int year=2000;year<=2999;year++)
		for(int MonthDay:PrimeDay)
			if(Judge(year,MonthDay) and Judge(year%10,MonthDay) and Judge(year%100,MonthDay) and Judge(year%1000,MonthDay))
				printf("%d\/%02d\/%02d\n",year,MonthDay/100,MonthDay%100);
}