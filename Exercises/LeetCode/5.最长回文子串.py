s=input()
test=''
testm=''
count=0

for i in range(len(s)):
    test+=s[i]
    for j in range(i+1,len(s)):
        test+=s[j]
    
        if(test==test[::-1]and count<len(test)):
            
            count=len(test)
            testm=test     
    test=''
if testm=='':
    print(s[0],)
print(testm,end='')