import os


# Simple fibo
def fib(n):
    if n <= 1:
        return n
    
    return fib(n-1) + fib(n-2)

# dp fibo
d = {}
def dp_fib(n):
    global d
    if n <= 1:
        d[n] = n
        return d[n]
    if d.get(n) == None:
      d[n-1] =  dp_fib(n-1)  if  d.get(n-1) == None else  d[n-1]
      d[n-2] =  dp_fib(n-2)  if  d.get(n-2) == None else  d[n-2]
      d[n] = d[n-1]+ d[n-2]

    return d[n]

print(dp_fib(950))