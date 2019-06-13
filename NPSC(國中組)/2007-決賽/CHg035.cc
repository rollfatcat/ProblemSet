#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
struct player{
  string name;
  string pb;
  int sc1;
  int sc2;
  double sc3;
}mvp[1000];

int compare(const void*a, const void*b){
  player*c=(player*)a;
  player*d=(player*)b;
  if(c->pb==d->pb){
    if(c->sc1 == d->sc1){
      if(c->sc2 == d->sc2){
        if(c->sc3 == d->sc3){
          return 0;
        }
        return (c->sc3 > d->sc3)?-1:1;
      }
      return (c->sc2 > d->sc2)?-1:1;
    }
    return (c->sc1 > d->sc1)?-1:1;
  }
  return (c->pb=="P")?-1:1;
}

int main(){
  int len;
  int times;
  cin>>times;
  for(int j=0;j<times;j++){
    cin>>len;
    for(int i=0;i<len;i++){
      cin>>mvp[i].pb>>mvp[i].name>>mvp[i].sc1>>mvp[i].sc2>>mvp[i].sc3;
      if(mvp[i].pb=="P"){
        mvp[i].sc2=0-mvp[i].sc2;
        mvp[i].sc3=0-mvp[i].sc3;
      }
    }
    qsort(mvp,len,sizeof(mvp[0]),compare);
    for(int i=0;i<len;i++){
      cout<<mvp[i].pb<<" "<<mvp[i].name<<endl;
    }
    if(j<times-1)
      cout<<"====="<<endl;
  }
}