/* 依照規定排序
 */
#include<iostream>
#include<algorithm>
using namespace std;

struct nn{ int sum, no, score; } student[300];
bool compare(nn a,nn b){
  if(a.sum!=b.sum) return a.sum>b.sum;
  return (a.score==b.score)?(a.no<b.no):(a.score>b.score);
}
int main(){
  for(int n; cin>>n; ){
    for(int i=0, l,m,e;i<n;i++)
      cin>>l>>m>>e,
      student[i].no=i+1,
      student[i].sum=l+m+e,
      student[i].score=l;
    sort(student,student+n,compare);
    for(int i=0;i<5;i++)
      cout<<student[i].no<<' '<<student[i].sum<<endl;
  }
}