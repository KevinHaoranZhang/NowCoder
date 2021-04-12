#include <iostream>
#include <vector>

using namespace std;
/* Question 1
 * @ Description
 * P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），则称其为“最大的”。
 * 求出所有“最大的”点的集合。（所有点的横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内）
 *
 * @ Input Example
 * 第一行输入点集的个数 N， 接下来 N 行，每行两个数字代表点的 X 轴和 Y 轴。
 * 对于 50%的数据,  1 <= N <= 10000;
 * 对于 100%的数据, 1 <= N <= 500000;
 *
 * 5
 * 1 2
 * 5 3
 * 4 6
 * 7 5
 * 9 0
 *
 * @ Ouput Example
 * 输出“最大的” 点集合， 按照 X 轴从小到大的方式输出，每行两个数字分别代表点的 X 轴和 Y轴。
 *
 * 4 6
 * 7 5
 * 9 0
 */

void question1();
void find_max_set(vector<pair<int, int>> input_set);

int main() {
    // question1;
    question1();
    return 0;
}

// question1
void question1() {
    int set_num = 0;
    cin >> set_num;
    vector<pair<int, int>> input_set;
    for (int i = 0; i < set_num; i++) {
        int first = 0, second = 0;
        cin >> first >> second;
        input_set.push_back(make_pair(first, second));
    }
    find_max_set(input_set);
}

void find_max_set(vector<pair<int, int>> input_set) {
    vector<pair<int, int>> set_seen;
    int max_set_bitmap [input_set.size()];
    for (int i = 0; i < input_set.size(); i++) {
        bool max_set = true;
        for (int j = 0; j < set_seen.size(); j++) {
            if (input_set[i].first > set_seen[j].first && input_set[i].second > set_seen[j].second) {
                max_set_bitmap[j] = 0;
            }
            if (input_set[i].first < set_seen[j].first && input_set[i].second < set_seen[j].second) {
                max_set = false;
            }
        }
        set_seen.push_back(input_set[i]);
        if (max_set) {
            max_set_bitmap[i] = 1;
        } else {
            max_set_bitmap[i] = 0;
        }
    }
    for (int i = 0; i < input_set.size(); i++) {
        if (max_set_bitmap[i] == 1) {
            cout << input_set[i].first << " " << input_set[i].second << endl;
        }
    }
}

