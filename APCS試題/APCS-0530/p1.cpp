#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int num[MaxN+1];
int mis[MaxN+1];

int main(){
	int N, v;
	scanf("%d",&N);
	for(int i=1;i<=N;i+=1){
		scanf("%d",&num[i]);
		mis[ num[i] ]=i;
	}
	int dis=-1;
	int ID=-1;
	for(int i=1;i<=N;i+=1)
		if(abs(num[i]-mis[i])>dis){
			dis=abs(num[i]-mis[i]);
			ID=i;
		}
	printf("%d %d\n",dis,ID);
}