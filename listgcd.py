#!/usr/bin/python3.6

"""A function named find_gcd that accepts a list of positive integers and returns their greatest common divisor (GCD)"""

def find_gcd(some_list):
    gcd = 1
    num = min(some_list)
    for i in range(1, num+1):
        no = 0
        for j in range(len(some_list)):
            if some_list[j]%i == 0:
                no = no + 1
        if no == len(some_list):
            gcd = i
    return gcd

n = int(input("Enter no. of items in list: "))
some_list = list()

for i in range(n):
    tmp = int(input("Enter the number: "))
    some_list.append(tmp)

gcd = find_gcd(some_list)
print(f"{gcd} is the G.C.D of all the numbers in list.")
