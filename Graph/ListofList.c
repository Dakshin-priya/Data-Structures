#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input[7][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {3, 4}, {2, 3}};
    int nov = 5;  // Number of vertices
    int noe = 7;  // Number of edges

    vector<vector<int>> graph(nov); // Correcting the vector initialization

    // Constructing the graph
    for (int i = 0; i < noe; i++) {
        int v1 = input[i][0];
        int v2 = input[i][1];

        // Corrected: Add actual edges instead of pushing v1 twice
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // Display the adjacency list
    for (int v1 = 0; v1 < nov; v1++) {
        printf("%d:", v1);
        for (int v2 = 0; v2 < graph[v1].size(); v2++) {
            printf(" %d", graph[v1][v2]);
        }
        printf("\n");
    }

    return 0;
}
