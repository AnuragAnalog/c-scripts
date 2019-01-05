#!/usr/bin/python3.6

""" This works similar to the rstrip method for strings in python. """

def rstripo(string):
    lt = list(string)
    lt = lt[-1::-1]
    while True:
        if ord(lt[0]) == 32:
            lt = lt[1:]
            continue
        else:
            break
    lt = lt[-1::-1]
    out_str = "".join(lt)
    return out_str

string = input("Enter the input string: ")
str_mod = rstripo(string)
print(str_mod)
