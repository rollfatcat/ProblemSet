/* 給定數個三角形和對應的數字代表屬於三點的總和，依照字典序輸出１-１０填入五芒星上的點並符合所有條件的解答？
 * 這些條件的輸入條件為EOF且條件不會彼此衝突。
 * 解題關鍵：next_permatation＋BruteForce
 * 依字典序暴力法決定填入１０個空格，確認符合所有條件後輸出該順序。
 */
#include<bits/stdc++.h>
using namespace std;
 
char ch, ss[5];
int bound[9][4];
 
int main(){
	int N;
	/* input */
    for(N=0;scanf("%s %c %d\n",ss,&ch,&bound[N][3])!=EOF;N++)
		bound[N][0]=ss[0]-'A',
		bound[N][1]=ss[1]-'A',
		bound[N][2]=ss[2]-'A';
    /* algorithm 的 next_permatation() 實作依照字典序的排列 */
	vector<int> bag={1,2,3,4,5,6,7,8,9,10};
	do{
		int ac=0;
		for(int i=0;i<N;i++)
			ac+=bag[bound[i][0]]+bag[bound[i][1]]+bag[bound[i][2]] ==bound[i][3];
		if(ac==N)
			printf("%d %d %d %d %d %d %d %d %d %d\n",bag[0],bag[1],bag[2],bag[3],bag[4],bag[5],bag[6],bag[7],bag[8],bag[9]);
	}while(next_permutation(bag.begin(),bag.end()));
}