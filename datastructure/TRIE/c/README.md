(refer for detailed explaination)[https://www.geeksforgeeks.org/trie-insert-and-search/]

The node structure used in TRIE holds single character and array
to hold 26 possible next node references.

`getNode` is a helper function to initialise new node

`insert` function crawls to correct position in TRIE and inserts new node.

`search` function given the root of trie and target checks whether target is present in TRIE.

refer to `main` function for testing and usage of TRIE instance.