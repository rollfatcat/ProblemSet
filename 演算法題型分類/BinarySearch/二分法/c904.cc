// 二分法：最大化平均值
// 題解：https://blog.csdn.net/m0_37846371/article/details/73321853
/* 实际上，对于这个问题使用二分搜索法可以很好地解决。我们定义：
 * C(x):=可以选择使得单位重量的价值不小于x
 * 因此，原问题就变成了求满足C(x)的最大的x。假设我们选了某个物品的集合S，
 * 那么它们的单位重量的价值是：∑v[i]/∑w[i]（i∈S），
 * 因此就变成了判断是否存在S满足下面的条件∑v[i]/∑w[i]（i∈S）>=x，
 * 把这个不等式进行变形就得到∑(v[i]-x*w[i])>=0，因此，可以对(v[i]-x*w[i])的值进行排序贪心地进行选取。
 * 因此就变成了C(x)=(v[i]-x*w[i])从大到小排列中的前k个的和不小于0
 */
/* 收斂的方式有兩種
 * (1) train固定的回合數，和 ESP無關(和時間有關)
 * (2) 定收斂條件：r-l>=esp，注意esp和題目要求的精準度相關(需要人為調整)
 */
#include<bits/stdc++.h>
using namespace std;
// 精準度最好預留一位，題目是對小數點第2位四捨五入，第3位會有影響性，所以最低的精準度要訂到e-4
#define esp 1e-4

int N, K, w[1000], v[1000];
double val[1000], sum;
bool test(double d){
  for(int i=0;i<N;i++)
    val[i]=v[i]-d*w[i];
  sort(val,val+N);
  sum=0.0;
  for(int i=0;i<K;i++) //只要最大的前M個加總大於0即可
    sum+=val[N-1-i];
  return sum>=0.0;
}
int main(){

  for(int M;scanf("%d %d",&N,&M)==2;){
    double maxD=0.0, minD=100000000.0, tmpD;
    for(int i=0;i<N;i++){
      scanf("%d %d",&w[i],&v[i]);
      tmpD=v[i], tmpD/=w[i];
      if(tmpD>maxD) maxD=tmpD;
      if(tmpD<minD) minD=tmpD;
    }

    while(M--){
      scanf("%d",&K);
      // 左右邊界一定是性價比最低和最高(快速收縮)
      double l=minD, r=maxD, m;
      while(r-l>=esp){
        m=(l+r)/2;
        if(test(m)) l=m;
        else r=m;
      }
      printf("%.2lf\n",m);
    }
  }
}