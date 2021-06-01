/* 給定第Ｎ項費波那契數字，輸出整個分解過程(依照深度順序印出，相同的印在同一行)
 * 解題關鍵：Breadth-First Search (BFS)
 */
#include<bits/stdc++.h>
using namespace std;
 
int FIB[16]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
struct NODE{
	int num, depth;
	NODE(int n=0,int d=0):num(n),depth(d){}
} ;
int main(){
	int N;
 
	while(scanf("%d\n",&N) and N>0){
		queue<NODE> Q;
		Q.push(NODE(N,0));
		for(int Depth=0; Depth<N; Depth++){
			while(Q.empty()==0 and Q.front().depth==Depth){
				printf("f(%d) ",Q.front().num);
				if(Q.front().num>=2)
					Q.push( NODE(Q.front().num-1,Q.front().depth+1) ),
					Q.push( NODE(Q.front().num-2,Q.front().depth+1) );
				else
					Q.push( NODE(Q.front().num,Q.front().depth+1) );
				Q.pop();
			}
			putchar('\n');
		}
		printf("f(%d) = %d\n\n",N,FIB[N]);
	}
}