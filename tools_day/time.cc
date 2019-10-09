#include <iostream>
using namespace std;
struct Date {
  int y; // year
  int m; // month
  int d; // day in month
};
bool isLeap(int y) //判断是否是闰年
{
  return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; //真返回为1，假为0
}
int daysOfMonth(int y, int m) {
  int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m != 2)
    return day[m - 1];
  else
    return 28 + isLeap(y);
}
int daysOfDate(Date d) //计算一共的天数
{
  int days = d.d;
  for (int y = 1; y < d.y; y++) //计算年
    days += 365 + isLeap(y);
  for (int m = 1; m < d.m; m++) //计算月
    days += daysOfMonth(d.y, m);
  // days+=d.d;
  return days;
}
int main() {
  Date d1, d2;
  cout << "intput 2 dates(yyyy mm dd):";
  cin >> d1.y >> d1.m >> d1.d;
  // cin >> d2.y >> d2.m >> d2.d;
  d2.y = 2020;
  d2.m = 1;
  d2.d = 1;

  int days1 = daysOfDate(d1);
  int days2 = daysOfDate(d2);
  cout << "difference:" << days2 - days1 << endl;
  cout << "weekday" << days1 % 7 << "\t" << days2 % 7 << endl;
  return 0;
}