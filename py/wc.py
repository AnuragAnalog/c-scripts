#!/usr/bin/python3.6

""" It's an analog of wc command """

fname = input("Enter the file-name:- ")

def linecount(fname):
    count = 0
    for line in open(fname):
        count += 1
    return count

print(linecount(fname))
