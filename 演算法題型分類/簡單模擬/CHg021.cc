
#include<iostream>
using namespace std;

int main(){
  int power[5]={ 0, 10, 100, 1000, 10000};
  int M, N, P, R, a, b;

  while(cin>>M>>N>>P>>R and M and N and P and R){

    if(M==N){
      cout<<"Draw with ";
      for(int i=0;i<R;i++)
        M=M*M%power[P];
      cout<<M<<'.'<<endl;
    }
    else{
      string ss[2];
      int n[2];
      if(M<N) ss[0]="king", ss[1]="ghost",  n[0]=M, n[1]=N;
      else    ss[1]="king", ss[0]="ghost",  n[1]=M, n[0]=N;;
      for(int i=0;i<R;i++){
        if(i%2) n[1]=n[0]*n[1]%power[P];
        else n[0]=n[0]*n[1]%power[P];
      }
      cout<<"The "<<ss[(R%2)^1]<<" of childish won the game with "<<n[(R%2)^1]<<'.'<<endl;
    }
  }
}