import numpy as np

# Input
inputs = list(map(int, input().split()))  # Read all inputs as integers
n = inputs[0]                             # First value is 'n'
arr = inputs[1:]                          # Remaining values form the array

# Precompute weights for all subsets
weight = np.zeros(1 << n)
for mask in range(1 << n):
    for i in range(n):
        if mask & (1 << i):  # Check if the i-th bit is set
            weight[mask] += arr[i]

# Initialize DP array
dp = np.zeros(1 << n)
dp[0] = 0

# Iterate over all masks
for X in range(1 << n):
    submask = X
    while submask > 0:
        # Iterate over all submasks of X
        if weight[submask] <= weight[X]:  # Add a condition based on problem constraints
            dp[X] = max(dp[X], dp[X ^ submask] + 1)
        submask = (submask - 1) & X  # Move to the next submask

# Result
print(int(dp[(1 << n) - 1]))
