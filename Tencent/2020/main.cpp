#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
/* Question 1
 * @ Description
 * 小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
 * 对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，
 * 现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？
 *
 * @ Input Example
 * "HG[3|B[2|CA]]F"
 *
 * @ Output Example
 * "HGBCACABCACABCACAF"
 *
 * @ Explanation
 * HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
 *
 */

// question 1
string compress(string str);

/* Question 2
 * @ Description
 * 小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。
 * 小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，所以他想知道他在每栋楼的位置处能看到多少栋楼呢？
 * （当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住）
 *
 * @ Input Example
 * [5,3,8,3,2,5]
 *
 * @ Output Example
 * [3,3,5,4,4,4]
 *
 * @ Explanation
 * 当小Q处于位置3时，他可以向前看到位置2,1处的楼，向后看到位置4,6处的楼，加上第3栋楼，共可看到5栋楼。
 * 当小Q处于位置4时，他可以向前看到位置3处的楼，向后看到位置5,6处的楼，加上第4栋楼，共可看到4栋楼。
 */

// question 2
vector<int> findBuilding(vector<int>& heights);

int main() {
    // question 1
    cout << "question 1:" << compress("HG[3|B[2|CA]]F") << endl;
    // question 2
    vector<int> heights{5,3,8,3,2,5};
    vector<int> seen_heights =  findBuilding(heights);
    return 0;
}

string compress(string str) {
    // cur_index: iterator of the string being processed
    // lb_index: find the corresponding left square bracket index
    // slash_index: find the corresponding slash index
    int cur_index = 0, lb_index = 0, slash_index = 0;
    // algorithm: find all [] in the string, replace it with processed string, starting from the innermost one
    while (cur_index < str.size()) {
        // find the leftmost right bracket
        if (str[cur_index] == ']') {
            lb_index = cur_index;
            // find the corresponding left bracket
            while (str[lb_index] != '[') {
                // record the corresponding slash index
                if (str[lb_index] == '|') {
                    slash_index = lb_index;
                }
                lb_index--;
            }
            // extract the multiplier
            int multiplier = stoi(str.substr(lb_index + 1, slash_index - lb_index - 1));
            // extract the sub string to be multiplied
            string sub_str = str.substr(slash_index + 1, cur_index - slash_index - 1);
            // store the string to replace []
            string replace_str = "";
            for (int i = 0; i < multiplier; i++) {
                replace_str += sub_str;
            }
            // replace [] with new string
            str.replace(lb_index, cur_index - lb_index + 1, replace_str);
            cur_index = lb_index;
        }
        cur_index++;
    }
    return str;
}

vector<int> findBuilding(vector<int>& heights) {
    int num_building = heights.size();
    vector<int> seen_heights(num_building, 1);
    // O(n^2) too slow
//    for (int i = 0; i < heights.size(); i++) {
//        int cur_pos = i, left_max = 0, right_max = 0, cur_seen = 1;
//        for (int left_index = cur_pos - 1; left_index >= 0; left_index--) {
//            if (heights[left_index] > left_max) {
//                left_max = heights[left_index];
//                cur_seen++;
//            }
//        }
//
//        for (int right_index = cur_pos + 1; right_index < heights.size(); right_index++) {
//            if (heights[right_index] > right_max) {
//                right_max = heights[right_index];
//                cur_seen++;
//            }
//        }
//        seen_heights.push_back(cur_seen);
//    }
    // using stack O(n)
    stack<int> left_stack;
    stack<int> right_stack;
    for (int i = 0; i < num_building; i++) {
        // update final results
        seen_heights[i] += left_stack.size();
        seen_heights[num_building - i - 1] += right_stack.size();
        // iterate left building, pop blocked ones
        while (!left_stack.empty() && left_stack.top() <= heights[i]) {
            left_stack.pop();
        }
        // iterate right building, pop blocked ones
        while (!right_stack.empty() && right_stack.top() <= heights[num_building - i - 1]) {
            right_stack.pop();
        }
        left_stack.push(heights[i]);
        right_stack.push(heights[num_building - i - 1]);
    }
    return seen_heights;
}
