#!/usr/bin/python3.6

"""A function named list_of_primes that accepts a positive integer n and returns a sorted list (ascending order) of all the prime numbers between 2 and n (including 2 but not including n)"""

def list_of_primes(n):
    primes = list()
    for m in range(2, n):
        no = 0
        for i in range(1, m+1):
            if m%i == 0:
                no = no + 1
        if no == 2:
            primes.append(m)
    return primes

n = int(input("Enter the number: "))
primes = list_of_primes(n)
print(primes)
