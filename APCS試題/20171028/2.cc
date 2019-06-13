#include<iostream>
using namespace std;

int main(){
  int k;
  string str;
  while(cin>>k>>str){
  //
  int cnt=0;
  int seq[100000]={};
  //
  for(int i=0; i<str.length(); ){
    int num=1;
    for(bool mask=(str[i++]>='a'); i<str.length() and mask==(str[i]>='a'); i++)
      num++;
    seq[cnt++]=num;
  }
  //
  int max_seq=0;
  for(int i=0;i<cnt;){
    while(seq[i]<k and i<cnt)
      i++;
    int num_seq=0;
    if(i++<cnt)
      num_seq=1;
    while(i<cnt and seq[i]==k)
      i++, num_seq++;
    if(i<cnt and seq[i]>k)
      num_seq++;
    if(max_seq<num_seq)
      max_seq=num_seq;
  }
  cout<<k*max_seq<<endl;
  }
}