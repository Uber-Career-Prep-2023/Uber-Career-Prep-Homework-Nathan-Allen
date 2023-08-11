# Question 6: WordBreak
# Given a string of characters without spaces and a dictionary of valid words, determine if it can be broken into a list of valid words by adding spaces. 

# Technique: Dynamic Programming and Trie
# Approach: Build a trie from the dictionary of valid words. Then, use dynamic programming to determine if the string can be broken into valid words.
# After building trie, the way I approached it was as follows:
# 1. Create a dp array of size n + 1, where n is the length of the string. dp[i] represents whether the substring from 0 to i can be broken into valid words.
# 2. dp[0] is True, since the empty string can be broken into valid words.
# 3. For each index i in the string, iterate backwards from i to 0. At each index j, check if the substring from j to i is a valid word. 
    # If it is, then check if dp[j - 1] is True. If it is, then dp[i] is True.
    # If it is not, then continue iterating backwards.
    # Why do we iterate backwards? Because we want to check if the substring from j to i is a valid word, and we want to check the longest substring first.
    # If we iterate forwards, then we will check the shortest substring first, which may not be a valid word.

# Time complexity: O(n + m^2), where m is length of input string and n is total number of characters in all words in dictionary
# Space complexity: O(n + m), where m is length of input string for dp array, and n is total number of characters
# Time taken: ~1 hour



class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

def build_trie(words):
    root = TrieNode()
    for word in words:
        node = root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.end = True
    return root

def word_break(string, words):
    root = build_trie(words)
    n = len(string)
    dp = [False] * (n + 1)
    dp[0] = True

    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            node = root
            k = j - 1
            while k < i and string[k] in node.children:
                node = node.children[string[k]]
                k += 1

            if k == i and node.end and dp[j - 1]:
                dp[i] = True
                break

    return dp[-1]

def main():

    dictionary = ['elf', 'go', 'golf', 'man', 'manatee', 'not', 'note', 'pig', 'quip', 'tee', 'teen']

    string = 'mangolf'
    print(word_break(string, dictionary))

    string = 'manateenotelf'
    print(word_break(string, dictionary))

    string = 'quipig'
    print(word_break(string, dictionary))


if __name__ == "__main__":
    main()