#include <iostream>
#include <vector>
#include <string>         // std::string
#include <algorithm>
#include <numeric>
#include <queue>

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
void question2();

/* Question 3
 * @ Description
 * 产品经理(PM)有很多好的idea，而这些idea需要程序员实现。现在有N个PM，在某个时间会想出一个 idea，每个 idea 有提出时间、所需时间和优先等级。
 * 对于一个PM来说，最想实现的idea首先考虑优先等级高的，相同的情况下优先所需时间最小的，还相同的情况下选择最早想出的，没有 PM 会在同一时刻提出两个 idea。
 * 同时有M个程序员，每个程序员空闲的时候就会查看每个PM尚未执行并且最想完成的一个idea,然后从中挑选出所需时间最小的一个idea独立实现，如果所需时间相同则选择PM序号最小的。
 * 直到完成了idea才会重复上述操作。如果有多个同时处于空闲状态的程序员，那么他们会依次进行查看idea的操作。
 * 求每个idea实现的时间。
 *
 * @ Input Example
 * 输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。
 * 随后有P行，每行有4个数字，分别是PM序号、提出时间、优先等级和所需时间。
 *
 * 2 2 5
 * 1 1 1 2
 * 1 2 1 1
 * 1 3 2 2
 * 2 1 1 2
 * 2 3 5 5
 *
 * @ Output Example
 * 输出P行，分别表示每个idea实现的时间点。
 *
 * 3
 * 4
 * 5
 * 3
 * 9
 */
// 这题太难了，参考大佬：https://blog.csdn.net/qq_41922018/article/details/104798916
void question3();

int main() {
    // question1
    // question1();

    // question2
    // question2();

    // question3
    question3();

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

struct idea{
    int id,pm,time,priority,cost;
    idea(int id_,int pm_,int time_,int priority_,int cost_):id(id_),pm(pm_),time(time_),priority(priority_),cost(cost_){}
};
bool cmp_time(const idea& idea1,const idea& idea2){
    return idea1.time<idea2.time;
}
struct cmp_pm{
    bool operator()(const idea&a,const idea& b){
        if(a.priority!=b.priority)
            return a.priority<b.priority;
        if(a.cost!=b.cost)
            return a.cost>b.cost;
        return a.time>b.time;
    }
};
struct cmp_worker{
    bool operator()(const idea& a,const idea& b){
        if(a.cost!=b.cost)
            return a.cost>b.cost;
        return a.pm>b.pm;
    }
};
priority_queue<idea,vector<idea>,cmp_pm> cur_ideas[3010];
void question3(){
    int N,M,P;
    cin>>N>>M>>P;
    int i,pm,t,l,cost;
    vector<idea> ideas;
    for(i=0;i<P;i++){
        cin>>pm>>t>>l>>cost;
        ideas.push_back(idea(i,pm-1,t,l,cost));
    }
    vector<int> workers(M,0);
    vector<int> finished(P);
    sort(ideas.begin(),ideas.end(),cmp_time);
    int count=0,p=0,time=1;
    while(count<P){
        while(p<P&&ideas[p].time<=time){
            int pm_=ideas[p].pm;
            cur_ideas[pm_].push(ideas[p]);
            p++;
        }
        priority_queue<idea,vector<idea>,cmp_worker> Q;
        for(i=0;i<N;i++){
            if(!cur_ideas[i].empty()){
                Q.push(cur_ideas[i].top());
            }
        }
        for(i=0;i<M;i++){
            if(workers[i]>0){
                workers[i]--;
            }
            if(workers[i]==0&&!Q.empty()){
                idea tmp=Q.top();
                Q.pop();
                workers[i]=tmp.cost;
                finished[tmp.id]=time+tmp.cost;
                cur_ideas[tmp.pm].pop();
                if(!cur_ideas[tmp.pm].empty())
                    Q.push(cur_ideas[tmp.pm].top());
                count++;
            }
        }
        time++;
    }
    for(i=0;i<P;i++)
        cout<<finished[i]<<endl;
}
