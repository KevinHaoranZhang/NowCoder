#include <iostream>
#include <vector>
#include <string>         // std::string
#include <algorithm>
#include <numeric>
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
void find_max_set(vector<pair<int, int>> input_list);

/* Description
 * 给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：
 * 区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。
 * 如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:
 *
 * [6] = 6 * 6 = 36;
 * [2] = 2 * 2 = 4;
 * [1] = 1 * 1 = 1;
 * [6,2] = 2 * 8 = 16;
 * [2,1] = 1 * 3 = 3;
 * [6, 2, 1] = 1 * 9 = 9;
 *
 * 从上述计算可见选定区间 [6] ，计算值为 36， 则程序输出为 36。
 * 区间内的所有数字都在[0, 100]的范围内;
 *
 * @ Input Example:
 * 第一行输入数组序列长度n，第二行输入数组序列。
 * 对于 50%的数据,  1 <= n <= 10000;
 * 对于 100%的数据, 1 <= n <= 500000;
 *
 * 3
 * 6 2 1
 *
 * @ Output Example:
 * 输出数组经过计算后的最大值。
 *
 * 36
 */
vector<int> sub_set;
vector<vector<int>> all_sub_set;
void question2();
void find_max_subset(int cur_index, vector<int>& input_list);

int main() {
    // question1
    // question1();

    // question2
    question2();

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

// question2
void question2() {
    int list_size = 0;
    vector<int> input_list;
    cin >> list_size;
    for (int i = 0; i < list_size; i++) {
        int num;
        cin >> num;
        input_list.push_back(num);
    }
    long max = input_list[0] * input_list[0];
    for (int i = 0; i < input_list.size(); i++) {
        long sum  = input_list[i];
        int min = input_list[i];
        for (int j = i + 1; j < input_list.size(); j++) {
            if (input_list[j] == 0) {
                break;
            }
            sum += input_list[j];
            if (min > input_list[j]) {
                min = input_list[j];
            }
            if (min * sum > max) {
                max = min * sum;
            }
        }
    }
    cout << max << endl;
}
