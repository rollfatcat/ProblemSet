/* 數學計算，題目有給予各個班級的人數/平均分數/標準差，求全校的平均/標準差
 * 主要如何計算透過各班『標準差』計算全校的『標準差』？
 * 從定義回推：sqrt( ((x1-u)^2＋(x2-u)^2＋……＋(xn-u)^2)÷ｎ )＝sqrt( x1^2＋x2^2＋……＋xn^2 )÷n－u^2
 * x1^2＋x2^2＋……＋xn^2 可以由各個班級的平均和標準差算出＝Σ #students*(avg^2+dev^2)。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int num_class, num_student, avg, dev;
  scanf("%d",&num_class);
  int ans_student=0;
  double ans_avg=0;
  double ans_dev=0;
  for(int i=0;i<num_class;i++)
    scanf("%d %d %d",&num_student,&avg,&dev),
    ans_student+=num_student,
    ans_avg+=avg*num_student,
    ans_dev+=(dev*dev+avg*avg)*num_student;
  ans_avg/=ans_student;
  printf("%d %.2lf ",ans_student,ans_avg);
  printf("%.2lf\n",sqrt(ans_dev/ans_student-ans_avg*ans_avg));
}