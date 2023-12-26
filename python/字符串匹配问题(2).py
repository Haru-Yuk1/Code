# 定义一个字典，存储括号的对应关系
brackets = {'(': ')', '[': ']', '<': '>', '{': '}'}

# 定义一个列表，存储括号的优先级
priority = ['<', '(', '[', '{']

# 定义一个函数，判断一个字符串是否是合法的括号序列
def is_valid(s):
    # 定义一个栈，用来存储未匹配的左括号
    stack = []
    # 遍历字符串中的每个字符
    for c in s:
        # 如果是左括号，就把它压入栈中
        if c in brackets:
            # 如果栈不为空，就检查栈顶的左括号是否比当前的左括号优先级高
            if stack and priority.index(stack[-1]) < priority.index(c):
                # 如果是，就返回False，因为不符合顺序要求
                return False
            # 如果不是，就把当前的左括号压入栈中
            stack.append(c)
        # 如果是右括号，就检查栈顶的左括号是否与之匹配
        elif c in brackets.values():
            # 如果栈为空，或者栈顶的左括号与右括号不匹配，就返回False
            if not stack or brackets[stack.pop()] != c:
                return False
            # 如果栈不为空，且栈顶的左括号与右括号匹配，就继续循环
        # 如果既不是左括号也不是右括号，就返回False
        else:
            return False
    # 遍历完字符串后，检查栈是否为空，如果为空，就返回True，否则返回False
    return not stack

# 读取输入的第一行，表示有多少个字符串
n = int(input())
# 循环n次，读取每个字符串，并判断是否合法
for i in range(n):
    s = input()
    if is_valid(s):
        print('YES')
    else:
        print('NO')
