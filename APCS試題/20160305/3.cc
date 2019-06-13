#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXsize 10000
struct Line{
  int st, ed;
} lines[MAXsize];
int compare(const void*a, const void *b){
  struct Line* x= (Line*)a;
  struct Line* y= (Line*)b;
  return (x->st==y->st)?(x->ed-y->ed):(x->st-y->st);
}
int main(void){
  int N, ed, total;
  int idx_lines[MAXsize], num_lines;
  while(cin>>N){
    for(int i=0;i<N;i++)
      cin>>lines[i].st>>lines[i].ed;
    qsort(lines,N,sizeof(lines[0]),compare);
    num_lines=0;
    for(int i=0;i<N;){
      idx_lines[num_lines]=i;
      for(ed=lines[i].ed; i<N and lines[i].st<=ed; i++)
        if(ed<lines[i].ed)
          ed=lines[i].ed;
      lines[idx_lines[num_lines++]].ed=ed;
    }
    total=0;
    for(int i=0;i<num_lines;i++)
      //cout<<lines[idx_lines[i]].st<<','<<lines[idx_lines[i]].ed<<endl;
      total+=(lines[idx_lines[i]].ed-lines[idx_lines[i]].st);
    cout<<total<<endl;
  }
}