# Question 8: Coin Change
# Given a list of coin denominations and a target sum, return the number of possible ways to make change for that sum.

# Technique: Dynamic Programming - Tabulation
# Approach:
# 1. Create a table of size (targetSum + 1) and initialize all values to 0
# 2. Set the first value in the table to 1
# 3. For each coin denomination, iterate through the table and update the value at each index by adding the value at (index - coinDenomination)
# Why? Because the number of ways to make change for a given sum is equal to the sum of the number of ways to make change for the sum minus each of the coin denominations
# 4. Return the value at the last index in the table

# Time complexity: O(n * m) where n is the target sum and m is the number of coin denominations
# Space complexity: O(n) where n is the target sum
# Time taken: 45 mins - drawing out decision tree and choosing bottom-up approach


def coinChange(coins, targetSum):
    table = [0] * (targetSum + 1)
    table[0] = 1

    for coin in coins:
        for i in range(coin, targetSum + 1):
            table[i] += table[i - coin]

    return table[targetSum]


def main():

    coins, sum = [2,5,10], 20
    assert coinChange(coins, sum) == 6


if __name__ == "__main__":
    main()
