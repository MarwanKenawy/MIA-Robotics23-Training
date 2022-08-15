import cv2 as cv
import numpy as np
import matplotlib as plt

def shapes(self):
    gray = cv.cvtColor(self, cv.COLOR_BGR2GRAY)
    _, thresh = cv.threshold(gray, 220, 255, cv.THRESH_BINARY)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
    for contour in contours:
     approx = cv.approxPolyDP(contour, 0.01*cv.arcLength(contour, True), True)
     #cv.drawContours(img, [approx], 0, ( 0, 0, 0), 5)
     x = approx.ravel()[0]
     y = approx.ravel()[1]
     x, y, w, h = cv.boundingRect(approx)
     aspectratio = float(w)/h
     if len(approx)==3:
        cv.putText(self, 'Triangle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))
     elif len(approx)==4:
        
        if aspectratio>=0.95 and aspectratio<=1.05:
            cv.putText(self, 'Square',(x,y),cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))
        else:
            cv.putText(self,'Rectangle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))

     else :
        cv.putText(self, 'Circle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))
    