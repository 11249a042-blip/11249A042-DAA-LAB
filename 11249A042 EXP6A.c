#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int min_dist(int dist[], bool visited[]) {
    int minimum = INT_MAX, ind;
    for(int k = 0; k < 6; k++) {
        if(!visited[k] && dist[k] <= minimum) {
            minimum = dist[k];
            ind = k;
        }
    }
    return ind;
}

void greedy_dijsktra(int graph[6][6], int src) {
    int dist[6];
    bool visited[6];
    for(int k = 0; k < 6; k++) {
        dist[k] = INT_MAX;
        visited[k] = false;
    }
    dist[src] = 0;

    for(int k = 0; k < 6; k++) {
        int m = min_dist(dist, visited);
        visited[m] = true;
        for(int j = 0; j < 6; j++) {
            if(!visited[j] && graph[m][j] && dist[m] != INT_MAX &&
               dist[m] + graph[m][j] < dist[j]) {
                dist[j] = dist[m] + graph[m][j];
            }
        }
    }

    printf("Vertex\t\tdist from source vertex\n");
    for(int k = 0; k < 6; k++) {
        printf("%c\t\t\t%d\n", 'A' + k, dist[k]);
    }
}

int main() {
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0}, 
        {1, 0, 0, 5, 1, 0}, 
        {2, 0, 0, 2, 3, 0}, 
        {0, 5, 2, 0, 2, 2}, 
        {0, 1, 3, 2, 0, 1}, 
        {0, 0, 0, 2, 1, 0}
    };
    greedy_dijsktra(graph, 0);
    return 0;
}
