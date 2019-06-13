// MergeSort 前置題( 接 ZJ-a457 )

#include<iostream>
using namespace std;
#define MaxN 10000

int main(){
    int n, m;
    int number[2][MaxN];

    cin>>n>>m;
    while(n--){
        for(int j=0;j<2;j++)
            for(int i=0;i<m;i++)
                cin>>number[j][i];
        int i, j, k;
        for(i=j=k=0;i<m and j<m;)
            if(number[0][i]>number[1][j])       j++;
            else if(number[0][i]<number[1][j])  i++;
            else i++,j++,k++;
        cout<<k<<endl;
    }
}