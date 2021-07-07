/*
    CodeForces 560C	Gerald's Hexagon
    题意：顺时针的给定六边形的六条边,问六边形由多少个边长为1的正三角形构成
    类型：思维
    分析：正向去数比较苦难,但我们很容易发现的是,边长为a的正三角形,由a*a个
          边长为1的正三角形构成,通过这个性质,我们就可以往六边形的三个角进行
          补三角形,把六边形补成正三角形,再减去补的三角形个数就是答案
*/
#include<iostream>
using namespace std;

int main(){
  int a,b,c,d,e,f;
  while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
    printf("%d\n",(a+b+c)*(a+b+c)-a*a-c*c-e*e);
}