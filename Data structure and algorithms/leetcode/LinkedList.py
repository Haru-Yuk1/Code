# 链节点类
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 链表类
class LinkedList:
    def __init__(self):
        self.head = None
# 根据 data 初始化一个新链表
    def create(self, data):
        self.head = ListNode(0)
        cur = self.head
        for i in range(len(data)):
            node = ListNode(data[i])
            cur.next = node
            cur = cur.next


if __name__=="__main__":
    LinkedList