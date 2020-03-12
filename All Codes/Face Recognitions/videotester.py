# -*- coding: utf-8 -*-
import cv2
import os
import numpy as np
import FaceRecognition as fr

face_recognizer = cv2.face.LBPHFaceRecognizer_create()
strr = os.path.abspath('traindata.yml')
face_recognizer.read(strr)
name = {1:"Andy",0:"Rachit",2:"Mili",3"Cody",4:"Zack"}

cap = cv2.VideoCapture(0)

while True:
    ret,test_img = cap.read()
    faces_detected, gray_img = fr.faceDetection(test_img)
    for fs in faces_detected:
        (x,y,w,h) = fs
        roi_gray = gray_img[y:y+h,x:x+h]
        label,confidence = face_recognizer.predict(roi_gray)
        fr.draw_rect(test_img,fs)
        predicted_name = name[label]
        fr.put_text(test_img,predicted_name,x,y)
    
    test_img = cv2.resize(test_img,(500,500))
    cv2.imshow("Images", test_img)
    if cv2.waitKey(10) == ord('q'):
        break


cap.release()
#cv2.waitKey(0)
cv2.destroyAllWindows