x=int(input())
def isPalindrome(x):
    if x<0:
        return False
    if x==0:
        return True
    else:
        right=str(x)
        if right==right[len(right)-1::-1]:
            return True
        else:
            return False
        
print(isPalindrome(x))