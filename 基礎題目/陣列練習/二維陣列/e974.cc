/* 給定教室的Ｒ×Ｃ後( 初始的座位號碼 )和需要換位Ｎ次
 * 單數週＝每個Row的號碼往後一格，偶數週＝每個Column的號碼往右一格
 * 第一週時是初始座位，第二週之後依照上述規則移動。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=100;
const int MaxC=100;
const int MaxN=100;

int num[2][MaxR][MaxC];
int main(){
	for(int R,C,N;scanf("%d %d %d\n",&R,&C,&N)!=EOF;){
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				num[0][i][j]=i*C+j+1;
		int pre=0, now=1;
		for(int k=2;k<=N;k++,swap(pre,now)){
			if(k&1){ // 單數週：所有人往後移一個座位
				for(int i=0;i<R-1;i++)
					for(int j=0;j<C;j++)
						num[now][i+1][j]=num[pre][i][j];
				for(int j=0;j<C;j++)
					num[now][0][j]=num[pre][R-1][j];
			}else{ // 雙數週：所有人往右橫移一個座位
				for(int i=0;i<R;i++)
					for(int j=0;j<C-1;j++)
						num[now][i][j+1]=num[pre][i][j];
				for(int i=0;i<R;i++)
					num[now][i][0]=num[pre][i][C-1];
			}
		}
		for(int i=0;i<R;i++,putchar('\n'))
			for(int j=0;j<C;j++)
				printf("%d ",num[pre][i][j]);
	}
}

