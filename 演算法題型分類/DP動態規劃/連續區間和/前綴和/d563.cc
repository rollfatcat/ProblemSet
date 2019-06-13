// 比較兩個數列(由前往後累加和由後往前累加) 輸出相同值的個數
#include <iostream>
using namespace std;
#define MaxN 100002

int main() {
	int n, num[MaxN], presum[MaxN]={0};

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i], 
		presum[i]=presum[i-1]+num[i];
	int cnt=0, suffsum=0;
	for(int i=1, j=1; i<=n and j<=n;i++){
		suffsum+=num[n+1-i];
		while(j<=n and suffsum>presum[j])
		    j++;
		if(j<=n and suffsum==presum[j])
		    cnt++;
	}
	cout<<cnt<<endl;
}