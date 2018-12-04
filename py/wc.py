#!/usr/bin/python3.6

fname = input("Enter the file-name:- ")

def linecount(fname):
    count = 0
    for line in open(fname):
        count += 1
    return count

print(linecount(fname))
