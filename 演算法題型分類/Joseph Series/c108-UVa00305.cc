// 題目要找到最小的 確保在殺掉前k個人時號碼在(0,k-1)都不會被殺掉 !!!
// 換句話說每回合被殺掉的人都不可以是隊伍中前面的位置(0,k-1)
// 要找到這回合要殺掉的人在隊伍中的位置(非實際號碼)只需要O(1)
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 14

int main(){

  int ans[MaxN], m, N, t, idx;
  for(int k=1;k<MaxN;k++){
    for(m=k+1, N=k<<1; true; m++){
      // 當殺掉的人是前面也就是(0,k-1), 代表這回合已經失敗, 不可t--
      for(t=N, idx=(m-1)%t; idx>=k and t>k; )
        t--,
        idx=(idx+m-1)%t;
      if(t==k)  break;
    }
    ans[k]=m;
  }
  while(cin>>m and m)
    cout<<ans[m]<<endl;
}
/*
2
7
5
30
169
441
1872
7632
1740
93313
459901
1358657
2504881
*/