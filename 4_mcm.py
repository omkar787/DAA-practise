'''
  Time Complexity = O(N^3)
  Space Complexity = O(N^2)
'''

import math
def mcm(order):
    # Number of matrices = order - 1
    n = len(order) - 1
    # Creating M and S matrix for n * n
    M = [[0 for j in range(n)] for i in range(n)]
    S = [[-1 for j in range(n)] for i in range(n)]

    # Traversing the matrix diagonally
    # The difference between i and j starts from 1 and goes till n-1
    # e.g i j
    #     1 2
    #     2 3
    #     3 4
    for difference in range(1, n):
        # Traversing i * j
        for i in range(0,n-difference):
            j = i + difference 
            M[i][j] = math.inf
            for k in range(i,j):
                q = M[i][k] + M[k+1][j] + (order[i]*order[k+1]*order[j+1])
                if q < M[i][j]:
                    M[i][j] = q
                    S[i][j] = k

    return M,S

def print_optimal_parens(s, i, j):
  if i == j:
    print(f' A{i+1} ', end='')
  else:
    print(' ( ', end='')
    print_optimal_parens(s, i, s[i][j])
    print_optimal_parens(s, s[i][j] + 1, j)
    print(' ) ', end='')



ord = [5,4,6,2,7]
# ord = [1, 85, 91, 14, 77, 96]
M,S = mcm(ord)

print_optimal_parens(S, 0, len(ord) - 2)
print()
for i in range(len(S)):
  print("[ ", end=" ")
  for j in range(len(S[i])):
     print(S[i][j]+1,end=" ")
  print(" ]")

print("\n")
for i in range(len(M)):
  print("[ ", end=" ")
  for j in range(len(S[i])):
     print(M[i][j],end=" ")
  print(" ]")