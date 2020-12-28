/* 給定產生圖形的第一個正方形邊長ｗ和某個座標，求該座標座落在幾個正方形內？
 * 若座標落在正方形邊上視同處於該正方形內。
 * 圖形產生規則：
 * 第一個正方形的中心點在(1024,1024)且邊長為２ｗ+1，
 * 之後依照四個角落為新的中心點產生邊長為第一個正方形的一半，之後依此類推直到邊長＝1。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxW=1<<9;
struct NODE{
	int x, y;
	NODE(int x=1<<10,int y=1<<10):x(x),y(y){}
	bool operator==(const NODE &rhs)const{ 
		return x==rhs.x and y==rhs.y; }
} ed, now;

int main(){
	int w, cnt;
  while(scanf("%d %d %d\n",&w,&ed.x,&ed.y) and w){
  	if(ed.x<=1024-(w<<1) or 1024+(w<<1)<= ed.x or
  	   ed.y<=1024-(w<<1) or 1024+(w<<1)<= ed.y){
  		puts("  0"); continue;
  	}
  	for(cnt=0,now=NODE(); w>0; w>>=1){
  		cnt+= now.x-w<=ed.x and ed.x<=now.x+w and 
  		      now.y-w<=ed.y and ed.y<=now.y+w;
  		if(now==ed) break;
  		now.x=(ed.x<now.x)? now.x-w : now.x+w;
  		now.y=(ed.y<now.y)? now.y-w : now.y+w;
  	}
  	printf("%3d\n",cnt);
  }
}