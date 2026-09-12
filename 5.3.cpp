//5.C 哈夫曼树
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;          // 字符，若非单节点，则为 '\0'
    int freq;         // 权重
    int id;           // 生成顺序编号（越早生成 id 越小）
    int firstPos;     // 若是单节点：首次出现位置；否则无意义
    Node *l, *r;

    // 单节点构造函数
    Node(char c, int f, int pos, int _id)
            : ch(c), freq(f), firstPos(pos), id(_id), l(NULL), r(NULL) {}

    // 非单节点构造函数
    Node(Node* left, Node* right, int f, int _id)
            : ch('\0'), freq(f), id(_id), l(left), r(right), firstPos(-1) {}
};

// 自定义比较器（最关键部分）
struct Cmp {
    bool operator()(Node* a, Node* b) const {
        if (a->freq != b->freq) return a->freq > b->freq;  // 权小优先

        bool a_single = (a->ch != '\0' && a->l == NULL && a->r == NULL);
        bool b_single = (b->ch != '\0' && b->l == NULL && b->r == NULL);

        // 单节点优先
        if (a_single != b_single) return a_single < b_single;

        // 若都是单节点：按首次出现顺序
        if (a_single && b_single) return a->firstPos > b->firstPos;

        // 若都是非单节点：按生成顺序（先生成的优先）
        return a->id > b->id;
    }
};

// 递归生成哈夫曼编码
void buildCode(Node* root, string path, unordered_map<char,string>& mp) {
    if (!root) return;
    if (root->ch != '\0') { // 叶子
        mp[root->ch] = path;
        return;
    }
    buildCode(root->l, path + "0", mp);
    buildCode(root->r, path + "1", mp);
}

int main() {
    string s;
    cin >> s;

    // 统计频率与首次出现位置
    unordered_map<char,int> freq;
    unordered_map<char,int> first;
    for (int i = 0; i < s.size(); i++) {
        if (!freq.count(s[i])) first[s[i]] = i;
        freq[s[i]]++;
    }

    // 优先队列（保证唯一结构）
    priority_queue<Node*, vector<Node*>, Cmp> pq;

    int idGen = 0; // 全局生成编号（越小越早）

    // 将所有单节点加入队列
    for (auto &p : freq) {
        pq.push(new Node(p.first, p.second, first[p.first], idGen++));
    }

    // 主循环：构造哈夫曼树
    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();

        // a 是左子树（优先级更高的那棵）
        Node* merged = new Node(a, b, a->freq + b->freq, idGen++);
        pq.push(merged);
    }

    // 最终根
    Node* root = pq.top();

    // 生成编码
    unordered_map<char,string> code;
    buildCode(root, "", code);

    // 输出（可根据题意格式调整）
    for (auto &p : code) {
        cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}