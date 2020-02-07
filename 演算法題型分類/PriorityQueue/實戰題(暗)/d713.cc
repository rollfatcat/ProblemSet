/* c010-uva10107的加強版:輸入的數量由1e4🔝2e5個
 * 題解：https://www.ptt.cc/bbs/Prob_Solve/M.1345237843.A.E5C.html
 * priorty_queue(49ms) 有太多elements時速度會降太多
 * 分成兩個priorty_queue(qL+qR)且qL和qR接在一起時就是一個完整的priorty_queue
 * qL是由大到小而qR是小到大的順序
 */
#include<bits/stdc++.h>
using namespace std;

struct COMPL{ bool operator()(const int& lhs, const int& rhs){ return lhs<rhs; }};
struct COMPR{ bool operator()(const int& lhs, const int& rhs){ return lhs>rhs; }};
priority_queue<int, vector<int>, COMPL> qL;
priority_queue<int, vector<int>, COMPR> qR;
static inline int gc() {
  static char buf[1 << 20], *p = buf, *end = buf;
  if (p == end) {
    if ((end = buf + fread(buf, 1, 1 << 20, stdin)) == buf) return EOF;
    p = buf;
  }
  return *p++;
}
template<typename T>
static inline bool gn(T &_){
  register int c = gc(); register T __ = 1; _ = 0;
  while(!isdigit(c) and c!=EOF and c!='-') c = gc();
  if(c == '-') { __ = -1; c = gc(); }
  if(c == EOF) return false;
  while(isdigit(c)) _ = _ * 10 + c - '0', c = gc();
  _ *= __;
  return true;
}
template <typename T, typename ...Args>
static inline bool gn(T &x, Args& ...args){return gn(x) and gn(args...);}
int main() {

  int qL_cnt=0, qR_cnt=0;
  for(int num; gn(num);){
    /* 當兩邊的Heap一樣多時，讓qL多一個element
     * 判斷 qR是不是空掉 或者 輸入的數字小於qR最小的數字，假若成立則直接推入qL
     * 否則取出qR最小的數字推入qL並且將輸入的數字推入qR
     */
    if(qL_cnt==qR_cnt){
      qL_cnt++;
      if(qR.empty() or num<qR.top())
        qL.push(num);
      else
        qL.push(qR.top()),
        qR.pop(),
        qR.push(num);
      printf("%d\n",qL.top());
    }else{
      /* 當qL多一個element時
       * 判斷 輸入的數字大於等於qR最小的數字，假若成立則直接推入qR
       * 否則取出qL最小的數字推入qR並且將輸入的數字推入qL
       */
      qR_cnt++;
      if(qL.top()<=num)
        qR.push(num);
      else
        qR.push(qL.top()),
        qL.pop(),
        qL.push(num);
      printf("%d\n",(qL.top()+qR.top())>>1);
    }
  }
}