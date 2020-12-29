/* 給定深度Ｄ和次數Ｋ，球會依據「規則」決定每次向左或向右，輸出最後球的落點號碼？
 * 移動規則：球會從 root (１號節點)向葉節點移動，每次移動時會根據目前節點被拜訪過的次數決定(偶數向左，奇數向右)
 * 題目盲點：為了判斷第Ｋ次的球移動時必須要知道所有節點被拜訪的次數？ ... 只需要知道移動路徑上的所有節點被拜訪次數
 * 解題關鍵：Divide & Conquer
 * Stop Condition : 抵達葉節點時回傳目前累加的數值
 * Subproblem to problem : 每次往下時號碼會翻倍，而往右時能再多贏一個
 */
#include<bits/stdc++.h>
using namespace std;
 
int DCQ(int depth,int count,int v){
	if(depth==1)// 抵達葉節點，沒有路徑可以再往下移動：回傳目前的編號
    return v;
	return DCQ(depth-1,count>>1,(v<<1)+(count&1) );
}
int main(){
  int caseT, depth, count;
 
  scanf("%d\n",&caseT);
  while(caseT-->0){
    scanf("%d %d\n",&depth,&count);
    printf("%d\n",DCQ(depth,count-1,1));
  }
}