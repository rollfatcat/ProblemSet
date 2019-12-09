// d478 的進階題: 題目說明兩個數列是經過排序,但不一定是由小到大,也可是大到小
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int X[MaxN], Y[MaxN]; // 1 ≤ Xi,Yi ≤ 1e5
int main() {
	for(int Na,Nb; scanf("%d %d\n",&Na,&Nb) and Na; ){
		for(int i=0;i<Na;i++)
			scanf("%d",&X[i]);
		for(int i=0;i<Nb;i++)
			scanf("%d",&Y[i]);
		// unique
		int Nx=0, Ny=0;
		for(int i=1;i<Na;i++)
			if(X[Nx]!=X[i])
				X[++Nx]=X[i];
		for(int i=1;i<Nb;i++)
			if(Y[Ny]!=Y[i])
				Y[++Ny]=Y[i];
		// 找出 #共同數字
		int cnt=0;
		for(int i=0,j=0;i<=Nx and j<=Ny;)
			if(X[i]<Y[j]) i++;
			else if(X[i]>Y[j]) j++;
			else cnt++, i++, j++;
		printf("%d\n",min(Nx,Ny)-cnt+1);
	}
}

