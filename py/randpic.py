#!/usr/bin/python3

""" It generates some random pixels and converts that pixels to a pic. """

from PIL import Image
import random

img = Image.new("RGB", (128, 128))
pix = img.load()

pixval = [0, 0, 0]
for i in range(128):
    for j in range(128):
        for k in range(3):
            num = random.randint(0, 256)
            pixval[k] = num
        pix[i, j] = tuple(pixval)

img.save("abcd.png", "PNG")
