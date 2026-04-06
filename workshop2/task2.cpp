//в прошлый раз было посложнее

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int kthElSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    if (n == 0) return 0;

    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {

        int mid = low + (high - low) / 2;

        int count = 0;
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

void test() {

    vector<vector<int>> m1 = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    assert(kthElSmallest(m1, 8) == 13);

    vector<vector<int>> m2 = {
        {1, 2},
        {1, 3}
    };
    assert(kthElSmallest(m2, 2) == 1);
    assert(kthElSmallest(m2, 3) == 2);

    vector<vector<int>> m3 = {{5}};
    assert(kthElSmallest(m3, 1) == 5);

    vector<vector<int>> m4 = {
        {1, 10, 20},
        {5, 15, 25},
        {8, 20, 30}
    };
    assert(kthElSmallest(m4, 1) == 1);
    assert(kthElSmallest(m4, 9) == 30);

    cout << "Все тесты для kthElSmallest пройдены успешно!" << endl;
}


int main() {
    test();
}
