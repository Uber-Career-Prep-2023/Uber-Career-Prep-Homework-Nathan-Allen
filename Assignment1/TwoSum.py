# Given an array of integers and a target integer, k, return the number of pairs of integers in the array that sum to k. In each pair, the two items must be distinct elements (come from different indices in the array).
# Approach: Hash element frequency
# Update number of pairs based on whether k - n exists & frequency of n in the dictionary (n = integer in input array)

# Time complexity: O(N) - N being length of input array
# Space complexity: O(N) - due to dictionary


def twosum(a, k):
  cnt = r = 0
  # Dictionary to store integer frequencies
  sums = dict()

  for r in range(len(a)):
    # if k - a[r] exists, update count to frequency of that integer
    if k - a[r] in sums:
      cnt += sums[k - a[r]]
    # update a[r] frequency for future integer pairs
    sums[a[r]] = sums.get(a[r], 0) + 1

  return cnt


def main():
  print(twosum([1, 10, 8, 3, 2, 5, 7, 2, -2, -1], 10) == 3)
  print(twosum([1, 10, 8, 3, 2, 5, 7, 2, -2, -1], 8) == 3)
  print(twosum([4, 3, 3, 5, 7, 0, 2, 3, 8, 6], 6) == 5)
  print(twosum([4, 3, 3, 5, 7, 0, 2, 3, 8, 6], 1) == 0)
  # extra test case
  print(twosum([3, 3, 3, 3], 6) == 6)


main()
# Time taken - ~20 minutes
