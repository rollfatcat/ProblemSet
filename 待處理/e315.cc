/* 題目給訂的雖然是整數但是計算時涉及到浮點數運算 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    scanf("%d %d %d",&A,&B,&C);
    printf("%.0lf\n",A*0.2+B*0.3+C*0.5);
}