/* 題目給定一組分數(分子＋分母)，輸出如何根據規則找到該分數的路徑。
 * 規則：模擬初始有左邊界(０/１)，右邊界(１/０)，中間值為該次左右邊界的各自和(分子分母都是直接相加)
 *      根據大於小於的結果收縮邊界，遞迴直到找到為止。
 * 解題關鍵：(偽)二元樹
 * 因為題目敘述詳細的方法，只要實做出來即可，也算是簡單模擬題。
 */
#include<iostream>
using namespace std;

const int MaxN=3e4;
int main(){
	int M, N;
  while(scanf("%d %d\n",&M,&N)!=EOF and (N or M)){
  	int L1=0, L2=1;
  	int R1=1, R2=0;
  	while(true){
  		int M1=L1+R1;
  		int M2=L2+R2;
  		if(M1==M and M2==N){
  			putchar('\n'); break;
  		}
  		if(M1*N>M*M2){
  			putchar('L');
  			R1=M1, R2=M2;
  		}else{
  			putchar('R');
  			L1=M1, L2=M2;
  		}
  	}
  }
}