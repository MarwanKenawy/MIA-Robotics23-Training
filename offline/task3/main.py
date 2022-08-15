import cv2 as cv
import numpy as np
import matplotlib as plt
from shapes import*
from colors import*
from lines import*
    
img = [cv.imread('photos/test1.png'),cv.imread('photos/test2.png'),cv.imread('photos/test3.png')]
for i in range(3):
   shapes(img[i])
   colors(img[i])
   lines(img[i])
   cv.imshow(f'final{i+1}',img[i])
   cv.waitKey(0)