#include<iostream>
#define MEMBER 1
#define NON_MEMBER 0
#define INFINITY_VAL 999
#define SIZE 10

using namespace std;

class ShortestPath {
private:
    int graph[SIZE][SIZE], queue[SIZE];

public:
    int front, rear, n;

    void buildGraph();
    void dijkstra(int src, int dest);
    void insertQueue(int index);
    int deleteQueue(int i);
};

void ShortestPath::buildGraph() {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << "\n Enter the edge of V" << i << " to V" << j << ": ";
            cin >> graph[i][j];
        }
        cout << "\n";
    }
}

void ShortestPath::insertQueue(int index) {
    queue[index] = MEMBER;
}

int ShortestPath::deleteQueue(int i) {
    if (queue[i] == MEMBER)
        return i;
    return INFINITY_VAL;
}

void ShortestPath::dijkstra(int src, int dest) {
    int small, dist[SIZE], current, start, new1;
    int temp, i;

    for (i = 0; i <= n; i++) {
        queue[i] = NON_MEMBER;
        dist[i] = INFINITY_VAL;
    }

    queue[src] = MEMBER;
    dist[src] = 0;
    current = src;

    while (current != dest) {
        small = INFINITY_VAL;
        start = dist[current];

        for (i = 1; i <= n; i++) {
            if (queue[i] == NON_MEMBER) {
                new1 = start + graph[current][i];

                if (new1 < dist[i])
                    dist[i] = new1;

                if (dist[i] < small) {
                    small = dist[i];
                    temp = i;
                }
            }
        }

        current = temp;
        insertQueue(current);
    }
}

int main() {
    int src, dest, pathNode;
    ShortestPath obj;

    cout << "\n Enter the number of vertices: ";
    cin >> obj.n;

    obj.buildGraph();

    cout << "\n Enter the source: ";
    cin >> src;

    cout << "\n Enter the destination: ";
    cin >> dest;

    obj.dijkstra(src, dest);

    cout << "\n The shortest path is: ";
    obj.front = 1;
    obj.rear = obj.n;

    while (obj.front <= obj.rear) {
        pathNode = obj.deleteQueue(obj.front);

        if (pathNode != INFINITY_VAL)
            cout << " " << pathNode;

        obj.front++;
    }

    return 0;
}
