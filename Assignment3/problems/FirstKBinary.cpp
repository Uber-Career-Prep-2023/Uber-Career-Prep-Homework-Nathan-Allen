// Given a number, k, return an array of the first k binary numbers, represented as strings.

// Technique: Queue
// Approach: Use a queue to store the binary numbers in string format (mentor advised using bits but it clicked while
// browsing over different data structures that a queue would be more appropriate)
// Start with the string "1" in the queue
// While the queue size is less than k, dequeue the front of the queue
// Append "0" and "1" to the dequeued string and enqueue them
// Return the queue

// Time complexity: O(n)
// Space complexity: O(n)
// Time taken: 20 minutes

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> firstKBinary(int k)
{   
    queue<string> binary;
    vector<string> res;

    if (k == 0) return res;

    // Edge case where k == 1
    res.push_back("0");
    binary.push("1");

    // Start with "1" in the queue
    while (res.size() < k)
    {
        // Dequeue the front of the queue after storing in temp string
        string temp = binary.front();
        binary.pop();

        // Append temp string to result vector
        res.push_back(temp);

        // Enqueue following binary numbers
        binary.push(temp + "0");
        binary.push(temp + "1");
    
    }

    return res;
}

int main()
{
    vector<string> res = firstKBinary(5);

    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res[res.size() - 1] << "]" << endl;

    vector<string> res2 = firstKBinary(10);

    cout << "[";
    for (int i = 0; i < res2.size() - 1; i++)
    {
        cout << res2[i] << ", ";
    }
    cout << res2[res2.size() - 1] << "]" << endl;
}