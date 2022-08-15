import cv2 as cv
import numpy as np
import matplotlib as plt
for i in range(3):
 img =[cv.imread("photos/test1.png"), cv.imread("photos/test2.png"), cv.imread("photos/test3.png")]
 gray = cv.cvtColor(img[i], cv.COLOR_BGR2GRAY)
 hsv = cv.cvtColor(img[i], cv.COLOR_BGR2HSV)
 _, thresh = cv.threshold(gray, 220, 255, cv.THRESH_BINARY)
 contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
 edges = cv.Canny(gray, 75, 150)
 lines = cv.HoughLinesP(edges, 1, np.pi/180, 500, maxLineGap=0)
 j=0

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
        cv.putText(img[i], "Red", (x, y+15),cv.FONT_HERSHEY_TRIPLEX, 0.5,(0, 0, 0))     

 for pic, contour in enumerate(greencontour):
    area = cv.contourArea(contour)
    if(area > 300):
        x, y, w, h = cv.boundingRect(contour)
        cv.putText(img[i], "Green", (x, y+15),cv.FONT_HERSHEY_TRIPLEX, 0.5, (0, 0, 0))
  

 for pic, contour in enumerate(bluecontour):
    area = cv.contourArea(contour)
    if(area > 300):
        x, y, w, h = cv.boundingRect(contour)  
        cv.putText(img[i], "Blue", (x, y+15),cv.FONT_HERSHEY_TRIPLEX,0.5, (0, 0, 0))

 for pic, contour in enumerate(yellowcontour):
    area = cv.contourArea(contour)
    if(area>300):
        x, y, w, h = cv.boundingRect(contour)
        cv.putText(img[i], "Yellow", (x+10,y+15), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))





 for contour in contours:
    approx = cv.approxPolyDP(contour, 0.01*cv.arcLength(contour, True), True)
    #cv.drawContours(img, [approx], 0, ( 0, 0, 0), 5)
    x = approx.ravel()[0]
    y = approx.ravel()[1]
    x, y, w, h = cv.boundingRect(approx)
    aspectratio = float(w)/h
    if len(approx)==3:
        cv.putText(img[i], 'Triangle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))
    elif len(approx)==4:
        
        if aspectratio>=0.95 and aspectratio<=1.05:
            cv.putText(img[i], 'Square',(x,y),cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))
        else:
            cv.putText(img[i],'Rectangle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))

    else :
        cv.putText(img[i], 'Circle', (x,y), cv.FONT_HERSHEY_TRIPLEX, 0.5, (0,0,0))  
  
 
 for line in lines:
        j+=1
        x1,y1,x2,y2 = line[0]
        if  len(lines)==5 and x1<x2:
            cv.putText(img[i],'left', (img[i].shape[0]//2,100), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))
            break
	    
        elif x1<x2:
            cv.putText(img[i],'right', (img[i].shape[0]//2,100), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))

        elif line in lines[-1]:
            cv.putText(img[i], 'straight', ((img[i].shape[0]//2)-150,70), cv.FONT_HERSHEY_TRIPLEX, 1, (0,0,0))
            break
 cv.imshow(f'final{i+1}', cv.resize(img[i], (1280,720)))

 cv.waitKey(0)
