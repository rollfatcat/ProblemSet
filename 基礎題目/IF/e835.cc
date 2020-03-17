/* 給定座位號碼，輸出該號碼屬於哪一區？哪排的哪個位置？
 * 第一區和第三區皆2500人，每排25人。第二區5000人，每排50人。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int BlockSz[3]={0,2500,7500};
int one_row[3]={25,50,25};
int main(){
	for(int N,block;scanf("%d\n",&N)!=EOF;){
		block=(N<=BlockSz[1])? 0: (N>BlockSz[2])? 2 :1,
		N-=BlockSz[block]+1;
		printf("%d %d %d\n",block+1,N/one_row[block]+1,N%one_row[block]+1);
	}
}