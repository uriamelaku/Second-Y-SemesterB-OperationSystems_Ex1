// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>
using namespace std;

// Number of vertices in the graph
#define V 3

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// Function to read the graph from standard input, line by line
bool readGraph(int graph[V][V]) 
{
    cout << "Enter the adjacency matrix for the graph (" << V << "x" << V << ") one line at a time:" << endl;
    for (int i = 0; i < V; ++i) 
    {
        // Read a line of input
        string line;
        getline(cin, line);
        

        // Check for extra spaces
        for (size_t j = 0; j < line.length(); ++j) {
            if (line[j] == ' ' && (j == 0 || j == line.length() - 1 || line[j + 1] == ' ')) {
                cerr << "ERROR: Invalid input in line " << i + 1 << ". Extra spaces detected." << endl;
                return false;
            }
        }

        // Parse the line
        istringstream iss(line);
        for (int j = 0; j < V; ++j) 
        {
            int weight;
            if (!(iss >> weight)) 
            {
                cerr << "ERROR: Invalid input in line " << i + 1 << ". Please provide exactly " << V << " integers per line." << endl;
                return false;
            }
            if (weight < 0) 
            {
                cerr << "ERROR: Negative edge weight detected. Dijkstra's algorithm does not support negative weights." << endl;
                return false;
            }
            if (weight != 0 && i == j) 
            {
                cerr << "ERROR: every edge from vertex to himself must be 0" << endl;
                return false;
            }
            graph[i][j] = weight;
        }

        // Check for extra values
        string leftover;
        if (iss >> leftover) 
        {
            cerr << "ERROR: Too many values in line " << i + 1 << ". Please provide exactly " << V << " integers per line." << endl;
            return false;
        }
    }
    return true;
}

int main() {
    int graph[V][V];

    if (readGraph(graph)) 
    {
        dijkstra(graph, 0);
    }
    else 
    {
        cerr << "Failed to read graph. Please try again." << endl;
    }

    return 0;
}