// 需要大數加速運算( 過程中只會有單位的乘法所以 base 可以高達 1e17 )
// struct 的大數自定義函數中分為是不是運算式覆蓋問題： 假設是 const 時內部自定義的參數是 read-only
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4345279
/* 首先要抓出數列的規律和推導：證明對於任意正整數 N 皆可以找到唯一的，每一位都是奇數且可以被5^N 整除的正整數
 * 假設我們已知 Ｎ=ｋ 的答案，並假定為其值為 Pk × 5^k ，其中 Pk 為一正整數。
 * 而當 N=k+1 時，Pk+1 × 5^(k+1) =  q × 10^k + Pk × 5^k，其中 q={1,3,5,7,9} 其中一個數字。原因如下：
 * 將上述等式簡化為：Pk+1=(q × 2^k + Pk)÷5。所以我們要找到一個整數 q 滿足 q × 2^k + Pk 模5的餘數為0。
 * 而 Pk 模5的餘數的可能值為 0-4 全部包含，但是 2^k 的可能值只有 1-4。且我們 q 的範圍模5的餘數分別為1, 3, 0, 2, 4。
 * 因此，對於任意可能的 2^k、Pk 的值，我們皆可以找到一個（且唯一一個）奇數 q 符合上式。
 * 從以上的證明我們可以看到：不會有需要輸出「-1」或是從多組解之中找出最小解的情況發生（畢竟是唯一解）。
 * 且 N = k+1 的解之末k位數即是 N=k 的解。我們可以利用大數運算，持續更新出 2^k 和上面提及過的 Pk 的值，來求出新的 q 值和 Pk+1。
 * 而把所有求過的 q 值串成一個字串，即 N=55555 的答案，而末 ｋ 位數的數字即為 N=k 的解。
 */

#include<bits/stdc++.h>
using namespace std;

const long base=1e17;
string ans="5";

struct BigInt{
  int len=0;
  long num[1000]={};
  BigInt(){}
  BigInt(const int x){ num[len++]=x; } // 預設初始化的時候只有一個位數

  void operator=(const BigInt &rhs){
    len=rhs.len;
    for(int i=0;i<len;i++)
      num[i]=rhs.num[i];
  }
  bool operator<(const BigInt &rhs)const{
    if(len!=rhs.len) return len<rhs.len;
    for(int i=len-1;i>=0;i--)
      if(num[i]!=rhs.num[i])
        return num[i]<rhs.num[i];
    return false;
  }
  void operator+=(const BigInt &rhs){
		while(len<rhs.len)
			num[len++]=0;
		long carry=0;
		for(int i=0; i<len; i++)
		  num[i]+=rhs.num[i]+carry,
		  carry=num[i]/base,
		  num[i]%=base;
		if(carry) num[len++]=carry;
	}
  void operator*=(const int scale){ // 單位數乘法
    long carry=0;
    for(int i=0;i<len;i++)
      num[i]=num[i]*scale+carry,
      carry=num[i]/base,
      num[i]%=base;
    if(carry) num[len++]=carry;
  }
  BigInt operator+(const BigInt &rhs)const{ // 兩個大數加法
    if(*this<rhs) return rhs+*this;
    BigInt out=*this;
		long carry=0;
		for(int i=0; i<rhs.len; i++)
			out.num[i]=num[i]+rhs.num[i]+carry,
			carry=out.num[i]/base,
			out.num[i]%=base;
		for(int i=rhs.len; i<len; i++)
			out.num[i]=num[i]+carry,
			carry=out.num[i]/base,
			out.num[i]%=base;
		if(carry)
		  out.num[out.len++]=carry;
		return out;
  }
	BigInt operator/(const int scale){ // 單位數除法
		long carry=0;
		for(int i=len-1; i>=0; i--)
			carry=carry*base+num[i],
			num[i]=carry/scale,
			carry%=scale;
		while(len and num[len-1]==0)
		  len--;
		return *this;
	}

	void PrintNum(){
    printf("%ld",num[len-1]);
    for(int i=len-2;i>=0;i--)
      printf("%017ld",num[i]);
    putchar('\n');
	}
}P2n, rem, buff;

int main(){
  // 初始化
  rem=BigInt(1);
  P2n=BigInt(2);
  // 估算最高的位數後加到答案中
  for(int guess,turn=2;turn<=55555;turn++){
    buff=P2n+rem;
    P2n*=2;
    for(guess=1; buff.num[0]%5; buff+=P2n, guess+=2); // 估算現在的最高位數
    ans=(char)(guess+'0')+ans;
    rem=buff/5;
  }
  // 輸出強迫使用 putchar()，使用cin/cout會TLE
  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    for(int i=55555-N;i<55555;i++)
      putchar(ans[i]);
    putchar('\n');
  }
}