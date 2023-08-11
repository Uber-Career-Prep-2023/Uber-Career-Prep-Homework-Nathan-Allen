# Question 5: MinCostStairClimbing

# A staircase on a hiking trail implements a rather unusual toll system to cover trail maintenance costs. 
# Each stair in the staircase has a different toll which you only have to pay if you step on that stair. 
# Due to the height of the stairs, you can only climb one or two stairs at once. 
# This means that from the ground you must initially step on either stair 0 or stair 1 and that, if there are n stairs, the last stair you step on can be either stair n-1 or n-2. 
# Given an array representing the costs per stair, what is the minimum possible toll you can pay to climb the staircase?

# Technique: Dynamic Programming - Bottom Up
# Approach:
# 1. Create a list of size n+1 to store the minimum cost to reach each stair.
# 2. Initialize the second and third elements of the list to be the cost of the first two stairs, first element will be zero it costs zero to be on the ground.
# 3. For each stair from 2 to n, the minimum cost to reach that stair is the minimum of the cost to reach the previous two stairs plus the cost of the current stair.
# 4. Return the last element of the list.

# Time complexity: O(n)
# Space complexity: O(n)
# Time taken: ~30 mins

def min_cost(stairs):
    if len(stairs) <= 2:
        return min(stairs)
    
    dp = [0] * (len(stairs) + 1)
    dp[1], dp[2] = stairs[0], min(stairs[0], stairs[1])

    for i in range(3, len(stairs) + 1):
        dp[i] = min(dp[i - 1], dp[i - 2]) + stairs[i - 1]
    
    return min(dp[-1], dp[-2])


def main():
    test1 =  [4, 1, 6, 3, 5, 8]
    test2 = [11, 8, 3, 4, 9, 13, 10]

    print(min_cost(test1)) # prints 9
    print(min_cost(test2)) # prints 25


if __name__ == "__main__":
    main()
