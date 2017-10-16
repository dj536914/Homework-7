// Griffin Jones
// dj536914@ohio.edu
// Main file

// Time complexity of adding n elements to a Huffman tree
// using the method in huffman_tree.h:
// O(nlogn)

// Time complexity of adding n elements to a Huffman tree
// using minimum frequencies:
// O(n)

#include <iostream>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {
  // Read a string message into the HuffmanTree constructor
  // Next, pass the string message into HuffmanTree::print_message()
  // to get its compressed binary encoding.

  // Input the number of strings
  int num;
  cin >> num;
  while (cin.peek() == '\n') cin.ignore();

  // Creates list of values from user entry
  string str;
  for (int i = 0; i < num; i++)
  {
    getline(cin, str);

    // Prints value entered
    HuffmanTree huff_str(str);
    cout << "Test Case: " << i + 1 << endl;

    // Prints the Huffman tree (testing purposes)
    // huff_str.print_tree();

    // Prints the compressed message
    huff_str.print_message(str);
  }
}
