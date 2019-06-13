// Sort練習
#include<iostream>
#include<algorithm>
using namespace std;

struct Pair{
  string A, B; int p, v;
  bool operator<(const Pair &other)const{ return (v==other.v)?(p<other.p):(v<other.v);  }
}meme[100];
int main(){
  int caseNum, cnt;

  cin>>caseNum;
  while(caseNum--){
    cin>>cnt;
    for(int i=0;i<cnt;i++)
      cin>>meme[i].A>>meme[i].B>>meme[i].v, meme[i].p=i;
    sort(meme,meme+cnt);
    if(meme[0].v>=0)  cout<<"Are you kidding me?"<<endl;
    else  cout<<meme[0].A<<' '<<meme[0].B<<endl;
  }
}