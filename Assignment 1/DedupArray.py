# Given a sorted array of non-negative integers, modify the array by removing duplicates so each element only appears once. If arrays are static (aka, not dynamic/resizable) in your language of choice, the remaining elements should appear in the left-hand side of the array and the extra space in the right-hand side should be padded with -1s.

# Approach: Reset catchup two-pointer method; right pointer advances if contiguous integers are not equal
# If they are equal, delete the list integer value and adjust length of list


def dedup(a):
  ptr = 0
  l = len(a)
  while ptr < len(a) - 1:
    if a[ptr] == a[ptr + 1]:
      del a[ptr + 1]
      l -= 1
    else:
      ptr += 1

  return a
  
def main():
  print(dedup([1, 2, 2, 3, 3, 3, 4, 4, 4, 4]) == [1, 2, 3, 4])
  print(dedup([0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15]) == [0, 1, 4, 5, 8, 9, 10, 11, 15])
  print(dedup([1, 3, 4, 8, 10, 12]) == [1, 3, 4, 8, 10, 12])


main()
# Time taken: ~16 minutes