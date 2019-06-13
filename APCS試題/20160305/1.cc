#include<iostream>
using namespace std;
int main(){
  int num, safe, gg;
  int grade[25]={};

  while(cin>>num){
    safe=101;
    gg=-1;
    for(int i=0;i<num;i++){
      cin>>grade[i];
      if(grade[i]>=60){
        if(safe>grade[i])
          safe=grade[i];
      }
      else{
        if(gg<grade[i])
          gg=grade[i];
      }
      for(int j=i; j>0 and grade[j-1]>grade[j];j--){
        int tmp=grade[j];
        grade[j]=grade[j-1];
        grade[j-1]=tmp;
      }
    }
    //
    cout<<grade[0];
    for(int i=1;i<num;i++)
      cout<<' '<<grade[i];
    cout<<endl;
    if(safe==101){
      cout<<gg<<endl<<"worst case"<<endl;
    }
    else if(gg==-1){
      cout<<"best case"<<endl<<safe<<endl;
    } else {
      cout<<gg<<endl<<safe<<endl;
    }
  }
}