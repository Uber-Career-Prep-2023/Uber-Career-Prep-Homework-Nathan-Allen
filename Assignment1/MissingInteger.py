# Given an integer n and a sorted array of integers of size n-1 which contains all but one of the integers in the range 1-n, find the missing integer.
def findInt(a, i):

  target = i
  for n in range(i - 1):
    if a[n] != n + 1:
      target = n + 1
      break
  return target


def main():

  print((findInt([1, 2, 3, 4, 6, 7], 7) == 5))
  print((findInt([1], 2) == 2))
  print((findInt([1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12], 12) == 9))


main()
# Time taken: ~20 minutes