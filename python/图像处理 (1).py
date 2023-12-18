#!D:/workplace/python
# -*- coding: utf-8 -*-
# @File  : face_prepare.py
# @Author: WangYe
# @Date  : 2019/4/17
# @Software: PyCharm
 
from PIL import Image
import numpy as np
 
 
def readData():
    image_dir0=r"E:\Code\python\QQ图片20231208215207.png"
    image_dir1 = r"E:\Code\python\QQ图片20231208182259.png"
    image_dir2=r"E:\Code\python\QQ图片20231208182313.png"
    x = Image.open(image_dir1) #打开图片
    y=Image.open(image_dir2)
    z=Image.open(image_dir0)
    data1 = np.asarray(x)      #转换为矩阵
    data2=np.asarray(y)
    data0=np.asarray(z)
    print(data1.shape)         #输出矩阵
    print(data2.shape)
    print(data0.shape)
    print(data1)
    count_11=0
    count_12=0
    count_13=0
    count_21=0
    count_22=0
    count_23=0
    count_31=0
    count_32=0
    count_33=0
    for i in range(len(data1)):
        for j in range(len(data1[i])):
            if data1[i][j][0] == 38:
                count_11+=1
            else:
                if data1[i][j][0] !=255:
                    count_12+=1
                else:
                    count_13+=1
    for i in range(len(data2)):
        for j in range(len(data2[i])):
            if data2[i][j][0] == 38:
                count_21+=1
            else:
                if data2[i][j][0] !=255:
                    count_22+=1
                else:
                    count_23+=1
    for i in range(len(data0)):
        for j in range(len(data0[i])):
            if data0[i][j][0] == 38:
                count_31+=1
            else:
                if data0[i][j][0] !=255:
                    count_32+=1
                else:
                    count_33+=1
    print(count_11,count_12,count_13,count_21,count_22,count_23,count_31,count_32,count_33)

    image = Image.fromarray(data1)  #将之前的矩阵转换为图片
    image=Image.fromarray(data2)
    image.show()            #调用本地软件显示图片，win10是叫照片的工具
    #for i in data1:
      #  if i!=0:
        #    i=1
    #print(data1)
readData()
#财产损失系数
#591 218339 34 119 221258 48 1059 220979 2(上述计算数据)分别为绿植面积，火场面积，剩余面积
x_11=(1059-591)/(591+218339+34)#图1财产损失系数
x_21=(1059-119)/(221258+119+48)#图2财产损失系数
x_12=34/(591+218339+34)#图1处理火场费用
x_22=48/(221258+119+48)#图1处理火场费用
print(x_11,x_21,x_12,x_22)#0.0021373376445443086 0.004245229761770351 0.00015527666648398823 0.00021677768996274135数据





