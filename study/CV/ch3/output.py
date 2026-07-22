import cv2 as cv
import numpy as np

img=cv.imread('soccer.jpg')

for i,color in {0:"B", 1:"G", 2:"R"}.items():
    cv.imshow(f'show {color}',img[img.shape[0]//6:img.shape[0]//2,img.shape[1]//6:img.shape[1]//2, i])

imgs=[]
for i, color in {0:"B", 1:"G", 2:"R"}.items():
    imgs.append(img[img.shape[0]//6:img.shape[0]//2, img.shape[1]//7:img.shape[1]//2, i])

pan=np.hstack(imgs)
cv.imshow("BGR", pan)

cv.waitKey()
cv.destroyAllWindows()