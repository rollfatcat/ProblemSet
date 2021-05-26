/* 利用陣列實現 Queue 資料結構 */
#include<bits/stdc++.h>
using namespace std;
 
int Queue[100000];
int main() {
	int front=0, rear=0;
	int N, act, x;
 
	for(scanf("%d",&N);N--;){
		scanf("%d",&act);
		if(act==1)
			scanf("%d",&x),
			Queue[rear++]=x;
		else if(act==2)
			printf("%d\n",(front==rear)?-1:Queue[front]);
		else{
			if(rear>front) 
				front++;
		}
	}
}