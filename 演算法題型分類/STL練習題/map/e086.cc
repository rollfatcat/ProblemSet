// 練習struct混搭STL的map解決實際問題
#include<bits/stdc++.h>
using namespace std;

struct OBJ{
  string id, name, ans;
  int point;
  bool operator<(const OBJ &rhs)const{ return id<rhs.id; }
};
struct MAN{
 string id, name;
 vector<int> score;
 bool operator<(const MAN &rhs)const{ return id<rhs.id; }
};
vector<OBJ> object;
vector<MAN> student;
map<string,int> obj_table;
map<string,int> stu_table;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int object_num, student_num;
  while(cin>>object_num>>student_num){

    object.resize(object_num),
    student.resize(student_num);

    for(int i=0;i<object_num;i++)
      cin>>object[i].id>>object[i].name>>object[i].ans,
      object[i].point=100/object[i].ans.length();
    for(int i=0;i<student_num;i++)
      cin>>student[i].id>>student[i].name,
      student[i].score.resize(object_num);

    sort(object.begin(),object.end());
    sort(student.begin(),student.end());
    obj_table.clear();
    stu_table.clear();
    for(int i=0;i<object_num;i++)
      obj_table[ object[i].id ]=i;
    for(int i=0;i<student_num;i++)
      stu_table[ student[i].id ]=i;

    string sID, oID, test_ans, real_ans;
    int stu_ID, obj_ID;
    for(int i=0;i<object_num*student_num;i++){
      cin>>sID>>oID>>test_ans;

      stu_ID=stu_table[sID],
      obj_ID=obj_table[oID];
      real_ans= object[ obj_ID ].ans;
      int correct=0;
      for(int j=0;j<real_ans.length() and j<test_ans.length();j++)
        if(real_ans[j]==test_ans[j])
          correct++;
      student[stu_ID].score[obj_ID]=correct*object[obj_ID].point;
    }
    for(int i=0;i<student_num;i++)
      for(int j=0;j<object_num;j++)
        cout<<student[i].id<<','<<student[i].name<<',',
        cout<<object[j].id<<','<<object[j].name<<','<<student[i].score[j]<<endl;
  }
}
/*
2 3
001 eng AAAAA
002 math BBBBBBBBBB
001 Tom
002 Peter
003 David
001 001 AAA=A
001 002 AAABBBCCC=
002 001 CCAAA=A
002 002 AADBBBCCC=DDD
003 001 AAAAA
003 002 BBBBBBBBBB
*/