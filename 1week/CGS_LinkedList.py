class Node:
    def __init__(self,data=None): # __init__ : 초기자(initializer)
        self.data=data
        self.next=None # 다음
        self.prev=None # 이전 # self.* : 인스턴스 변수

        #노드->class Node
#데이터를 담는 멤버변수 -> self.data
#링크를 담는 멤버변수 -> self.next, self.prev

head=Node() #head 객체 생성
tail=Node() #tail 객체 생성
head.next=tail #다음 노드의 머리와 현재 노드의 꼬리를 링크(head객체의 인스턴스 변수 next에 tail을 전달)   
tail.prev=head #이전 노드의 꼬리와 현재 노드의 머리를 링크
    
    #메소드                  #파이썬에서 함수와 메소드 차이 : 클래스 안/밖 + 인스턴스
def insert_node(): #노드 삽입 함수 정의
    
    data=input("input : ")  #data에 입력
    node=Node(data) #현재 입력한 data를 현재 노드에 저장

#인스턴스 메서드 => 객체변수.메서드명()
#인스턴스 변수 => 객체변수.인스턴스변수
#클래스 변수 엑세스 => 클래스명.클래스변수명 / 객체명.클래스변수명

    node.prev=tail.prev #이전 노드의 꼬리를 연결
    node.next=tail #다음 노드와 현재 꼬리를 연결
    
    tail.prev.next=node 
    tail.prev=node

def print_node():
    node=head.next

    while node != tail: 
        print("data: "+node.data)
        print()
        
        node=node.next

def delete(find):
    node=head
    while node:
        if node.data==find:
            node.prev.next=node.next
            node.next.prev=node.prev
            del node
            break
        node=node.next
        
def search(find):
    node=head
    while node:
        if node.data==find:
            print("O")
            break
        node=node.next

        
while True:
    print("1. input")
    print("2. delete")
    print("3. serach")
    print("4. print")
    print("5. exit")
    print("-----------------------------------")
    cmd=input("select a list: ")
    if cmd=='1':
        insert_node()
    elif cmd=='2':
        find=input()
        delete(find)
    elif cmd=='3':
        find=input()
        search(find)
    elif cmd=='4':
        print_node()
    elif cmd=='5':
        break
    else:
        print("Unknown Number")