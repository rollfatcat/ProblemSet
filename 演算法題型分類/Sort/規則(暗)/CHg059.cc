// QSort 練習
#include<iostream>
#include<cstdlib>
using namespace std;
#define MaxN 10000

struct Line{
  int st, dis;
} lines[MaxN];
int compare(const void*a, const void*b){
  struct Line *c=(Line*)a;
  struct Line *d=(Line*)b;
  return (c->dis==d->dis)?(c->st-d->st):(c->dis-d->dis);
}
int main(){
  int T, N, lineNum, pre, now;
  cin>>T;
  while(T--){
    cin>>N>>pre;
    lineNum=N-1;
    for(int i=0;i<lineNum;i++,pre=now){
      cin>>now;
      lines[i].st=i+1;
      lines[i].dis=now-pre;
    }
    qsort(lines,lineNum,sizeof(lines[0]),compare);
    int idx=lineNum-1;
    while(lines[idx].dis==lines[idx-1].dis)
      idx--;
    cout<<lines[idx].st<<endl;
  }
}