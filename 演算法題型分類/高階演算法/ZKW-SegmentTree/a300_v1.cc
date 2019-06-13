// DP題解(15ms)：https://www.jianshu.com/p/53155318cd26?
// 解法的概念類似：c412，以下是最佳解且不需要線段樹維持區間的最小值確保題目的條件
/* 当找到一个旅店在右边，若是其左边有一个符合要求的咖啡店，那么再往左边看，
 * 如果有一个颜色相同的旅店，那么就算是一种住宿方法了，那么如果以这个右边的旅店作为对应点，
 * 将所有在左边而且颜色与之相同的旅店数相加，就能得出很多种住宿方法了。
 * 那么用这个办法，用所有的对应点对应过去，就能最快的时间内找出所用的酒店了。
 * a数组是记录同一种颜色中的酒店所出现的最后一次的位置；
 * b数组记录同一种颜色的酒店的出现次数，
 * 而c数组则是临时记录当前同样颜色的酒店出现的次数，也就是为找对应点而进行的临时记录
 */
#include<bits/stdc++.h>
using namespace std;

int n, k, p, m, ans;
int last_pos[200010];
int hotal_num[200010];
int tmp_num[200010];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, K, P, m;

  scanInt(N),
  scanInt(K),
  scanInt(P);
  for(int i=1; i<=N; i++){
    int k, q;
    scanInt(k),
    scanInt(q);
    if(q<=P)//如果咖啡店的最低消费地于标准，那么记录其位置
      m=i;
    if(m>=last_pos[k])//如果在当前颜色的酒店之前有出现过同样颜色的酒店那么记录当前同种颜色的酒店的出现次数
      tmp_num[k]=hotal_num[k];
    last_pos[k]=i;   //记录同样颜色的酒店最后一次的出现位置
    ans+=tmp_num[k];//每一个酒店都可以作为对应点，所以不需要再去加上任何的判断，记录住宿的方法
    hotal_num[k]++;   //记录出现次数的总数
  }
  printf("%d\n",ans);
}
/*
5 2 3
1 5
1 3
1 2
1 4
1 5
===
9
*/