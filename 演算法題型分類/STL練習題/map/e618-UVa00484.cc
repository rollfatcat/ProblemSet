/* 給定一個數列(測資只有一筆，所以只要讀取到沒有數字即停止)
 * 要求依照輸入的數字順序輸出數列中出現的次數
 * Queen 維護輸入的順序，Map 紀錄對應的數量。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	queue<int> NumMemo;
	map<int,int> CntMemo;
	while(scanf("%d",&num)!=EOF)
		if(CntMemo.find(num)==CntMemo.end())
			CntMemo[num]=1, NumMemo.push(num);
		else
			CntMemo[num]++;
	for(;NumMemo.empty()==0;NumMemo.pop())
		printf("%d %d\n",NumMemo.front(),CntMemo[NumMemo.front()]);
}