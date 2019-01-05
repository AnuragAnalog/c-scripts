#!/usr/bin/python3.6
""" This script is used to take a screen shot in between the process, it takes the
screenshot and saves it in the current working directory but doesn't show to you
to show the image soon after capturing remove the comment from the line sc.show().

NOTE: It only works in windows and MacOS, for linux based systems
 there are other versions"""

import PIL.ImageGrab

fname = input("Enter the name of the screen-shot file: ")

def screen_shot(fname):
    check = fname.split(".")
    if check[1] == "png" or check[1] == "jpeg" or check[1] == "jpg":
        sc = PIL.ImageGrab.grab()
        sc.save(fname, check[1].upper())
        #sc.show()
    else:
        print("File extension should be JPEG or PNG")
        quit()

screen_shot(fname)
