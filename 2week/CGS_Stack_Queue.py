#Stack

class stack:
    def __init__(self):
        self.stack_items=[]
    
    # pop 기능 구현
    def pop(self):
        item_length=len(self.stack_items)
        # 스택이 비어있을때는 에러메세지 출력
        if item_length < 1:
            print("Stack is empty!")
            return False
        # 가장 위에 있는 item을 반환하며 삭제
        result = self.stack_items[item_length-1]
        del self.stack_items[item_length-1]
        return result
    
    # push
    def push(self,x):
        self.stack_items.append(x)
        
    # isEmpty
    def isEmpty(self):
        return not self.stack_items

# Test
test1 = stack()
print(test1.stack_items)
test1.push(3)
print(test1.stack_items)
test1.push(5)
test1.push(7)
test1.push(9)
test1.push(11)
print(test1.stack_items)
print(test1.isEmpty())
print(test1.pop())
print(test1.pop())
print(test1.pop())
print(test1.pop())
print(test1.pop())
print(test1.pop())
print(test1.isEmpty())

################################

#Queue

class Queue:
    def __init__(self):
        self.Queue_item = []
        
    # Enqueue
    def Enqueue(self,x):
        self.Queue_item.append(x)
        return None
    
    # Dequeue
    def Dequeue(self):
        item_length = len(self.Queue_item)
        if item_length < 1:
            print("Queue is empty!")
            return False
        result = self.Queue_item[0]
        del self.Queue_item[0]
        return result
    
    # isEmpty
    def isEmpty(self):
        return not self.Queue_item

#Test
test = Queue()
print(test.Queue_item)
test.Enqueue(1)
print(test.Queue_item)
print(test.Dequeue())
test.Enqueue(2)
test.Enqueue(3)
test.Enqueue(4)
test.Enqueue(5)
print(test.Queue_item)
print(test.Dequeue())
print(test.Dequeue())
print(test.Dequeue())
print(test.Dequeue())
print(test.Dequeue())
test.Enqueue(1)
print(test.isEmpty())
