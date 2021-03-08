#include<iostream>
#include<cmath>
using namespace std;

bool input[201][201]={};
int rectangle[201][201]={};
int rectangle_area[201][201]={};
int main(){
  int m,n;
  while(cin>>m>>n){
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cin>>input[i][j];
      }
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(input[i][j]){
          rectangle[i][j]=rectangle[i][j-1]+1;
        }
        else{
          rectangle[i][j]=0;
        }
      }
    }
    int max_a=0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        //以(i,j)往左往上算出最大長方形
        int min_w=rectangle[i][j];
        rectangle_area[i][j]=min_w;
        for(int k=i-1;k>=0;k--){
          int h=i-k+1;
          min_w = min( min_w, rectangle[k][j] );
          if(min_w==0)
            break;
          int area=min_w*h;
          if(area>rectangle_area[i][j])
            rectangle_area[i][j]=area;
          if(max_a<area) max_a=area;
        }
      }
    }
    cout<<max_a<<endl;
  }
}
/*
4 5
0 0 1 1 0
0 1 1 1 1
0 1 0 1 1
0 1 1 1 1
*/