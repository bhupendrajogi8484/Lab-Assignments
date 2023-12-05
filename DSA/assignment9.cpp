#include<iostream>
#define SIZE 20
#define MAX_WEIGHT 32767

using namespace std;

class MST {
private:
    int graph[SIZE][SIZE];
    int nodes;

public:
    MST();
    void prim();
    void getdata();
};

MST::MST() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            graph[i][j] = 0;
}

void MST::prim() {
    int select[SIZE], i, j, k;
    int minDist, v1, v2, total = 0;

    for (i = 0; i < nodes; i++)
        select[i] = 0; // initialize the selected vertices list.

    cout << "\n The minimum spanning tree is";

    select[0] = 1;

    for (k = 1; k < nodes; k++) {
        minDist = MAX_WEIGHT;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if (graph[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j]))) {
                    if (graph[i][j] < minDist) {
                        minDist = graph[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }
        cout << "\n Edge (" << v1 << " " << v2 << ") and weight = " << minDist;
        select[v1] = select[v2] = 1;
        total = total + minDist;
    }

    cout << "\n Total path length is " << total;
}

void MST::getdata() {
    int v1, v2, length, n;
    cout << "\n Enter the number of nodes in the tree: ";
    cin >> nodes;
    cout << "\n Enter the number of edges in the tree: ";
    cin >> n;
    cout << "\n Enter edges and weight:";
    for (int i = 0; i < n; i++) {
        cout << "\n Enter edge by v1 and v2: ";
        cin >> v1 >> v2;
        cout << "\n Enter corresponding weight: ";
        cin >> length;
        graph[v1][v2] = graph[v2][v1] = length;
    }
}

int main() {
    MST obj;
    cout << "\n Prim's algorithm";
    obj.getdata();
    cout << "\n\t";
    obj.prim();
    return 0;
}
