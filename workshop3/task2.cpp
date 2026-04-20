#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int find_kth_max(vector<int>& vec, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap; // жульничаю

    for (int num : vec) {
        min_heap.push(num);
        if (min_heap.size() > k) min_heap.pop();
    }
    return min_heap.top();
}

int main() {
    vector<int> v = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << find_kth_max(v, k) << endl;
    assert(5 == find_kth_max(v, k));

    k = 4;
    cout << find_kth_max(v, k) << endl;
    assert(3 == find_kth_max(v, k));
}
