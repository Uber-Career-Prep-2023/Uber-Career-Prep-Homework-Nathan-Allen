#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class PriorityQueue {
    private:
      // the underlying array
      vector<pair<string, int>> arr; 

    public:
      // returns the highest priority (first) element in the PQ
      int top() {
            return arr[0].second;
      }

      // helper functions

        // 
        void percolateUp(int i) {
            int parent = (i-1) / 2;
            while (i > 0 && arr[parent].second < arr[i].second)
                {
                    pair<string, int> temp = arr[parent];
                    arr[parent] = arr[i];
                    arr[i] = temp;
                    i = parent;
                    parent = (i-1) / 2;
                }
            }

        // 
        void percolateDown(int i)
        {
            int child = 2 * i + 1;
            if (child > arr.size()){
                return;
            }

            if (child + 1 < arr.size() && arr[child].second < arr[child + 1].second){
                child++;
            }

            if (arr[i].second < arr[child].second){
                pair<string, int> temp = arr[i];
                arr[i] = arr[child];
                arr[child] = temp;
                percolateDown(child);
            }
        }

      // adds string x to the PQ with priority weight
      void insert(string x, int weight) {
        pair <string, int> p;
        p.first = x; p.second = weight;
        arr.push_back(p);
        percolateUp(arr.size() - 1);
      }

      // removes the highest priority (first) element in the PQ
      void remove() {
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        percolateDown(0);
      }

      // test case purposes
      friend ostream& operator<<(ostream& os, const PriorityQueue& pq) {
        for (int i = 0; i < pq.arr.size(); i++) {
          os << pq.arr[i].first << ": " << pq.arr[i].second << endl;
        }
        return os;
      }

      int size() {
        return arr.size();
      }
};

int main()
{
    PriorityQueue pq;
    pq.insert("a", 1);
    pq.insert("b", 2);
    pq.insert("c", 3);
    pq.insert("d", 4);
    pq.insert("e", 5);
    pq.insert("f", 6);

    // testing insert function
    cout << pq << endl;
    /*--------------------------
    Output:
    f: 6
    d: 4
    e: 5
    a: 1
    c: 3
    b: 2
    --------------------------*/
    
    // testing remove function
    for (int i = 0; i < pq.size(); i++) {

        cout << "Element to remove: " << pq.top() << endl;
        pq.remove();
        cout << "Priority queue after removal: " << endl;
        cout << pq << endl;
    }
    /*--------------------------
    Output:
    Element to remove: 6
    Priority queue after removal:
    e: 5
    d: 4
    b: 2
    a: 1
    c: 3

    Element to remove: 5
    Priority queue after removal:
    d: 4
    c: 3
    b: 2
    a: 1

    Element to remove: 4
    Priority queue after removal:
    c: 3
    a: 1
    b: 2

    ---------------------------*/
}

