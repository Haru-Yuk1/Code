#一种数出现次数位奇数次，其他数出现次数位偶数次的数组，找到这个数
def printOddTimesNum1(arr):
    eor=0
    for i in arr:
        eor^=i
    print(eor)
#测试
test=[1,1,1,1,2,2,3,3,4,4,4,4,5,5,5,6,6,7,7]
printOddTimesNum1(test)