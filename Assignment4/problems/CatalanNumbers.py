# Question 4: Catalan Numbers
# The Catalan numbers are a mathematical sequence of numbers. 
# The nth Catalan number is defined as (2n)! / (n+1)!n!. 
# Given a non-negative integer n, return the Catalan numbers 0-n.

# Technique: Dynamic Programming - Bottom Up
# Approach:
#   1. Create a list of size n+1 to store the Catalan numbers
#   2. Initialize all the elements of the list to 1
#   3. Iterate from 1 to n+1
#       3.1. Calculate the Catalan number for the current index using the provided formula
# Note* provided formula can be simplified from using factorials to using multiplication and division
#   4. Return the list of Catalan numbers

# Time complexity: O(n)
# Space complexity: O(n)

# Time taken: 30 minutes



def generate_catalan_numbers(n):
    catalan_numbers = [1] * (n + 1)

    for i in range(1, n + 1):
        catalan_numbers[i] = catalan_numbers[i - 1] * (2 * (2 * i - 1)) // (i + 1)
    
    return catalan_numbers


def main():
    a, b = 1, 5
    print(generate_catalan_numbers(a)) # outputs [1, 1]
    print(generate_catalan_numbers(b)) # outputs [1, 1, 2, 5, 14, 42]


if __name__ == "__main__":
    main()
