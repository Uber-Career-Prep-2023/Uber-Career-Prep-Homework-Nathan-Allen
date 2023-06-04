// Given a list of courses that a student needs to take to complete their major and a map of courses to their prerequisites, 
// return a valid order for them to take their courses assuming they only take one course for their major at once.


// Technique: DFS & topological sort
// Approach: Build a directed graph from the prerequisites map
// Modified DFS on the directed graph and push explored courses onto vector
// Reverse the vector to get the topological sort, which is the order of courses 

// Time complexity: O(V + E)
// Space complexity: O(V + E)
// Time taken: 30 minutes



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void dfs(unordered_map<string, vector<string>>& graph, string course, vector<string>& s, unordered_map<string, bool>& visited)
{
    visited[course] = true;

    for (auto prereq : graph[course]) {
        if (!visited[prereq]) {
            dfs(graph, prereq, s, visited);
        }
    }

    s.push_back(course);
}

vector<string> findOrder(vector<string>& courses, unordered_map<string, vector<string>>& prereqs)
{
    vector<string> res;

    // Build a directed graph from the prerequisites map
    unordered_map<string, vector<string>> graph;
    for (auto course : courses) {
        graph[course] = {};
    }

    // Map prerequisities to courses
    for (auto prereq : prereqs) {
        for (auto course : prereq.second) {
            graph[course].push_back(prereq.first);
        }
    }

    // DFS and Topological Sort
    unordered_map<string, bool> visited;
    
    for (auto course : courses) {
        if (!visited[course]) {
            dfs(graph, course, res, visited);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<string> courses = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};
    unordered_map<string, vector<string>> prereqs;

    prereqs["Data Structures"] = {"Intro to Programming"};
    prereqs["Advanced Algorithms"] = {"Data Structures"};
    prereqs["Operating Systems"] = {"Advanced Algorithms"};
    prereqs["Databases"] = {"Advanced Algorithms"};

    vector<string> res = findOrder(courses, prereqs);
    cout << "Order of courses: " << endl;
    for (auto course : res) {
        cout << course << endl;
    }
    cout << endl;

    courses.clear(), prereqs.clear(), res.clear();

    courses = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};
    prereqs["Contemporary Literature"] = {"Intro to Writing"};
    prereqs["Ancient Literature"] = {"Intro to Writing"};
    prereqs["Comparative Literature"] = {"Ancient Literature", "Contemporary Literature"};
    prereqs["Plays & Screenplays"] = {"Intro to Writing"};

    res = findOrder(courses, prereqs);
    cout << "Order of courses: " << endl;
    for (auto course : res) {
        cout << course << endl;
    }

    return 0;
}
