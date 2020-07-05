/* 給定指令(０代表輸入結束,１代表套餐,２代表單點)和餐點號碼，輸出對應的餐點和價格
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string MealSet_name[6]={"","Medium Wac","WChicken Nugget","Geez Burger","ButtMilk Crispy Chicken","Plastic Toy"};
	int MealSet_price[6]={0,4,8,7,6,3};
	string MealOdr_name[5]={"","German Fries","Durian Slices","WcFurry","Chocolate Sunday"};
	int MealOdr_price[5]={0,2,3,5,7};
	
	int opt, number, total=0;
	while(cin>>opt and opt>0){
		cin>>number;
		if(opt==1)
			cout<<MealSet_name[number]<<' '<<MealSet_price[number]<<'\n',
			total+=MealSet_price[number];
		else
			cout<<MealOdr_name[number]<<' '<<MealOdr_price[number]<<'\n',
			total+=MealOdr_price[number];
	}
	cout<<"Total: "<<total<<'\n';
}