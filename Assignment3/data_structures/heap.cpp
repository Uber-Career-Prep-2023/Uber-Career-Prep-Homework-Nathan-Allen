// Write a min heap class according to the following API using an array as the underlying data structure. 
// (A max heap has the same implementation; you simply need to flip the direction of the comparators.) 
// For simplicity, you can assume that the heap holds integers rather than generic comparables.

#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

// Implemented using a vector, but will change to a static array
// per question guidelines

class minHeap {
    private:
        vector<int> array;

    public:

        // returns the top element of the heap
        int top() { 
            return array[0]; 
        }

        // helper functions

        //  
        void percolateUp(int i) {
            int parent = (i-1) / 2;
            while (i > 0 && array[parent] > array[i])
                {
                    int temp = array[parent];
                    array[parent] = array[i];
                    array[i] = temp;
                    i = parent;
                    parent = (i-1) / 2;
                }
            }

        // 
        void percolateDown(int i)
        {
            int child = 2 * i + 1;
            if (child > array.size()){
                return;
            }

            if (child + 1 < array.size() && array[child] > array[child + 1]){
                child++;
            }

            if (array[i] > array[child]){
                int temp = array[i];
                array[i] = array[child];
                array[child] = temp;
                percolateDown(child);
            }
        }

        // inserts an element into the heap, corrects heap property if necessary
        void insert(int x) {
            array.push_back(x);

            // get indices of child
            int child = array.size() - 1;

            // percolate up to correct heap property
            percolateUp(child);
            
        }

        // removes the top element of the heap, corrects heap property if necessary
        void remove()
        {
            int temp = array[0];
            array[0] = array[array.size() - 1];
            array[array.size() - 1] = temp;
            array.pop_back();
            percolateDown(0);

        }

        // test-case purposes
        friend ostream& operator<<(ostream& out, const minHeap& heap) {
            for (int i = 0; i < heap.array.size(); i++) {
                out << heap.array[i] << " ";
            }
            return out;
        }

        int size() {
            return array.size();
        }
};

int main() {

    minHeap heap;

    // testing the insert function
    heap.insert(23);
    heap.insert(57);
    heap.insert(36);
    heap.insert(45);
    heap.insert(32);
    heap.insert(10);
    heap.insert(38);

    cout << heap << endl;
    // correctly fixes the min-heap property and outputs: 10 32 23 57 45 36 38

    // testing the remove function until the heap is empty
    for (int i = 0; i < heap.size(); i++) {

        cout << "Element to remove: " << heap.top() << endl;
        heap.remove();
        cout << "Heap after removal: ";
        cout << heap << endl;
    }
    /*----------------------------------------------------------------
    Element to remove: 10
    Heap after removal: 23 32 36 57 45 38 

    Element to remove: 23
    Heap after removal: 32 38 36 57 45    

    Element to remove: 32
    Heap after removal: 36 38 45 57

    Element to remove: 36
    Heap after removal: 38 36 45
    
    -----------------------------------------------------------------*/
}
