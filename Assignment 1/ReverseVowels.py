# Given a string, reverse the order of the vowels in the string.
# Approach: Forward-backward two pointer with helper function to verify vowels
# Time complexity: O(N)
# Space complexity: O(N)


def is_vowel(char):
  if char in "AEIOUaeiou":
    return True
  return False


def reverse_vowels(string):
  if not string:
    return string

  str_list = [char for char in string]
  l, r = 0, len(str_list) - 1

  while l < r:
    if is_vowel(str_list[l]) and is_vowel(str_list[r]):
      str_list[l], str_list[r] = str_list[r], str_list[l]
      l += 1
      r -= 1

    elif is_vowel(str_list[l]) and not is_vowel(str_list[r]):
      r -= 1

    elif not is_vowel(str_list[l]) and is_vowel(str_list[r]):
      l += 1

    else:
      l += 1
      r -= 1

  new_string = ''.join(str_list)
  return new_string


def main():

  print(reverse_vowels("Uber Career Prep") == "eber Ceraer PrUp")
  print(reverse_vowels("xyz") == "xyz")
  print(reverse_vowels("flamingo") == "flominga")
  print(reverse_vowels(" ") == " ")


main()
# 25 minutes
