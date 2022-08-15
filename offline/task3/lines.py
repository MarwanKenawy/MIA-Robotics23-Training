import cv2 as cv
import numpy as np
import matplotlib as plt
def lines(self):
    j=0
    gray = cv.cvtColor(self, cv.COLOR_BGR2GRAY)
    edges = cv.Canny(gray, 75, 150)
    lines = cv.HoughLinesP(edges, 1, np.pi/180, 500, maxLineGap=0)
    for line in lines:
        j+=1
        x1,y1,x2,y2 = line[0]
        if  len(lines)==5 and x1<x2:
            cv.putText(self,'right', (self.shape[0]//2,100), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))
            break
	    
        elif x1<x2:
            cv.putText(self,'left', (self.shape[0]//2,100), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))

        elif line in lines[-1]:
            cv.putText(self, 'straight', ((self.shape[0]//2)-150,70), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))
            break