#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
void question1();
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
void question2();
#define OVERFLOW_LIMIT 99997867
long long num_combination(vector<int> building_list, int distance);

/* Question 3
 * @ Description
 *
 * 小包最近迷上了一款叫做雀魂的麻将游戏，但是这个游戏规则太复杂，小包玩了几个月了还是输多赢少。
 * 于是生气的小包根据游戏简化了一下规则发明了一种新的麻将，只留下一种花色，并且去除了一些特殊和牌方式（例如七对子等），具体的规则如下：
 *
 * 总共有36张牌，每张牌是1~9。每个数字4张牌。
 * 你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
 * 14张牌中有2张相同数字的牌，称为雀头。
 * 除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。顺子的意思是递增的连续3个数字牌（例如234,567等），刻子的意思是相同数字的3个数字牌（例如111,777）
 *
 * 例如：
 * 1 1 1 2 2 2 6 6 6 7 7 7 9 9 可以组成1,2,6,7的4个刻子和9的雀头，可以和牌
 * 1 1 1 1 2 2 3 3 5 6 7 7 8 9 用1做雀头，组123,123,567,789的四个顺子，可以和牌
 * 1 1 1 2 2 2 3 3 3 5 6 7 7 9 无论用1 2 3 7哪个做雀头，都无法组成和牌的条件。
 *
 * 现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，取到哪几种数字牌可以和牌。
 *
 * @ Input Example:
 * 输入只有一行，包含13个数字，用空格分隔，每个数字在1~9之间，数据保证同种数字最多出现4次。
 *
 * 1 1 1 2 2 2 5 5 5 6 6 6 9
 *
 * @ Output Example:
 * 输出同样是一行，包含1个或以上的数字。代表他再取到哪些牌可以和牌。若满足条件的有多种牌，请按从小到大的顺序输出。若没有满足条件的牌，请输出一个数字0
 *
 * 9
 * 可以组成1,2,6,7的4个刻子和9的雀头
 */

void question3();
vector<int> available_num(vector<int> input_card_list, vector<int> card_counter);
bool is_win(vector<int> remaining_card_list);

int main() {
    // question 1
    // question1();

    // question 2
    // question2();

    // question 3
    question3();
    return 0;
}

// question 1
void question1() {
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
}

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
void question2() {
    int total_building_num = 0, distance = 0;
    cin >> total_building_num >> distance;
    vector<int> building_list;
    int building_location;
    for (int i = 0; i < total_building_num; i++) {
        cin >> building_location;
        building_list.push_back(building_location);
    }
    cout << num_combination(building_list, distance) << endl;
}

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

// question 3
void question3() {
    // initial 13 cards given
    vector<int> input_card_list(13);
    // counter for each card's occurance, maximum 4, index range 1 - 9
    vector<int> card_counter(10, 0);
    for (int i = 0; i < 13; i++) {
        cin >> input_card_list[i];
        // increment card counter accordingly
        card_counter[input_card_list[i]]++;
    }
    vector<int> available_num_list = available_num(input_card_list, card_counter);
    if (available_num_list.empty()) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < available_num_list.size(); i++) {
            cout << available_num_list[i] << " ";
        }
    }
}

vector<int> available_num(vector<int> input_card_list, vector<int> card_counter) {
    // store all possible card to win
    vector<int> available_num_list;
    // sort input card list for winning condition check algorithm to work
    sort(input_card_list.begin(), input_card_list.end());
    // iterate over all possible card
    for (int i = 1; i <= 9; i++) {
        // skip if a card reach maximum
        if (card_counter[i] == 4) {
            continue;
        }
        // find next position to insert i
        auto it = lower_bound(input_card_list.begin(), input_card_list.end(), i);
        input_card_list.insert(it, i);

        // check if this card can win
        if (is_win(input_card_list)) {
            available_num_list.push_back(i);
        }

        // remove card i from the list to continue
        it = lower_bound(input_card_list.begin(), input_card_list.end(), i);
        input_card_list.erase(it);
    }
    return available_num_list;
}

bool is_win(vector<int> remaining_card_list) {
    // base condition
    if (remaining_card_list.empty()) {
        return true;
    }
    // check number of repeated first number in the list
    int first_card_count = count(remaining_card_list.begin(), remaining_card_list.begin() + 4, remaining_card_list[0]);

    // condition 1: bird head, take first two repeated num
    // 14 is not divisible by 3, but 14 - 2 can
    if (remaining_card_list.size() % 3 != 0 && first_card_count >= 2) {
        // take out first two cards
        if (is_win(vector<int> (remaining_card_list.begin() + 2, remaining_card_list.end()))) {
            return true;
        }
    }

    // condition 2: triple duplicates
    if (first_card_count >= 3) {
        // take out first three cards
        if (is_win(vector<int> (remaining_card_list.begin() + 3, remaining_card_list.end()))) {
            return true;
        }
    }

    // condition 3: flush
    if (count(remaining_card_list.begin(), remaining_card_list.end(), remaining_card_list[0] + 1) > 0
        && count(remaining_card_list.begin(), remaining_card_list.end(), remaining_card_list[0] + 2) > 0) {
        // remove the flush from the remaining card list
        vector<int> removed_flush_list(remaining_card_list.begin() + 1, remaining_card_list.end());
        removed_flush_list.erase(find(removed_flush_list.begin(), removed_flush_list.end(), remaining_card_list[0] + 1));
        removed_flush_list.erase(find(removed_flush_list.begin(), removed_flush_list.end(), remaining_card_list[0] + 2));
        if (is_win(removed_flush_list)) {
            return true;
        }
    }

    // no condition satisfied, no win
    return false;
}

