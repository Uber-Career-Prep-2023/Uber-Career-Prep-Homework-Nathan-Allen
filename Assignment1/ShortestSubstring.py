# Given a string and a second string representing required characters, return the length of the shortest substring containing all the required characters.
# Approach: Variable-size sliding window


def ShortestSubstring(a, pattern):
  # Populate dict with pattern chars
  pattern_dict, window_dict = {}, {}
  # Record frequency of pattern chars
  for ch in pattern:
    pattern_dict[ch] = pattern_dict.get(ch, 0) + 1
  # Used to record how many unique chars are left for pointers to open/shrink window
  count, target = len(pattern_dict), 0
  min_len = float("inf")

  l = r = 0
  # Iterate through string
  while r < len(a):
    # Add char to window dict
    window_dict[a[r]] = window_dict.get(a[r], 0) + 1
    # If char is in pattern dict & frequency in window dict matches frequency in pattern dict, increment target
    if a[r] in pattern_dict and window_dict[a[r]] == pattern_dict[a[r]]:
      target += 1

    # While target == count, we have found all unique chars in pattern
    while target == count:
      min_len = min(min_len, r - l + 1)
        # Shrink window
      window_dict[a[l]] -= 1
      if a[l] in pattern_dict and window_dict[a[l]] < pattern_dict[a[l]]:
        target -= 1
      l += 1
    r += 1

  return min_len


def main():
  print(ShortestSubstring("abracadabra", "abc") == 4)
  print(ShortestSubstring("zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx") == 10)
  print(ShortestSubstring("dog", "god") == 3)
  
main()
# Time taken: ~ 40 minutes