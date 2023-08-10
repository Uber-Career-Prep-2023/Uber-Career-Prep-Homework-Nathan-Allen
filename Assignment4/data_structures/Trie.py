# Question 1: Build a Trie
# Implement a trie class, including the insert, search, and delete methods. 
# Your class should adhere to the following API, adjusted appropriately for your language of choice.

# Sub-class for TrieNode within a prefix tree
class TrieNode:
    def __init__(self):
        # Stores all the children(references to letters) of the node
        self.children = {}

        # Flag to indicate if the word ends at this node
        self.validWord = False


# Main class for Trie
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    # Insert a word into the trie
    def insert(self, word):
        ptr = self.root
        for char in word:
            if char not in ptr.children:
                ptr.children[char] = TrieNode()
            # Move the pointer to the next node/letter
            ptr = ptr.children[char]

        # Set the flag to indicate that the word ends at this node
        ptr.validWord = True
    
    # Returns if the word is in the trie
    def isValidWord(self, word):
        ptr = self.root
        for char in word:
            if char not in ptr.children:
                return False
            ptr = ptr.children[char]
        
        # If the word is in the trie, then the last node will have validWord flag set to True
        return ptr.validWord == True

    # Removes word, from the trie and deletes unused nodes
    def remove(self, word):
        def helper(node, word, index):
            if index == len(word):
                node.validWord = False
                return len(node.children) == 0
            
            child = word[index]
            if child not in node.children:
                return False

            # Recursively call the helper function to delete the child node
            shouldDeleteChild = helper(node.children[child], word, index + 1)
            if shouldDeleteChild:
                del node.children[child]
                return len(node.children) == 0
            
            return False
                

        helper(self.root, word, 0)

            # Recursively call the helper function to delete the child node



def main():
    trie = Trie()
    trie.insert("apple")
    trie.insert("app")
    trie.insert("apricot")

    assert trie.isValidWord("apple") == True
    assert trie.isValidWord("app") == True
    assert trie.isValidWord("apricot") == True
    assert trie.isValidWord("approach") == False

    trie.remove("apple")
    assert trie.isValidWord("apple") == False

    trie.remove("app")
    assert trie.isValidWord("app") == False

    trie.remove("apricot")
    assert trie.isValidWord("apricot") == False


if __name__ == "__main__":
    main()



