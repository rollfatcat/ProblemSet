// 題目雖然給予高和寬，但寬度似乎是無用的且解題方向和 stack 相關
/* 從左而右掃描依序讀取，碰到高度高於Stack時就推入但低於時要pop()直到空掉或是stack內的內的高度低於輸入
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, x;
  while(scanf("%d",&N)!=EOF){
    stack<int> store;
    int cnt=0;
    for(int i=0;i<N;i++){
      scanf("%d",&x);
      if(x==0) continue; // 沒有惡性測資(寬度=0)時高度沒有意義
      scanf("%d",&x);
      while(store.empty()==0 and x<store.top())
        store.pop(),
        cnt++;
      if(store.empty() or x>store.top())
        store.push(x);
    }
    printf("%d\n",cnt+store.size());
  }
}