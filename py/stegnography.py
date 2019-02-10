#!/usr/bin/python3

"""
   Description:
       This is a script which hides you information like some small messages
   in an image and makes your communication with your partner easier, this 
   script works on the concept of LSB-Modification (Stegnography).

   To know how this works trace the code.

   A python script by @anurag.peddi 9th Feb,2019.
   Copyright © 2018-2019 Anurag Peddi, India. All Rights Reserved

"""

import time
import hashlib    
from PIL import Image

def img_to_pixel(filename):
    img_file = Image.open(filename)
    img = img_file.load()
    
    (width, height) = img_file.size
    print("Maximum no. of chars that can be entered is: ",(3*width*height)/8)
    
    [xs, ys] = img_file.size
    
    fout = open("pixval.txt", "w")
    for x in range(0, xs):
        for y in range(0, ys):
            [r, g, b] = img[x, y]
            string = " ".join([str(r), str(g), str(b), "\n"])
            fout.write(string)
    fout.close()

    return (width, height)

def hide_message(message, width, height): 
    padding = 0
    if len(message)%3 == 1:
        message = message + "$$"
        padding = 2
    elif len(message)%3 == 2:
        message = message + "$"
        padding = 1
    
    fhin = open("pixval.txt", "r")
    fhout = open("mpixval.txt", "w")
    
    i = 0
    j = 0
    while i < width*height:
        arr = [next(fhin) for i in range(8)]
        if j != len(message):
            chars = message[j:j+3]
            letter = list(chars)
            binvals = []
            for n in range(3):
                leng = len(list(bin(ord(letter[n]))[2:]))
                binvals = binvals + list("0"*(8-leng)+bin(ord(letter[n]))[2:])
            j += 3
            for k in range(len(arr)):
                vals = arr[k].split()
                for l in range(3):
                    if int(vals[l])%2 == 0 and binvals[k*3+l] == "1":
                        vals[l] = str(int(vals[l])+1)
                    elif int(vals[l])%2 == 1 and binvals[k*3+l] == "0":
                        vals[l] = str(int(vals[l])-1)
                fhout.write(" ".join(vals))
                fhout.write("\n")
        else:
            for line in fhin:
                fhout.write(line)
            i = width*height
    
    fhout.close()

    return 

def pix_to_img(stegoname, message, width, height):
    img = Image.new("RGB", (width, height))
    pix = img.load()
    
    fhand = open("mpixval.txt", "r")
    x = 0
    y = 0
    for line in fhand:
        vals = line.split()
        for i in range(3):
            vals[i] = int(vals[i])
        vals = tuple(vals)
    
        if x < width and y < height:
            pix[x, y] = vals
            y = y + 1
            if y == height:
                y = 0
                x = x + 1
        if x == width and y == height:
            break
    
    img.save(stegoname, "PNG")

    return len(message);

def find_key(key):
    tmp = ""

    for num in time.localtime():
        tmp = tmp + str(num)

    result = hashlib.md5(tmp.encode())
    result = result.hexdigest() + str(key) + str(len(str(key)))

    return result

def retriveimg2pix(filename):
    img_file = Image.open(filename)
    img = img_file.load()

    [xs, ys] = img_file.size

    fout = open("data.txt", "w")
    for x in range(0, xs):
        for y in range(0, ys):
            [r, g, b] = img[x, y]
            string = " ".join([str(r), str(g), str(b), "\n"])
            fout.write(string)
    fout.close()

    return

def pix2message(key):
    leng = key[-1]
    key = int(key[-int(leng)-1:-1])
    lines = ((key*8)//3)+1

    fext = open("data.txt", "r")

    emessage = ""
    l = 0
    while l < lines:
        binval = ""
        arr = [next(fext) for i in range(8)]
        for k in range(len(arr)):
            vals = arr[k].split()
            for j in range(3):
                if int(vals[j])%2 == 0:
                    binval = binval + "0"
                else:
                    binval = binval + "1"

        for i in range(3):
            tmpbin = binval[i*8:i*8+8]
            emessage = emessage + chr(int(tmpbin, 2))
        l = l + 8
    print("Retrived message is: ", emessage[:key])
    return

def embed():
    filename = input("Enter the name of the input file: ")
    (width, height) = img_to_pixel(filename)
    message = input("Enter the message to be embed: ")
    hide_message(message, width, height)
    stegoname = input("Enter the name of your stego-image: ")
    key = pix_to_img(stegoname, message, width, height)
    key = find_key(key)

    return key

def retrive():
    filename = input("Enter the name of the stego file: ")
    retriveimg2pix(filename)
    key = input("Please enter the key: ")
    pix2message(key)

print("What do you want to do?")
print("1) Embed the message.")
print("2) Retrive the message.")
print("3) Exit the program.")

option = int(input("Your choice--> "))

if option == 1:
    key = embed()
    print("The key is: ", key)
elif option == 2:
    retrive()
elif option == 3:
    quit()
else:
    print("###  INVALID option  ###")
