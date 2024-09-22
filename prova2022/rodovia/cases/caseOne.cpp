#include <iostream>
#include <vector>

int main () {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<bool>> v(n + 1, std::vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        v[x][y] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && v[i][j] == false) {
                std::cout << i << " " << j;
                return 0;
            }
        }
    }
    std::cout << -1;
    return 0;
}

// 4 6
// 1 4
// 1 2
// 2 4
// 3 2
// 4 3
// 1 3