# 定义一个字典，存储左右括号之间的对应关系
pairs = {'>': '<', ')': '(', ']': '[', '}': '{'}
# priority = ['<', '(', '[', '{']
# 定义一个函数，判断输入的字符串中括号是否匹配
def is_valid(s):
    # 定义一个栈，用来存储遇到的左括号
    stack = []
    # 定义一个变量，记录当前遇到的最内层的左括号类型
    
    # 遍历输入的字符串中的每个字符
    for c in s:
        # 如果是左括号
        if c in pairs.values():
            if stack and ((c == '(' and stack[-1]== '<') or \
               (c == '[' and stack[-1] in '<(') or \
               (c == '{' and stack[-1] in '<([')):
                return False
            # 将其压入栈中
            stack.append(c)
            # 更新最内层的左括号类型
            
        # 如果是右括号
        elif c in pairs:
            # 如果栈为空，或者栈顶的左括号与之不匹配
            if not stack or stack.pop() != pairs[c]:
                # 返回NO
                return False
            # 如果当前的右括号与最内层的左括号类型不符合要求
            
        else:
            return False    
    # 如果遍历完字符串后，栈为空
    return not stack

# 读取第一行输入，表示有多少个字符串
n = int(input())
# 循环n次
for i in range(n):
    # 读取每一行输入，表示一个由括号组成的字符串
    s = input()
    # 调用函数判断该字符串中括号是否匹配，并输出结果
    print("YES" if is_valid(s) else "NO")
