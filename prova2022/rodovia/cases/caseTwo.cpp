#include <iostream>
#include <vector>
#include <map>
#include <numeric>

int main () {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::map<int, bool>> v(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        v[x][y] = true;
        v[y][x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            std::cout << -1;
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            if (v[j].size() == 0) {
                std::cout << -1;
                return 0;
            } else if (v[i].find(j) == v[i].end() && i != j) {
                std::cout << i << " " << j;
                return 0;
            }
        }
    }
    std::cout << -1;
    return 0;
}