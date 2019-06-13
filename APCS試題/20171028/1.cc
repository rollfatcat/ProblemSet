#include<iostream>
using namespace std;
int main(void){
  int a, b, c;
  bool A, B, C;
  string Type[3] = {"AND","OR","XOR"};
  while( cin>>a>>b>>c ){
    A=a, B=b, C=c;
    bool flag[3]={0, 0, 0};
    flag[0]=(A&B)==c;
    flag[1]=(A|B)==c;
    flag[2]=(A^B)==c;
    //
    bool first = true;
    for(int i=0;i<3;i++)
      if(flag[i])
        cout<<Type[i]<<endl;
    if(flag[0]==false and flag[1]==false and flag[2]==false)
      cout<<"IMPOSSIBLE"<<endl;
  }
}