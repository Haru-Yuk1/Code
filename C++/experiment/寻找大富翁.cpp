// #include <iostream>
// #include <algorithm>
// using namespace std;

// // 定义一个结构体，用来存储每个人的编号和资产值
// struct person {
//     int id; // 编号
//     long long wealth; // 资产值
// };

// // 定义一个比较函数，用来按照资产值从大到小排序
// bool cmp(person a, person b) {
//     return a.wealth > b.wealth;
// }

// int main() {
//     int n, m; // 输入的总人数和需要找出的大富翁数
//     cin >> n >> m;
//     person arr[n]; // 存储每个人的信息
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i].wealth; // 输入每个人的资产值
//         arr[i].id = i + 1; // 给每个人分配一个编号
//     }
//     sort(arr, arr + n, cmp); // 对数组进行按照资产值从大到小的排序
//     for (int i = 0; i < m; i++) {
//         if(i==m-1){
//             cout<<arr[i].wealth;
//         }
//         else{
//             cout << arr[i].wealth << " "; // 输出资产排前M位的大富翁的资产值
//         }
        
//     }
//     cout << endl;
//     return 0;
// }


#include <iostream>
#include <algorithm>

using namespace std;


void findTopM(long long n, long long m) {
    long long *money = new long long[m];
    if (n <= m) m = n;
    for (int i = 0; i < m; i++)
        cin >> money[i];
    sort(money, money + m);


    for (int i = m + 1; i <= n; i++) {
        long long s;
        cin >> s;

        if (s > money[0]) {
            money[0] = s;
            sort(money, money + m);
        }
    }

    for (int i = m - 1; i > 0; i--)
        cout << money[i] << ' ';

    cout << money[0];

    delete[] money;
}

int main() {
    long long n, m;
    cin >> n >> m;
    findTopM(n, m);
    return 0;
}
