class Node:

    def __init__(self, value = None, next = None):

        self.data = value

        self.next = next

    def __str__(self):

        return str(self.data)

#우선순위 큐

class Priority_que:

    def __init__(self, head = None ):

        self.node = Node(head)

        self.head = self.node

#제일 앞의 큐를 뽑아낸다

    def Dequeue(self):

        self.head = self.head.next

#데이터를 받아서 순위에 따라 배치한다

    def Enqueue(self,data):

        insert_data = Node(data)

        comp = self.head

        pre = Node()

        if insert_data.data < comp.data:

            self.head = insert_data

            insert_data.next = comp

        else:

            while  True:

                if comp.data >= insert_data.data:

                        pre.next = insert_data

                        insert_data.next = comp

                        break

                elif comp.data < insert_data.data:

                    if comp.next == None:

                        comp.next = insert_data

                        break

                    else:

                        pre = comp

                        comp = comp.next

#우선순위 큐를 출력한다

    def PrintLL(self):

        node_print = self.head

        

        while True :

            if node_print.next == None:

                print(node_print.data)

                break

            else:

                print(node_print.data , "->", end=" ")

                node_print = node_print.next

#큐를 만든다

k=Priority_que(5)

#여러 숫자로 큐를 만든다

k.Enqueue(4)

k.Enqueue(7)

k.Enqueue(8)

k.Enqueue(4)

k.Enqueue(7)

k.Enqueue(8)

k.Enqueue(4)

k.Enqueue(7)

k.Enqueue(8)

k.Enqueue(10)

#만든 큐를 출력한다

k.PrintLL()

#큐를 뽑아낸다

k.Dequeue()

k.PrintLL()

k.Dequeue()

k.Dequeue()

k.PrintLL()    
