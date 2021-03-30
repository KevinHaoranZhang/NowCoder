#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* question 1
 * @ Description:
 *
 * 我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：
 * 1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
 * 2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
 * 3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
 * 我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
 * ……
 * 万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……
 * 请听题：请实现大锤的自动校对程序
 *
 * @ Input Example:
 * 第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。
 * 后面跟随N行，每行为一个待校验的字符串。
 *
 * 2
 * helloo
 * wooooooow
 *
 * @ Output Example:
 * N行，每行包括一个被修复后的字符串。
 *
 * hello
 * woow
 */

string word_processor(string word);

int main() {
    // question 1
    int total_word_num = 0;
    cin >> total_word_num;
    vector<string> word_list;
    string word;
    for (int i = 0; i < total_word_num; i++) {
        cin >> word;
        word_list.push_back(word);
    }
    for (int i = 0; i < word_list.size(); i++) {
        string processed_word = word_processor(word_list[i]);
        cout << processed_word << endl;
    }
    return 0;
}

// question 1
string word_processor(string word) {
    // base condition
    if (word.size() < 3) {
        return word;
    }

    string processed_word;
    // track the latest processed word string
    int j = 0;
    for (int i = 0; i < word.size(); i++) {
        // compare the lastest charater in the original word to previous ones in the processed word
        j = processed_word.size() - 1;
        // condition 1: triple duplicates
        if (i >= 2 && word[i] == processed_word[j] && word[i] == processed_word[j-1]) {
            continue;
        }
        // condition 2: AABB
        if (i >= 3 && word[i] == processed_word[j] && processed_word[j-1] == processed_word[j-2]) {
            continue;
        }
        processed_word += word[i];
    }
    return processed_word;
}

