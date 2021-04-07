#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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

/* Question 4
 * @ Description
 *
 * 小明是一名算法工程师，同时也是一名铲屎官。某天，他突发奇想，想从猫咪的视频里挖掘一些猫咪的运动信息。为了提取运动信息，他需要从视频的每一帧提取“猫咪特征”。
 * 一个猫咪特征是一个两维的vector<x, y>。如果x_1=x_2 and y_1=y_2，那么这俩是同一个特征。
 * 因此，如果喵咪特征连续一致，可以认为喵咪在运动。也就是说，如果特征<a, b>在持续帧里出现，那么它将构成特征运动。
 * 比如，特征<a, b>在第2/3/4/7/8帧出现，那么该特征将形成两个特征运动2-3-4 和7-8。
 * 现在，给定每一帧的特征，特征的数量可能不一样。小明期望能找到最长的特征运动。
 *
 * @ Input Example:
 * 第一行包含一个正整数N，代表测试用例的个数。
 *
 * 每个测试用例的第一行包含一个正整数M，代表视频的帧数。
 *
 * 接下来的M行，每行代表一帧。其中，第一个数字是该帧的特征个数，接下来的数字是在特征的取值；比如样例输入第三行里，2代表该帧有两个猫咪特征，<1，1>和<2，2>
 * 所有用例的输入特征总数和<100000
 *
 * N满足1≤N≤100000，M满足1≤M≤10000，一帧的特征个数满足 ≤ 10000。
 * 特征取值均为非负整数。
 *
 * 1
 * 8
 * 2 1 1 2 2
 * 2 1 1 1 4
 * 2 1 1 2 2
 * 2 2 2 1 4
 * 0
 * 0
 * 1 1 1
 * 1 1 1
 *
 * @ Output Example:
 * 对每一个测试用例，输出特征运动的长度作为一行
 *
 * 3
 * 特征<1,1>在连续的帧中连续出现3次，相比其他特征连续出现的次数大，所以输出3
 */

void question4();

/* Question 5
 * @ Description
 * 小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。
 * 由于经费有限，希望能够通过合理的路线安排尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。
 *
 * @ Input Example:
 * 城市个数n（1<n≤20，包括北京）
 *
 * 城市间的车票价钱 n行n列的矩阵 m[n][n]
 *
 * 4
 * 0 2 6 5
 * 2 0 4 4
 * 6 4 0 2
 * 5 4 2 0
 *
 * 共 4 个城市，城市 1 和城市 1 的车费为0，城市 1 和城市 2 之间的车费为 2，城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，依次类推。
 * 假设任意两个城市之间均有单程票可购买，且票价在1000元以内，无需考虑极端情况。
 *
 * @ Output Example:
 * 最小车费花销 s
 *
 * 13
 */

void question5();
void dp_tsp(vector<vector<int>> city_dis);

int main() {
    // question 1
    // question1();

    // question 2
    // question2();

    // question 3
    // question3();

    // question 4
    // question4();

    // question 5
    question5();

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

// question 4
void question4() {
    int total_move = 0;
    cin >> total_move;
    while (total_move--) {
        int sub_move = 0;
        cin >> sub_move;
        // first map keeps track of current set of movement
        map<pair<int, int>, int> cur_move_dic;
        // second map keeps track of previous accumulated sets of movement
        map<pair<int, int>, int> prev_move_dic;
        pair<int, int> move;
        int count = 0;
        while (sub_move--) {
            int size = 0;
            cin >> size;
            for (int i = 0; i < size; i++) {
                cin >> move.first >> move.second;
                if (prev_move_dic.count(move)) {
                    cur_move_dic[move] = prev_move_dic[move] + 1;
                } else {
                    cur_move_dic[move] += 1;
                }
                count = max(count, cur_move_dic[move]);
            }
            prev_move_dic.clear();
            prev_move_dic.swap(cur_move_dic);
        }
        cout << count << endl;
    }
}

// question 5
void question5() {
    int city_num = 0;
    cin >> city_num;
    vector<vector<int>> city_dis(city_num, vector<int>(city_num));
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            cin >> city_dis[i][j];
        }
    }
    dp_tsp(city_dis);
}

/* 这题太难了，参考https://www.geek-share.com/detail/2802225362.html
 * 1 出发城市：0 ；经过{1，2，3}各城市有且仅有一次，再回到出发城市0
 * 2 dp[i]{v}:表示从城市i出发，经过集合v，回到出发点0 的最段路径
 * 3 最后结果dp[0]{1,2,3};
 *
 * dp[0]{1,2,3}=min(dis[0][1]+dp[1]{2,3}，dis[0][2]+dp[2]{1,3}，dis[0][3]+dp[3]{1,2})
 *
 * dp[i]{v}=min(dis[i][k]+dp[k]{v-k});(i不属于v，k属于v)
 * 初始条件：
 * dp[i]{}=dis[i][0];//从i出发，不经过任何城市，回到城市0
 *
 * 1 怎么表示集合V？
 * 除出发城市0 外剩下的城市为{1，2，3}，则剩下城市所包含的所有子集为
 * {}，{1}，{2}，{3}，{1，2}，{1，3}，{2，3}，{1，2，3}正好2^（n-1）个
 *
 * 设dp[i][j]中j为除出发点之外剩下的城市集合，则j的二进制中第i为正好对应第i个城市是否在j中。如：dp[0][7]=dp[0]{3,2,1} dp[0][5]=dp[0]{3,1}。
 * 则dp表的列数为2^（n-1）列：（可写为1<<(n-1)）
 *
 * 2 怎么查看集合j中某一位的状态？（判断城市k是否在集合中
 * 采用(j>>(k-1))&1==1判断，等于1则在，等于0则不在
 * 如：判断城市1，2是否在集合j=5={3，1}中；
 * (j>>(1-1))&1=5&1=101&001=1:则城市1在集合j=5中
 * (j>>(2-1))&1=2&1=10&01=0:则城市2不在集合j=5中
 *
 * 3 怎么将集合j中某个城市置0？（即从集合j中取出某个城市k）
 * j^(1<<(k-1)) (和0异或不变，和1异或取反)
 * 如从集合j=7={3，2，1}中取出城市2变为j={3,1}=101=5;
 * 7^(1<<(2-1))=7 ^ 2=111 ^ 010=101=5;
 */

void dp_tsp(vector<vector<int>> dis) {
    int city_num = dis.size();
    // dp[i][j] 代表了dp[i]{v}的最小值
    vector<vector<int>>dp(city_num, vector<int>(1 << (city_num - 1)));//n行 2^(n-1)列

    //初始化dp表的第一列：dp[k]{}
    for (int i = 0; i < city_num; i++) {
        dp[i][0] = dis[i][0];
    }
//填dp表的剩余列：1—（2^(n-1)-1）列
    for (int j = 1; j < (1 << (city_num - 1));j++)
    {
        for (int i = 0; i < city_num; i++)
        {
//将其初始化为最大值
            dp[i][j] = 10000 ;
//如果城市i在集合j中，跳过
            if (((j >> (i - 1)) & 1) == 1)
                continue;
//城市i不在j中，则dp[i]{v}=min(dis[i][k]+dp[k]{v-k});(i不属于v，k属于v)
            if (((j >> (i - 1)) & 1) == 0)
            {

                for (int k = 1; k < city_num; k++)
                {
//除i以外所有在j中的城市城市
                    if ((j >> (k - 1)) & 1 == 1)
                    {
//取出城市k
                        if (dp[i][j]>dis[i][k] + dp[k][j ^ (1 << (k - 1))])
                        {
//取值小的
                            dp[i][j] = dis[i][k] + dp[k][j ^ (1 << (k - 1))];
                        }
                    }
                }
            }
        }
    }
//输出结果：dp[0][7]=dp[0]{1,2,3}
    cout << dp[0][(1<<(city_num-1))-1] << endl;
}
