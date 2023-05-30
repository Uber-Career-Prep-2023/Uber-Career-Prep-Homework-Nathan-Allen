# Approach: Sorting and comparing pairs of intervals to find overlaps
# 1. Convert pairs of intervals to list of lists
# 2. Sort list of lists by first element of each pair
# 3. Iterate through list of lists, if first element of current pair is less than or equal to last element of previous pair, update last element of previous pair to max of current pair's last element and previous pair's last element
# 4. If first element of current pair is greater than last element of previous pair, append current pair to stack
# 5. Convert stack to list of tuples and return

# Time complexity: O(nlogn) by built-in sorting function
# Space complexity: O(n)


def merge(pairs):
  intervals = [list(pair) for pair in pairs]
  stack = []
  intervals.sort()
  #print(intervals)
  stack.append(intervals[0])
  #print(stack)
  for i in range(1, len(intervals)):
    if stack[-1][0] <= intervals[i][0] and intervals[i][0] <= stack[-1][-1]:
      stack[-1][-1] = max(intervals[i][-1], stack[-1][-1])
    else:
      stack.append(intervals[i])

  #print(stack)
  res = [tuple(pair) for pair in stack]
  return res


def main():
  print(merge([(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]))
  # Outputs [(1, 3), (4, 8), (9, 12)]
  print(merge([(5, 8), (6, 10), (2, 4), (3, 6)]))
  # Outputs [(2, 10)]
  print(merge([(10,12), (5,6), (7, 9), (1, 3)]))
  # Outputs [(10, 12), (5, 6), (7, 9), (1, 3)]


main()
# Time taken: 40 minutes
# Could not think of how to implement method without sorting in time
