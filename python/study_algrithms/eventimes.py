#一种数出现次数为偶数次，其他数出现次数位奇数次的数组，找到这个数
def printEvenTimesNum1(arr):
    eor=0
    for i in arr:
        eor=eor^~i # 求同或即可
    print(eor)

#测试
test=[1,1,1,2,3,4,4,4,5,5,5,6,6,6,7,7]
printEvenTimesNum1(test)
