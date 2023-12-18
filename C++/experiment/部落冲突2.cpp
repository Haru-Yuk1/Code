// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 定义一个结构体，表示一个绿洲
// struct Oasis {
//     int x, y, w, h; // 左上角坐标，宽度，高度
//     int area; // 面积
//     Oasis(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
//         area = w * h; // 计算面积
//     }
// };

// // 定义一个函数，计算给定一个划分界线 x 时，两部分的绿洲面积之差
// int diff(vector<Oasis>& oases, int x) {
//     int areaA = 0, areaB = 0; // 初始化部落 A 和 B 的绿洲面积为 0
//     for (auto& oasis : oases) { // 遍历所有的绿洲
//         if (oasis.x + oasis.w <= x) { // 如果绿洲完全在 x 的左边，那么它属于部落 A
//             areaA += oasis.area;
//         } else if (oasis.x >= x) { // 如果绿洲完全在 x 的右边，那么它属于部落 B
//             areaB += oasis.area;
//         } else { // 如果绿洲跨越了 x，那么需要计算它的左右部分的面积
//             int left = x - oasis.x; // 左边部分的宽度
//             int right = oasis.w - left; // 右边部分的宽度
//             areaA += left * oasis.h; // 左边部分的面积加到部落 A
//             areaB += right * oasis.h; // 右边部分的面积加到部落 B
//         }
//     }
//     return areaA - areaB; // 返回两部分的绿洲面积之差
// }

// int main() {
//     int n; // 输入绿洲的个数
//     cin >> n;
//     vector<Oasis> oases; // 存储所有的绿洲
//     int minx = 1e6, maxx = 0; // 记录所有绿洲的最小和最大的 x 坐标
//     for (int i = 0; i < n; i++) {
//         int x, y, w, h; // 输入绿洲的信息
//         cin >> x >> y >> w >> h;
//         oases.emplace_back(x, y, w, h); // 创建一个绿洲对象并加入到数组中
//         minx = min(minx, x); // 更新最小的 x 坐标
//         maxx = max(maxx, x + w); // 更新最大的 x 坐标
//     }
//     int ans = -1; // 初始化答案为 -1
//     int min_diff = 1e6; // 初始化最小的绿洲面积之差为一个很大的数
//     for (int x = minx; x <= maxx; x++) { // 枚举所有可能的划分界线 x
//         int d = diff(oases, x); // 计算当前的绿洲面积之差
//         if (d >= 0 && d < min_diff) { // 如果当前的绿洲面积之差非负且比之前的更小，那么更新答案和最小的绿洲面积之差
//             ans = x;
//             min_diff = d;
//         }
//     }
//     cout << ans << endl; // 输出答案
//     return 0;
// }




#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// 判断当前划分位置是否满足要求
bool check(long long mid, int n, vector<vector<long long>>& greenLands) {
	long long leftArea = 0;
	long long rightArea = 0;
	
	// 遍历所有绿洲
	for (int i = 0; i < n; i++) {
		if (greenLands[i][0] + greenLands[i][2] <= mid) {
			// 绿洲完全在左边
			leftArea += greenLands[i][2] * greenLands[i][3];
		} else if (greenLands[i][0] >= mid) {
			// 绿洲完全在右边
			rightArea += greenLands[i][2] * greenLands[i][3];
		} else {
			// 绿洲被划分为左右两部分
			long long overlapWidth = mid - greenLands[i][0];
			leftArea += overlapWidth * greenLands[i][3];
			rightArea += (greenLands[i][2] - overlapWidth) * greenLands[i][3];
		}
	}
	
	return leftArea >= rightArea;
}
 
// 二分查找划分位置
long long find(int n, vector<vector<long long>>& greenLands) {
	// 将绿洲按照x坐标排序
	sort(greenLands.begin(), greenLands.end(), [](const vector<long long>& a, const vector<long long>& b) {
		return a[0] < b[0];
	});
	
	long long left = 0;
	long long right = 1000000;
	long long result = 0;
	
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		
		if (check(mid, n, greenLands)) {
			// 当前划分位置满足要求（左边面积大于等于右边面积），更新结果并缩小右边界
			result = mid;
			right = mid - 1;
		} else {
			// 当前划分位置不满足要求，增大左边界
			left = mid + 1;
		}
	}
	
	return result;
}
 
int main() {
	int n;
	cin >> n;
	
	vector<vector<long long>> greenLands(n, vector<long long>(4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> greenLands[i][j];
		}
	}
	
	long long x = find(n, greenLands);
	cout << x << endl;
	
	return 0;
}