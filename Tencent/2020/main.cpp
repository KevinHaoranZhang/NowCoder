#include <iostream>
#include <string>

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

int main() {
    // question 1
    cout << "question 1:" << compress("HG[3|B[2|CA]]F") << endl;
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
