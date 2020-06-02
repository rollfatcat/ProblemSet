/* 題目雖然給予高和寬，但寬度似乎是無用的且解題方向和 stack 相關
 * 從左而右掃描依序讀取，碰到高度高於Stack時就推入但低於時要pop()直到空掉或是stack內的內的高度低於輸入
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, x, cnt;
  while(scanf("%d",&N)!=EOF){
    stack<int> S;
    for(cnt=0; N--; ){
      for(scanf("%d %d\n",&x,&x);S.empty()==0 and S.top()>x;S.pop())
        cnt++;
      if(S.empty() or S.top()<x)
        S.push(x);
    }
    printf("%d\n",cnt+S.size());
  }
}