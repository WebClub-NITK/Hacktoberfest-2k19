import numpy as np
import cv2
import argparse

parser =argparse.ArgumentParser()
parser.add_argument("--color",type=str,default='R',help="insert uppercase first letter in color you want to see its output")
parser.add_argument("--image",type=str,default="colors.png",help="Specify the image location")
arg = parser.parse_args()

colors = ['R','G','B','Y','M','C']


image = arg.image
color = arg.color
img = cv2.imread(image)

R_channel = img[:,:,2]
G_channel = img[:,:,1]
B_channel = img[:,:,0]

#Red colors
imageR = img.copy()
imageR[R_channel < 128 ] = 0
imageR[G_channel > 51] = 0
imageR[B_channel > 51] = 0
imageR = cv2.resize(imageR,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))


#Green Colors
imageG = img.copy()
imageG[G_channel <100] = 0
imageG[R_channel > 173 ]=0
imageG[B_channel > 102]=0
imageG = cv2.resize(imageG,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))

#Blue color
imageB = img.copy()
imageB[B_channel < 205] = 0
imageB[(G_channel > 153)]=0
imageB[R_channel > 51]=0
imageB = cv2.resize(imageB,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))


#Yellow color
imageY = img.copy()
imageY[(B_channel  < 51) & (B_channel > 153)] = 0
imageY[(G_channel < 200)]=0
imageY[R_channel < 200]=0
imageY = cv2.resize(imageY,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))

#Yellow color
imageM = img.copy()
imageM[B_channel < 153]=0
imageM[(R_channel  < 76)] = 0
imageM[(G_channel >51)]=0
imageM = cv2.resize(imageM,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))

#Cyan color
imageC = img.copy()
imageC[B_channel < 153]=0
imageC[(G_channel  < 153)] = 0
imageC[(R_channel >51)]=0
imageC = cv2.resize(imageC,(int(img.shape[1]*0.5),int(img.shape[0]*0.5)))

images = [imageR,imageG,imageB,imageY,imageM,imageC]
image_sel = images[colors.index(color)]

cv2.imshow("image",image_sel)

cv2.waitKey(0)
cv2.destroyAllWindows()
