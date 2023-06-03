// Given an array of k sorted arrays, merge the k arrays into a single sorted array.

// Technique: Min-Heap
// Approach: Use a min-heap to store the first element of each array
// Pop the top element from the heap and push it to the result vector
// Push the next element of the array from which the element was popped to the heap
// Repeat until the heap is empty
// Return the result vector


// Time complexity: O(nlogk)
// Space complexity: O(n)
// Time taken: ~40 minutes

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> mergeKSortedArrays(int k, vector<vector<int>>& nums)
{
    vector<int> res;
    priority_queue <int, vector<int>, greater<int>> min;
    for (int i = 0; i < k; i++)
    {   
        if (nums[i].size() > 0)
        {
            min.push(nums[i][0]);
        }
    }

    while (!min.empty())
    {
        int minVal = min.top();
        min.pop();
        res.push_back(minVal);

        for (int i = 0; i < k; i++)
        {
            // If the array is not empty and the first element is equal to the min value, pop the first element
            if (nums[i].size() > 0 && nums[i][0] == minVal)
            {
                nums[i].erase(nums[i].begin());

                // If array containing min value is not empty, push the next element to the heap
                if (nums[i].size() > 0)
                {
                    min.push(nums[i][0]);
                }
            }
        }
        
    }
    return res;

}

int main() {

    vector<vector<int>> nums = {{1,2,3,4,5}, {1,3,5,7,9}};
    vector<int> sorted = mergeKSortedArrays(2, nums);

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    nums.clear(), sorted.clear();
    nums = {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};
    sorted = mergeKSortedArrays(3, nums);

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
}