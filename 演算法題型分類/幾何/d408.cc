// 幾何 => P點是該三角形的重心，給邊長求重心=>中線定理
// 證明：https://www.itsfun.com.tw/%E4%B8%89%E8%A7%92%E5%BD%A2%E4%B8%AD%E7%B7%9A%E5%AE%9A%E7%90%86/wiki-4886565-8178145
/* 題解：https://home.gamer.com.tw/creationDetail.php?sn=4224014
 * 給3邊長問P點到3頂點的距離平方和最小化 => 自己推導時可以固定一點在原點 另一點落在X軸
 * 配方後最小化即是答案
 */
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  for(int N; scanf("%d",&N) and N; )
    for(double a,b,c; N--; ){
      scanf("%lf %lf %lf",&a,&b,&c);
			double mc2=(a*a+b*b-c*c/2)/2;
			double mb2=(a*a+c*c-b*b/2)/2;
			double ma2=(c*c+b*b-a*a/2)/2;
			printf("%.1lf\n", (ma2+mb2+mc2)*4/9.0);
    }
}