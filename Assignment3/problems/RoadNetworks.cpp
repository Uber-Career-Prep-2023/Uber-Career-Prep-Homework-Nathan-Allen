// In some states, it is not possible to drive between any two towns because they are not connected to the same road network. 
// Given a list of towns and a list of pairs representing roads between towns, return the number of road networks. 
// (For example, a state in which all towns are connected by roads has 1 road network, and a state in which none of the towns are connected by roads has 0 road networks.)

// Technique: DFS (Depth-First Search) on 
// Approach: Build a graph of connected towns using an adjacency list
// Perform DFS on each town in graph, incrementing a counter only on return
// Return the counter


// Time complexity: O(v + e) - v is the number of vertices, e is the number of edges
// Space complexity: O(v + e)
// Time taken: 35 minutes


#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

// DFS helper function
void dfs(string town, unordered_map<string, vector<string>>& graph, map<string, bool>& visited) {
    if (visited[town] == true) {
        return;
    }

    // Mark the current town as visited
    visited[town] = true;
    
    // Recursively call dfs on each neighbor of the current town
    for (auto neighbor : graph[town]) {
        if (visited[neighbor] == false) {
            dfs(neighbor, graph, visited);
        }
    }
}

int roadNetworks(vector<string> towns, vector<pair<string, string>> roads) {
    // Build a graph of connected towns using an adjacency list
    unordered_map<string, vector<string>> graph;
    for (auto road : roads) {
        graph[road.first].push_back(road.second);
        graph[road.second].push_back(road.first);
    }

    // Perform DFS on each town, incrementing a counter only on return
    int counter = 0;
    map<string, bool> visited;
    
    for (auto town : graph) {
        if (visited[town.first] == false) {
            // Perform DFS on the current town, incrementing the counter only on return
            // to indicate that the current town is not connected to any other town
            dfs(town.first, graph, visited);
            counter++;
        }
    }

    // Return the counter
    return counter;
}


int main() {

    vector<string> towns = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};
    vector<pair<string, string>> roads = {
        {"Anchorage", "Homer"},
        {"Glacier Bay", "Gustavus"},
        {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"},
        {"Copper Center", "Fairbanks"},
        {"Healy", "Fairbanks"},
        {"Healy", "Anchorage"}
    };

    cout << roadNetworks(towns, roads) << endl;

    towns.clear(), roads.clear();

    towns = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"};
    roads = {
        {"Kona", "Volcano"},
        {"Volcano", "Hilo"},
        {"Lahaina", "Hana"},
        {"Kahului", "Haiku"},
        {"Hana", "Haiku"},
        {"Kahului", "Lahaina"},
        {"Princeville", "Lihue"},
        {"Lihue", "Waimea"}
    };

    cout << roadNetworks(towns, roads) << endl;
    
    return 0;
}
