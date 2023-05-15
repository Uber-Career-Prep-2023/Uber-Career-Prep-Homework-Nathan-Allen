// Given an array of pairs of values representing edges in an unweighted graph, 
// create the equivalent adjacency list/set representation (a map from element to a list or set of elements). 
// Pairs represent directed edges: (A, B) means there is an edge from A to B.

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;


// Building graph representation
map<int, set<int>> adjacencySet(vector<pair<int, int>> edges)
{
    // map from node to set of neighbors
    map<int, set<int>> adjSet;
    for (auto edge: edges) {
        adjSet[edge.first].insert(edge.second);
    }
    return adjSet;
}

// BFS traversal
bool bfs(int target, map<int, set<int>> graph)
{
    // queue for BFS traversal, set for visited nodes
    queue<int> q;
    set<int> visited;

    // start at first node in graph
    q.push(graph.begin()->first);
    visited.insert(graph.begin()->first);

    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // check if target is found; if so, return true
        if (curr == target) {
            return true;
        }

        // add all unvisited neighbors to queue and visited set
        for (auto node: graph[curr]) {
            if (visited.find(node) == visited.end()) {
                q.push(node);
                visited.insert(node);
            }
        }
    }
    // if target is not found, return false
    return false;
}

// DFS traversal
bool dfs(int target, map<int, set<int>> graph)
{
    
}



// Topological sort helper function (DFS)
void dfs_tp(int node, map<int, set<int>>& graph, stack<int>& explored, map<int, bool>& visited)
{
    // mark node as visited
    visited[node] = true;
    
    // recursively call dfs_tp on all unvisited neighbors
    for (auto neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs_tp(neighbor, graph, explored, visited);
        }
    }

    // push node to explored stack
    explored.push(node);
}

// Topological sort
vector<int> topologicalSort(map<int, set<int>> graph)
{
    stack<int> explored;
    map<int, bool> visited;
    dfs_tp(graph.begin()->first, graph, explored, visited);

    vector<int> sorted;
    while (!explored.empty()) {
        sorted.push_back(explored.top());
        explored.pop();
    }

    return sorted;
}



int main() {

    // Testing adjacency list builder function
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    map<int, set<int>> adjSet = adjacencySet(edges);
    for (auto node: adjSet) {
        cout << node.first << ": ";
        for (auto edge: node.second) {
            cout << edge << " ";
        }
        cout << endl;
    }

    // Testing BFS
    cout << "BFS: " << bfs(0, adjSet) << endl; // prints 1 (true)

    // Testing DFS
    cout << "DFS: " << dfs(0, adjSet) << endl; // prints 1 (true)

    // Testing topological sort
    vector<int> sorted = topologicalSort(adjSet);
    for (auto node: sorted) {
        cout << node << " ";
    } // prints 1 3 2 0

    cout << endl;

    return 0;
}