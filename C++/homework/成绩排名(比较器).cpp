#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个结构体，存储学生的学号，语文成绩和数学成绩
struct Student {
    int id; // 学号
    int chinese; // 语文成绩
    int math; // 数学成绩
};

// 定义一个比较函数，用于排序
bool compare(Student a, Student b) {
    // 如果语文成绩不同，按语文成绩降序排序
    if (a.chinese != b.chinese) {
        return a.chinese > b.chinese;
    }
    // 如果语文成绩相同，但数学成绩不同，按数学成绩降序排序
    if (a.math != b.math) {
        return a.math > b.math;
    }
    // 如果语文成绩和数学成绩都相同，按学号升序排序
    return a.id < b.id;
}

int main() {
    int n; // 学生数量
    cin >> n; // 输入学生数量
    vector<Student> students(n); // 创建一个存储学生的向量
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].chinese >> students[i].math; // 输入每个学生的信息
    }
    sort(students.begin(), students.end(), compare); // 对学生进行排序
    for (int i = 0; i < n; i++) {
        cout << students[i].id << endl; // 输出每个学生的学号
    }
    return 0;
}
