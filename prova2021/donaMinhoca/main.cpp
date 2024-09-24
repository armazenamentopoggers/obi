//nao finalizado

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int const MAXN = 50100;
int dist[MAXN], size[MAXN], d = 0, qtd = 0;
std::vector<bool> visitedDfs(MAXN, false);

void bfs(int v, int n, std::vector<std::vector<int>> g) {
    std::queue<int> queue;
    std::vector<bool> visited(n + 1, false);
    queue.push(v);

    while (!queue.empty()) {
        int aux = queue.front();
        queue.pop();
        visited[aux] = true;

        for (int i = 0; i < g[aux].size(); i++) {
            int curr = g[aux][i];
            if (!visited[curr]) {
                queue.push(curr);
                visited[curr] = true;
                dist[curr] = dist[aux] + 1;
            }
        }
    }
}

void dfs(int v, int n, int dis, std::vector<std::vector<int>> g) {
    int last = v;
    visitedDfs[v] = true;
    if (g[v].size() == 1 && dis == d) qtd++;
    for (int i = 0; i < g[v].size(); i++) {
        int curr = g[v][i];
        
        if (!visitedDfs[curr]) {
            visitedDfs[curr] = true;
            size[curr] = size[last] + 1;
            dfs(curr, n, dis + 1, g);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1, n, graph);
    int max = -1, v = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max) {
            max = dist[i];
            v = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = 0;
    }
    bfs(v, n, graph);
    for (int i = 1; i <= n; i++) {
        d = std::max(d, dist[i]);
    }
    d++;
    for (int i = 1; i <= n; i++) {
        visitedDfs.clear();
        dfs(i, n, 1, graph);
    }
    std::cout << d << std::endl << qtd;
}