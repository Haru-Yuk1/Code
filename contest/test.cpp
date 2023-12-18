#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Oasis {
    int x, y, w, h;

    int area() const {
        return w * h;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Oasis> oases(n);
    vector<int> boundaries;

    // 读取绿洲数据并记录所有的左右边界
    for (int i = 0; i < n; ++i) {
        cin >> oases[i].x >> oases[i].y >> oases[i].w >> oases[i].h;
        boundaries.push_back(oases[i].x);
        boundaries.push_back(oases[i].x + oases[i].w);
    }

    // 移除重复的边界值
    sort(boundaries.begin(), boundaries.end());
    boundaries.erase(unique(boundaries.begin(), boundaries.end()), boundaries.end());

    // 计算所有绿洲的总面积
    int totalArea = 0;
    for (const auto& oasis : oases) {
        totalArea += oasis.area();
    }

    // 找到最佳划分界线
    int bestBoundary = boundaries.front();
    int halfTotalArea = totalArea / 2;
    int closestDiff = totalArea;

    for (int boundary : boundaries) {
        int areaA = 0;
        for (const auto& oasis : oases) {
            if (oasis.x < boundary) {
                int width = min(boundary - oasis.x, oasis.w);
                areaA += width * oasis.h;
            }
        }
        if (areaA >= halfTotalArea) {
            int diff = areaA - halfTotalArea;
            if (diff < closestDiff) {
                closestDiff = diff;
                bestBoundary = boundary;
            }
        }
    }

    cout << bestBoundary << endl;
    return 0;
}
