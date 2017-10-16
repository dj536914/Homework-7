// Griffin Jones
// dj536914@ohio.edu
// min_heap.h

#include <vector>
using namespace std;

template <typename Type>
struct HeapNode {
  HeapNode(const Type d, const int k) :
    data(d), key(k) {}

  Type data;
  int key;
};

template <typename Type>
class MinHeap {

public:
  MinHeap() {}
  ~MinHeap() {}

  //* Function: insert
  //* Input:
  //*       data - User data
  //*       key  - Key value associated with user data.
  //*              Use key to organize user data into min
  //*              heap container
  void insert(const Type data, const int key)
  {
    // Adds data and key as the last node in the heap
    // If this is the only node, return
    HeapNode<Type> heap_node(data, key);
    heap_.push_back(heap_node);
    if (heap_.size() == 1) return;

    // Sets i to the index of the last value in the heap_
    size_t i = heap_.size() - 1;

    // While the index isn't at the root, and while the last element is
    // smaller than its parent, bubble up, then iterate as the parent
    while ((i != 0) && (heap_node.key < heap_[(i - 1) / 2].key))
    {
      // Swaps the current node with the parent node
      HeapNode<Type> temp_node(heap_[i].data, heap_[i].key);
      heap_[i].data = heap_[(i - 1) / 2].data;
      heap_[i].key = heap_[(i - 1) / 2].key;
      heap_[(i - 1) / 2].data = temp_node.data;
      heap_[(i - 1) / 2].key = temp_node.key;

      // Iterate as parent
      i = (i - 1) / 2;
    }
  }

  //* Function: extract_min
  //* Input:
  //*       return_data - Reference variable to retrieve user data
  //*                     stored in heap.
  void extract_min(Type& return_data)
  {
    // If the size is zero, return
    if (heap_.size() == 0)
      return;

    // Returns the first element
    return_data = heap_[0].data;

    // Sets k to the last element, swap with the min, then remove the last
    size_t n = heap_.size() - 1;
    HeapNode<Type> k = heap_[n];
    heap_[0].data = k.data;
    heap_[0].key = k.key;
    heap_.pop_back();

    // Updates n
    n = heap_.size() - 1;

    // Current parent
    size_t h = 0;

    // Left child
    size_t i = 1;

    // Right child
    size_t j = 2;

    // Bubbles down
    for (int l = n; l >= 0; --l)
    {
      // Sets the min child value to h as default
      int m = h;

      // If h is bigger than i, switch with i
      if (heap_[h].key > heap_[i].key)
      {
        m = i;
      }

      // If h is the same as i, switch with j
      else if ((j < n) && (heap_[m].key > heap_[j].key))
      {
        m = j;
      }

      // Switch with the left child
      if ((heap_[m].key > heap_[i].key) && (heap_[i].key == heap_[j].key))
      {
        // We swap
        HeapNode<Type> temp_node(heap_[m].data, heap_[m].key);
        heap_[m] = heap_[i];
        heap_[i] = temp_node;
      }

      // Switch with the right child
      else if (m != h)
      {
        // We swap
        HeapNode<Type> temp_node(heap_[h].data, heap_[h].key);
        heap_[h] = heap_[m];
        heap_[m] = temp_node;
      }
    }
  }

  //* Function: peek
  //* Input:
  //*       return_data - Reference variable to retrieve user data
  //*                     stored in heap.
  void peek(Type& return_data) const {
    // As with extract_min, we leave it up to the user to check if
    // their heap is empty before calling peek. If the user doesn't
    // follow this suggestion and calls peek when
    // heap_ is empty, then return_data won't be set to anything.
    if (heap_.size() == 0)
      return;

    // If heap_ isn't empty, then get user data out of min element.
    // Don't remove min element from heap though.
    else
        return_data = heap_[0].data;
  }

  //* Function: size
  int size() const {
    // Return the size of your heap
    return heap_.size();
  }

private:
  vector<HeapNode<Type> > heap_;
};
