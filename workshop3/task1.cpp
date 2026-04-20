#include <bits/stdc++.h>
using namespace std;


struct node {
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> level_tree(node* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<node*> q;
    q.push(root);

    // тихо, не спеша, без суеты перебираем сверху вниз
    while (!q.empty()) {
        int size = q.size();
        vector<int> cur_level;

        for (int i = 0; i < size; i++) {
            node* n = q.front();
            q.pop();
            cur_level.push_back(n->val);

            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }

        res.push_back(cur_level);
    }
    return res;
}


int main() {
    node* root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    root->left->left = new node(8);

    auto res = level_tree(root);
    for (auto& lvl: res) {
        for (auto i: lvl) {
            cout << i << " ";
        }
        cout << endl;
    }

    //память не чистил, легко рекурсией сверху делается
}
