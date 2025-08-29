#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef std::pair<int, int> pii;

void Dijkstra(int start, const std::vector<std::vector<pii>>& graph) {
    std::vector<int> dist(graph.size(), INT_MAX);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (const auto& edge : graph[current]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[neighbor] > dist[current] + weight) {
                dist[neighbor] = dist[current] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < graph.size(); ++i) {
	std::cout << "Distance from " << start << " to " << i << ": " << dist[i] << std::endl;
    }
}
