#!/usr/bin/python3.6

""" This works similar to the lstrip method for strings in python. """

def lwhite(string):
    lt = list(string)
    while True:
        if ord(lt[0]) == 32:
            lt = lt[1:]
            continue
        else:
            break
    out_str = "".join(lt)
    return out_str

string = input("Enter the input string: ")
str_mod = lwhite(string)
print(str_mod)
