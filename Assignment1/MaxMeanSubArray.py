# Given an array of integers and an integer, k, find the maximum mean of a subarray of size k.

# Approach: Fixed-size sliding window
# 1. Initialize left, right pointers to be at start of array, k - 1 positions from left respectively
# 2. Calculate sum of current window [l:r + 1] & obtain max value; store in return value
# 3. Iterate entire array, calculating & comparing subarray sums of size k
# 4. Return max mean

# Time complexity - O(n) n-> n being the length of the array
# Space complexity - O(1) -> no additional memory allocation


def max_mean_subarray(a, k):
  l, r = 0, k - 1
  max_mean = -1

  if not a or k > len(a):
    return -1

  while r < len(a):
    cur_sum = sum(a[l:r + 1])
    max_mean = max(max_mean, cur_sum / k)
    l += 1
    r += 1

  return max_mean


def main():
  print(max_mean_subarray([4, 5, -3, 2, 6, 1], 2) == 4.5)
  print(max_mean_subarray([4, 5, -3, 2, 6, 1], 3) == 3)
  print(max_mean_subarray([1, 1, 1, 1, -1, -1, 2, -1, -1, 6], 3) >= 1.33)
  print(max_mean_subarray([1, 1, 1, 1, -1, -1, 2, -1, -1, 6], 4) == 1.5)

  print(max_mean_subarray([], 2) == -1)
  print(max_mean_subarray([4, 5, -3, 2, 6, 1], 7) == -1)


main()
# ~30 minutes total: 25 for implementation, ~5 for test cases
