#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define INF 1000000000

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INF)); // ответ
    queue<pair<int, int>> q; // очередь для BFS
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // чтобы не писать отдельно 4 варианта
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return dist;
}





signed main() // На литкоде зашла
{
    vector<vector<int>> mat1 = {{0,0,0}, {0,1,0}, {1,1,1}};
    vector<vector<int>> ans1 = {{0,0,0}, {0,1,0}, {1,2,1}};
    assert(updateMatrix(mat1) == ans1);
    
    vector<vector<int>> mat2 = {{0,0}, {0,0}};
    vector<vector<int>> ans2 = {{0,0}, {0,0}};
    assert(updateMatrix(mat2) == ans2);
    
    cout << "Тесты пройдены" << endl;
}
