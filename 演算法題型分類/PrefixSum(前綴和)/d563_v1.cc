// 比較兩個數列(由前往後累加和由後往前累加) 輸出相同值的個數
// 模擬 MergeSort 指標移動方式(只是從同一個陣列的兩端往反向移動)

#include <iostream>
using namespace std;
#define MAXN 100002

int num[MAXN];
int main() {
	int n, cnt=0;
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0,j=n-1,diff=num[i++]-num[j--]; i<=n and j>=-1;){
		if(diff>0)	diff-=num[j--];
		else if(diff<0)	diff+=num[i++];
		else	diff=num[i++]-num[j--], cnt++;
	}
	cout<<cnt<<endl;
}