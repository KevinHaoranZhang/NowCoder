#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
/* Question 1
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

/* Question 2
 * @ Description
 *
 * 我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。和我一起行动的还有另外两名特工，我提议
 * 1. 我们在字节跳动大街的N个建筑中选定3个埋伏地点。
 * 2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过D。
 *
 * 我特喵是个天才! 经过精密的计算，我们从X种可行的埋伏方案中选择了一种。这个方案万无一失，颤抖吧，孔连顺！
 * ……
 * 万万没想到，计划还是失败了，孔连顺化妆成小龙女，混在cosplay的队伍中逃出了字节跳动大街。只怪他的伪装太成功了，就是杨过本人来了也发现不了的！
 *
 * 请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择.
 * 注意：
 * 1. 两个特工不能埋伏在同一地点
 * 2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用
 *
 * @ Input Example:
 * 第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)
 * 第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）
 *
 * 4 3
 * 1 2 3 4
 *
 * @ Output Example:
 * 一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模
 *
 * 4
 * 可选方案 (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)
 */
#define OVERFLOW_LIMIT 99997867
long long num_combination(vector<int> building_list, int distance);

int main() {
    // question 1
//    int total_word_num = 0;
//    cin >> total_word_num;
//    vector<string> word_list;
//    string word;
//    for (int i = 0; i < total_word_num; i++) {
//        cin >> word;
//        word_list.push_back(word);
//    }
//    for (int i = 0; i < word_list.size(); i++) {
//        string processed_word = word_processor(word_list[i]);
//        cout << processed_word << endl;
//    }

    // question 2
    int total_building_num = 0, distance = 0;
    cin >> total_building_num >> distance;
    vector<int> building_list;
    int building_location;
    for (int i = 0; i < total_building_num; i++) {
        cin >> building_location;
        building_list.push_back(building_location);
    }
    cout << num_combination(building_list, distance) << endl;

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

// question 2
long long num_combination(vector<int> building_list, int distance) {
    int i, j, building_num = building_list.size();
    long long sum = 0;
    for (i = 0, j = 2; i < building_num - 2; i++) {
        // find the next allowed building position
        while (j < building_num && building_list[j] - building_list[i] <= distance) {
            j++;
        }
        // combination: base (j - i - 1), choose 2 (fixed position for i)
        // C(n, 2) = n * (n - 1) / 2
        if (j - i - 1>= 2) {
            sum += (long long)(j - i - 1) * (long long)(j - i - 2) / 2;
        }

    }
    return sum % OVERFLOW_LIMIT;
}

