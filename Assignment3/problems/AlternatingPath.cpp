// Given an origin and a destination in a directed graph in which edges can be blue or red, 
// determine the length of the shortest path from the origin to the destination 
// in which the edges traversed alternate in color. Return -1 if no such path exists.

// Technique: Modified BFS to detect shortest path 
// Approach: Build a directed graph with blue and red edges.
// Use a queue to store the current node, the color of the edge that led to the current node, and the distance from the origin.
// While the queue is not empty, dequeue the front of the queue.
// If the current node is the destination, return the distance from the origin.
// For each neighbor of the current node, if the color of the edge that led to the neighbor is different from the color of the edge that led to the current node, 
// enqueue the tuple of neighbor, color and distance from origin + 1


// Time complexity: O(V + E)
// Space complexity: O(V + E)
// Time taken: ~50 minutes - tuple syntax was confusing and I had to look up how to use it


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <string>
#include <utility>

using namespace std;

unordered_map<string, vector<pair<string, string>>> buildGraph(vector<tuple<string, string, string>> edges)
{
    unordered_map<string, vector<pair<string, string>>> graph;

    for (int i = 0; i < edges.size(); i++)
    {
        string origin = get<0>(edges[i]);
        string destination = get<1>(edges[i]);
        string color = get<2>(edges[i]);

        graph[origin].push_back(make_pair(destination, color));
    }

    return graph;
}

int AlternatingPath(vector<tuple<string, string, string>> edges, string origin, string destination)
{
    unordered_map<string, vector<pair<string, string>>> graph = buildGraph(edges);

    queue<tuple<string, string, int>> q;
    q.push(make_tuple(origin, "", 0));


    while (!q.empty())
    {
        tuple<string, string, int> curr = q.front();
        q.pop();

        string currCity = get<0>(curr);
        string currColor = get<1>(curr);
        int currDist = get<2>(curr);

        if (currCity == destination)
        {
            return currDist;
        }

        for (int i = 0; i < graph[currCity].size(); i++)
        {
            string neighbor = graph[currCity][i].first;
            string neighborColor = graph[currCity][i].second;

            if (neighborColor != currColor)
            {
                q.push(make_tuple(neighbor, neighborColor, currDist + 1));
            }
        }

    }
    return -1;
}

int main()
{
    vector<tuple<string, string, string>> edges = { make_tuple("A", "B", "blue"), 
    make_tuple("A", "C", "red"), make_tuple("B", "D", "blue"), 
    make_tuple("B", "E", "blue"), make_tuple("C", "B", "red"), 
    make_tuple("D", "C", "blue"), make_tuple("A", "D", "red"), 
    make_tuple("D", "E", "red"), make_tuple("E", "C", "red")
    };

    cout << AlternatingPath(edges, "A", "E") << endl;
    cout << AlternatingPath(edges, "E", "D") << endl;

}