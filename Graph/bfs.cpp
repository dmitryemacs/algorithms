#include <iostream>
#include <vector>
#include <queue>

// Поиск в ширину графа
void BFS(int start, const std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
	std::cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
