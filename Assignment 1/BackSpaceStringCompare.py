# Given two strings representing series of keystrokes, determine whether the resulting text is the same. Backspaces are represented by the '#' character so "x#" results in the empty string ("").

# Approach - Stack implementation of strings, string comparison to validate similarity
# 1. 
# Time complexity: O(n)
# Space complexity: O(n)


def BackSpaceStringCompare(first, second):

  if not first and not second:
    return True
  if not first or not second:
    return False
  fs = []
  sc = []
  for ch in first:
    if (ch == "#"):
      del fs[-1]
    else:
      fs.append(ch)
  for ch in second:
    if (ch == "#"):
      del sc[-1]
    else:
      sc.append(ch)

  return fs == sc


def main():
  print(BackSpaceStringCompare("abcde", "abcde") == True)
  print(BackSpaceStringCompare("Uber Career Prep", "u#Uber Careee#r Prep") == True)
  print(BackSpaceStringCompare("abcdef###xyz", "abcw#xyz") == True)
  print(BackSpaceStringCompare("abcdef###xyz", "abcdefxyz###") == False)


main()
# Time taken: ~35 minutes
