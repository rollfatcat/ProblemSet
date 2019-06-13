// 實際應用：http://squall.cs.ntou.edu.tw/cprog/content/10b1%20Binary%20search%20and%20applications_bw.pdf
/* (1)初級問題：
 * Given an array of integers and an integer L,
 * find the position of the first element of the array that is greater than or equal to L.
 * 介紹 lowbound() 和 upper_bound 的STL用法
 *    ZJ-a450
 *    ZJ-a625
 *    ZJ-a864
 *    ZJ-b543
 *    ZJ-b837
 *    ZJ-c010 ==> 和 c421/d713 比較，當數量極大時不能用vector插入模擬找到中位數
 *    ZJ-c777
 *    ZJ-d423
 *
 * (2) 利用二分搜尋快速逼近答案
 *    ZJ-c575 基地台 => 前置練習題請參考題影片內容
 *    uva-00714
 *    uva-11413
 *    ZJ-c942
 *    ZJ-a277
 *
 * (3) 最大化平均值
 *    ZJ-c904
 * (4) 混合雙向BFS的概念
 *    ZJ-c927
 *
   STL 教學連結：https://blog.csdn.net/zwj1452267376/article/details/47150521
 * #include<algorithm>
 * 想像檢測值如果會出現在陣列時『應該』要存在的位置
 * lower_bound( arr_st , arr_ed , value ) : 回傳第一個大於等於值的陣列位置
 * upper_bound( arr_st , arr_ed , value ) : 回傳第一個大於值的陣列位置
 * binary_search( arr_st , arr_ed , value ) : 是否在範圍內(回傳T/F)
 *
 *
 */