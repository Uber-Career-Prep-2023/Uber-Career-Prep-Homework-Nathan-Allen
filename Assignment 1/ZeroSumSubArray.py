# Given an array of integers, count the number of subarrays that sum to zero.
# Approach - One-directional running computation/total paired with hashing sums

# Time complexity: O(N)
# Space complexity: O(1)


def zero_sum(nums):
  count = cur = 0
  pref = set()
  pref.add(0)

  for num in nums:
    cur += num
    if cur in pref:
      count += 1
    else:
      pref.add(cur)


# [1,2,-3,3,4,5]
  return count


def main():

  print(zero_sum([4, 5, 2, -1, -3, -3, 4, 6, -7]) == 2)
  print(zero_sum([1, 8, 7, 3, 11, 9]) == 0)
  print(zero_sum([8, -5, 0, -2, 3, -4]) == 2)
  print(zero_sum([1, 2, -3, 3, 4, 5]) == 2)


main()

# Time taken:  ~ 30 minutes: familiar with problem concept
