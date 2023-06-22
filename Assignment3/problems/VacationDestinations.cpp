// Given an origin city, a maximum travel time k, and pairs of destinations that can be reached directly from each other with corresponding travel times in hours
// return the number of destinations within k hours of the origin
// Assume that having a stopover in a city adds an hour of travel time

// Technique: BFS
// Approach: Build graph of cities as nodes, edges as travel times between them
// Use BFS to traverse graph, keeping track of time taken to reach each city using queue
// If time taken to reach a city (that isn't visited) is less than or equal to k, increment numDestinations


// Time complexity: O(v + e * n) - v is number of cities, e is number of edges, n is equal to max numbers of neighbors a city has
// Space complexity: O(v + e) - v is number of cities, e is number of edges
// Time taken: 40 mins

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <string>
#include <utility>
#include <set>

using namespace std;

unordered_map<string, vector<pair<string, double>>> buildGraph(vector<tuple<string, string, double>> edges)
{
    unordered_map<string, vector<pair<string, double>>> graph;
    for (auto edge : edges)
    {   
        string city1 = get<0>(edge);
        string city2 = get<1>(edge);
        double time = get<2>(edge);

        if (graph.find(city1) == graph.end())
        {
            graph[city1] = vector<pair<string, double>>();
        }

        if (graph.find(city2) == graph.end())
        {
            graph[city2] = vector<pair<string, double>>();
        }
        
        graph[city1].push_back(make_pair(city2, time));
        graph[city2].push_back(make_pair(city1, time));
    }
    return graph;
}


int numDestinations(string origin, int k, vector<tuple<string, string, double>> edges)
{
    unordered_map<string, vector<pair<string, double>>> graph = buildGraph(edges);
    int numDestinations = 0;
    queue<pair<string, double>> q;
    set<string> visited;
    q.push(make_pair(origin, -1));

    while (!q.empty())
    {
        pair<string, double> curr = q.front();
        q.pop();
        string currCity = curr.first;
        double currTime = curr.second;

        if (visited.find(currCity) != visited.end())
        {
            continue;
        }
        visited.insert(currCity);

        if (currTime != -1 && currTime <= k)
        {
            numDestinations++;
        }
        
        for (auto neighbor : graph[currCity])
        {
            
                q.push(make_pair(neighbor.first, currTime + neighbor.second + 1));
        }
    }
    return numDestinations;
    
}




int main()
{
    vector<tuple<string, string, double>> edges = {
    make_tuple("Boston", "New York", 4), 
    make_tuple("New York", "Philadelphia", 2), 
    make_tuple("Boston", "Newport", 1.5), 
    make_tuple("Washington, D.C.", "Harper's Ferry", 1), 
    make_tuple("Boston", "Portland", 2.5), 
    make_tuple("Philadelphia", "Washington, D.C.", 2.5)};
    
    int x = numDestinations("New York", 5, edges);
    int y = numDestinations("New York", 7, edges);
    int z = numDestinations("New York", 8, edges);
    cout << x << " " << y << " " << z << endl;
}