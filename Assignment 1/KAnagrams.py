# Two strings are considered to be “k-anagrams” if they can be made into anagrams by changing at most k characters in one of the strings. Given two strings and an integer k, determine if they are k-anagrams.

# Approach: Hashing elements
# Time complexity: O(n)
# Space complexity: O(n)


def isKAnagram(left, right, k):
  if len(left) != len(right):
    return False

  comp = dict()

  for i in left:
    comp[i] = comp.get(i, 0) + 1

  for i in right:
    if i in comp:
      comp[i] -= 1
    else:
      k -= 1

  valid = sum(comp.values())
  return k >= valid or k == 0


def main():
  print(isKAnagram("apple", "peach", 1) == False)
  print(isKAnagram("apple", "peach", 2) == True)
  print(isKAnagram("cat", "dog", 3) == True)
  print(isKAnagram("debit curd", "bad credit", 1) == True)
  print(isKAnagram("baseball", "basketball", 2) == False)


main()

# Time taken: ~27 minutes
