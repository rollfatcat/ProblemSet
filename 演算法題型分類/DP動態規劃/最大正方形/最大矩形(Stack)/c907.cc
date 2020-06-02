/* Histogram找到最大矩形面積，可類推到『尋找最大矩陣』
 * http://www.csie.ntnu.edu.tw/~u91029/MaximumSubarray.html#2
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int hgt[MaxN];

int main(){
	for(int C;scanf("%d\n",&C)!=EOF;){
		for(int i=0;i<C;i++)
			scanf("%d",&hgt[i]);
		
		int maxRec=0, prev;
		stack<int> S;
		for(int j=0;j<C;j++){
			for(prev=j;S.empty()==0 and hgt[S.top()]>hgt[j];S.pop())
				prev=S.top(),
				maxRec=max(maxRec,hgt[S.top()]*(j-prev));
			S.push(prev);
			hgt[prev]=hgt[j];
		}
		for(;S.empty()==0 and hgt[S.top()]>0;S.pop())
			maxRec=max(maxRec,hgt[S.top()]*(C-S.top()));
		printf("%d\n",maxRec);
	}
}