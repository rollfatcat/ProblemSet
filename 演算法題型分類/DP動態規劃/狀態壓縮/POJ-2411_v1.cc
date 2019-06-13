// 參考鏈結：https://blog.csdn.net/hopeztm/article/details/7841917
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX_ROW 12
#define MAX_STATUS 2048
long long DP[MAX_ROW][MAX_STATUS];
int g_Width, g_Height;

bool TestFirstLine(int nStatus){  //test the first line
	for(int i=0; i<g_Width; ){
		if(nStatus & (1<<i)){
			if( i==g_Width-1 || (nStatus & (1<<(i+1)))==0)
				return false;
			i+=2;
		}
		else
			i++;
	}
	return true;
}

// test if status (i, nStatusA) and (i-1, nStatusB) is compatable.
bool CompatablityTest(int nStatusA, int nStatusB){
	for(int i=0; i<g_Width; ){
		if((nStatusA & (1<<i))==0){
			if((nStatusB & (1<<i))==0){
				return false;
			} else
			i++;
		} else { //(nStatusA & (1<<i))=1
			if((nStatusB & (1<<i))==0){
				i++;
			} else if( (i==g_Width-1) || ! ( (nStatusA & (1<<(i+1))) && (nStatusB & (1<<(i+1)) )) ){
				return false;
			} else {
				i+=2;
			}
		}
	}
	return true;
}

int main(){
	int i, j, k;
	while(scanf("%d%d", &g_Height, &g_Width) != EOF ){
		if(g_Width==0 && g_Height==0)
			break;
		if(g_Width>g_Height)
			swap(g_Width, g_Height);

		int nAllStatus = 2<<(g_Width-1);
		memset(DP,0,sizeof(DP));
		for( j=0; j<nAllStatus; j++)
			if(TestFirstLine(j))
				DP[0][j]=1;
    // 可以改善的點是上下狀態相容的關係應該只要跑一次就知道
		for( i=1; i<g_Height; i++)
			for( j=0; j<nAllStatus; j++)// iterate all status for line i
				for( k=0; k<nAllStatus; k++)// iterate all status for line i-1
					if( CompatablityTest(j,k) )
						DP[i][j]+=DP[i-1][k];
		printf("%lld\n", DP[g_Height-1][nAllStatus-1]);
	}
}
