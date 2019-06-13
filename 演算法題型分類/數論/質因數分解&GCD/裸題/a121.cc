// 搜尋的範圍到達1e8, 沒辦法先存起來查表
// 需要1e4內的1229個質數
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MaxN 10001

int PrimeCheck;
vector<int>PrimeTable;
vector<bool>CheckPrime(MaxN,1);
bool isPrime(int x){
  if(x<MaxN)  return CheckPrime[x];
  int i=0;
  while(i<PrimeCheck and x%PrimeTable[i]) i++;
  return i==PrimeCheck;
}
int main(){
	CheckPrime[0]=CheckPrime[1]=0;
	PrimeTable.push_back(2);
	for(int j=4; j<MaxN; j+=2)
		CheckPrime[j]=0;
	int bound=sqrt(MaxN);
	for(int i=3;i<=bound;i+=2)
		if(CheckPrime[i]){
			PrimeTable.push_back(i);
			for(int k=i<<1, j=i+k; j<MaxN; j+=k)
				CheckPrime[j]=0;
		}
	for(int i=bound+1;i<MaxN;i+=2)
	  if(CheckPrime[i])
			PrimeTable.push_back(i);
	PrimeCheck=PrimeTable.size();

	int a, b;
	while(cin>>a>>b){
	  int cnt=0;
	  for(int idx=a;idx<=b;idx++)
      cnt+=isPrime(idx);
    cout<<cnt<<endl;
	}
}