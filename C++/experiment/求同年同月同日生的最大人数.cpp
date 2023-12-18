#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 定义一个map，用来存储每个日期出现的次数
    map<string, int> count;
    // 定义一个变量n，用来输入出生日期的个数
    int n;
    // 从标准输入中读取n的值
    cin >> n;
    // 定义一个循环，从0到n-1，每次循环读取一个出生日期，并更新map中的计数
    for (int i = 0; i < n; i++) {
        // 定义一个字符串变量date，用来存储一个出生日期
        string date;
        // 从标准输入中读取date的值
        cin >> date;
        // 如果map中已经有这个日期，就把它的计数加一
        if (count.count(date)) {
            count[date]++;
        }
        // 否则，就把这个日期插入到map中，并把它的计数设为一
        else {
            count[date] = 1;
        }
    }
    // 定义一个变量max，用来存储同年同月同日生的最大人数，初始值为0
    int max = 0;
    // 定义一个vector，用来存储满足同年同月同日生最大人数的日期
    vector<string> dates;
    // 遍历map中的每个键值对，找出最大的计数，并把对应的日期存入vector中
    for (auto it = count.begin(); it != count.end(); it++) {
        // 如果当前的计数大于max，就更新max，并清空vector，把当前的日期插入到vector中
        if (it->second > max) {
            max = it->second;
            dates.clear();
            dates.push_back(it->first);
        }
        // 如果当前的计数等于max，就把当前的日期插入到vector中
        else if (it->second == max) {
            dates.push_back(it->first);
        }
    }
    // 对vector中的日期进行升序排序
    sort(dates.begin(), dates.end());
    // 输出同年同月同日生的最大人数
    cout << max << endl;
    // 输出满足同年同月同日生最大人数的日期，每行一个
    for (auto date : dates) {
        cout << date << endl;
    }
    // 返回0，表示程序正常结束
    return 0;
}
