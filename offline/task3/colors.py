import cv2 as cv
import numpy as np
import matplotlib as plt
def colors(self):
 hsv = cv.cvtColor(self, cv.COLOR_BGR2HSV)


 
 redlower = np.array([0, 50, 50])
 redupper = np.array([10, 255,255])
 redmask = cv.inRange(hsv,redlower,redupper)

 greenlower = np.array([40, 40, 40])
 greenupper = np.array([70, 255, 255])
 greenmask = cv.inRange(hsv,greenlower,greenupper)

 bluelower = np.array([94, 80, 2])
 blueupper = np.array([120, 255,255])
 bluemask = cv.inRange(hsv,bluelower,blueupper)

 yellowlower = np.array([22, 93, 0])
 yellowupper = np.array([45, 255,255])
 yellowmask = cv.inRange(hsv,yellowlower,yellowupper)
 
 redcontour, hierarchy = cv.findContours(redmask,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)
 greencontour, hierarchy = cv.findContours(greenmask,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)
 bluecontour, hierarchy = cv.findContours(bluemask,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)
 yellowcontour, hierarchy = cv.findContours(yellowmask,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)
 for pic, contour in enumerate(redcontour):
    area = cv.contourArea(contour)
    if(area > 300):
        x, y, w, h = cv.boundingRect(contour)
        cv.putText(self, "Red", (x, y+15),cv.FONT_HERSHEY_TRIPLEX, 0.5,(0, 0, 0))     

 for pic, contour in enumerate(greencontour):
    area = cv.contourArea(contour)
    if(area > 300):
        x, y, w, h = cv.boundingRect(contour)
        cv.putText(self, "Green", (x, y+15),cv.FONT_HERSHEY_TRIPLEX, 0.5, (0, 0, 0))
  

 for pic, contour in enumerate(bluecontour):
    area = cv.contourArea(contour)
    if(area > 300):
        x, y, w, h = cv.boundingRect(contour)  
        cv.putText(self, "Blue", (x, y+15),cv.FONT_HERSHEY_TRIPLEX,0.5, (0, 0, 0))

 for pic, contour in enumerate(yellowcontour):
    area = cv.contourArea(contour)
    if(area>300):
        x, y, w, h = cv.boundingRect(contour)
        cv.putText(self, "Yellow", (x+10,y+15), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))



 
 