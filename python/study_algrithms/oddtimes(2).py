#其中两种数出现次数位奇数次，其他数出现次数为偶数次，找到这两个数
def printOddTimesNum2(arr):
    eor=0
    for i in arr:
        eor^=i
    rightone=eor&(~eor+1) #提取出最右的1，比如eor=1010111100 则~eor=01010000100,~eor+1=01010001,eor&(~eor+1)=0000000100
    onlyone=0
    for i in arr:
        if i&rightone==0:
            onlyone^=i
    print(f'{onlyone}和{onlyone^eor}')

test=[1,1,1,1,2,2,3,3,4,4,4,4,5,5,5,6,6,7]
printOddTimesNum2(test)