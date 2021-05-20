/* 經典歷題：N x M 盤面上詢問最少的關燈次數讓盤面全部都是熄燈
 * 表面是每個燈有開和關2種選項，所有的選擇是2^(NxM)，實際上是2^N
 * 關鍵是由上往下開始選擇，(i-1)th Row 最終只會被 ith 開關影響，並且是讓(i-1)th Row全部燈滅的操作
 * 當 1st Row狀態決定整個盤面就決定好了
 * (1) 1st Row 枚舉+位运算，搜索全部解，即以下的寫法，尋找最後一個『亮著』的燈可以改為狀態壓縮方式
 * https://blog.csdn.net/MHL_1208980380/article/details/54618002
 * (2) 線性代數解法：高斯消去 做XOR運算(燈的狀態只有0/1，模擬加法時的位元運算就是XOR)
 * https://blog.csdn.net/mhl_1208980380/article/details/54889018
 */
#include <bits/stdc++.h>
using namespace std;
#define oo 1<<30
struct data_map{
  int L[5]={1, -1, 0, 0, 0};
	bool mp[12][12];
	int C(int l, int s){
		for(int i=1;i<11;i++)
		  if(mp[l-1][i]){
		    s++;
			  for(int j=0;j<5;j++)
			    mp[ l+L[j] ][ i+L[4-j] ]^=1;
		  }
		if( l==10 ){
			for(int i=1;i<11;i++)
			  if(mp[10][i])
			    return oo;
			return s;
		}
		return C(l+1,s);
	}
	int D(int l, int s){
	  // 複製一個，並且對該物件的(1,l)的燈按下去
		data_map y = *this;
		for(int i=0;i<5;i++)
		  y.mp[ 1+L[i] ][ l+L[4-i] ]^=1;
		if( l==10 )
		  return min( C(2,s), y.C(2,s+1) );
		else
		  return min( D(l+1,s), y.D(l+1, s+1) );
	}
};
int main(){
	int t;
	for(cin>>t;t--;){
		string L[12];
		data_map m;
		for(int i=1;i<11;i++)
		  cin>>L[i];
		for(int i=1;i<11;i++)
		  for(int j=1;j<11;j++)
		    m.mp[i][j]=L[i][j-1]-'#';
		cout<<m.D(1,0)<<endl;
	}
}
/*
3
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
*/