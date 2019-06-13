// Huffman Code『解碼』：map實作
#include<iostream>
#include<map>
using namespace std;

int main(){
  map<string,char> Book;
  Book["00"]='A', Book["01"]='B',
  Book["100"]='0', Book["101"]='1',
  Book["1100"]='2', Book["1101"]='3',
  Book["11100"]='4', Book["11101"]='5',
  Book["111100"]='6', Book["111101"]='7',
  Book["111110"]='8', Book["111111"]='9';
  for(int N; cin>>N;){
    for(int i=0;i<N;i++){
      string ss, subss="";  cin>>ss;
      for(int j=0, cnt=0; j<ss.length(); j++){
        subss+=ss[j];
        if(Book.find(subss)!=Book.end())
          cout<<Book[subss], cnt++, subss="";
        if(cnt==4)
          cout<<',', cnt++;
      }
      cout<<endl;
    }
  }
}