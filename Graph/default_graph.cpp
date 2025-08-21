#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void printGraph();

private:
    int vertices; // Количество вершин
    std::vector<std::vector<int>> adjList; // Список смежности
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

// Метод для добавления ребра
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

int main() {
    Graph g(5); // Создаем граф с 5 вершинами

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
