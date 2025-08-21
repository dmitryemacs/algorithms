#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void printGraph();
    void DFS(int startVertex);

private:
    int vertices; // Количество вершин
    std::vector<std::vector<int>> adjList; // Список смежности
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w); // Добавляем w в список смежности v
    adjList[w].push_back(v); // Добавляем v в список смежности w (для неориентированного графа)
}

void Graph::printGraph() {
    for (int v = 0; v < vertices; ++v) {
        std::cout << "Вершина " << v << ": ";
        for (int w : adjList[v]) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(vertices, false); // Вектор для отслеживания посещенных вершин
    std::stack<int> stack; // Стек для хранения вершин

    stack.push(startVertex); // Начинаем с начальной вершины

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            visited[vertex] = true; // Помечаем вершину как посещенную
            std::cout << vertex << " ";

            // Добавляем все непосещенные соседние вершины в стек
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    Graph g(5); // Создаем граф с 5 вершинами

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Граф:" << std::endl;
    g.printGraph();

    std::cout << "Поиск в глубину, начиная с вершины 0:" << std::endl;
    g.DFS(0);

    return 0;
}
