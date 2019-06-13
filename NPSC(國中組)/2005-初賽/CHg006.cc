#include<iostream>
using namespace std;


int Judge(int tx, int ty, int mx, int my){
  if(tx==mx and ty==my)
    return 0;
  long long int a=tx*my;
  long long int b=mx*ty;
  return (a>b)?1:-1;
}
int main(){
  int tx, ty, mx, my;
  while(cin>>tx>>ty and tx and ty){
    int lx=0, ly=1;
    int rx=1, ry=0;
    while(true){
      mx=(lx+rx);
      my=(ly+ry);
      int status=Judge(tx, ty, mx, my);
      if(status==0){
        cout<<endl;
        break;
      }
      else if(status==1){
        cout<<'R';
        lx=mx, ly=my;
      }
      else{
        cout<<'L';
        rx=mx, ry=my;
      }
    }
  }
}