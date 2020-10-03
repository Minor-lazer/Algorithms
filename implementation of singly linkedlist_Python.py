class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class Linkedlist:
    def __init__(self):
        self.head=None

    def lengthOfLinkedList(self):
        currentnode=self.head
        length=0
        while currentnode is not None:
            length+=1
            currentnode=currentnode.next
        return length

    def isEmpty(self):
        if self.lengthOfLinkedList()==0:
            return True
        else:
            return False

    def insertHead(self,newNode):
        temp=self.head
        self.head=newNode
        self.head.next=temp
        del temp

    def insertEnd(self, newNode):
        if self.head is None:
            self.head=newNode
        else:
            lastnode=self.head
            while True:
                if lastnode.next is None:
                    break
                lastnode=lastnode.next
            lastnode.next=newNode

    def insertAt(self,newNode,position):
        if position<0 or position>self.lengthOfLinkedList():
            print('You enter wrong position retarted person,FUCK OFF!!')
            return
        if position==0:
            self.insertHead(newNode)
            return
        currentNode=self.head
        currentpositon=0
        while True:
            if currentpositon==position:
                prev.next=newNode
                newNode.next=currentNode
                break
            prev=currentNode
            currentNode=currentNode.next
            currentpositon += 1

    def deleteEnd(self):
        lastnode=self.head
        while lastnode.next is not None:
            prev=lastnode
            lastnode=lastnode.next
        prev.next=None


    def delethead(self):
        if self.isEmpty() is False:
            prevHead=self.head
            self.head=self.head.next
            prevHead.next=None
        else:
            print('List empty')

    def deleteAt(self,position):
        if position<0 or position>self.lengthOfLinkedList():
            print('You enter wrong position retartdd person,FUCK OFF!!')
        elif self.isEmpty() is False:
            if position==0:
                self.delethead()
                return
            currentNode=self.head
            currentpos=0
            while True:
                if currentpos==position:
                    prev.next=currentNode.next
                    currentNode.next=None
                    break
                prev=currentNode
                currentNode=currentNode.next
                currentpos+=1

    def printLinkedlist(self):
        if self.head is None:
            print('Empty')
            return
        currentNode=self.head
        while True:
            if currentNode is None:
                break
            print(currentNode.data)
            currentNode=currentNode.next


firstnode=Node('John')
linkedlist=Linkedlist()
linkedlist.insertEnd(firstnode)
secondnode=Node('Bem')
linkedlist.insertEnd(secondnode)
thirdnode=Node('Bikash')
linkedlist.insertHead(thirdnode)
fourthnode=Node('hello')
linkedlist.insertAt(fourthnode,2)
#linkedlist.deleteEnd()
linkedlist.deleteAt(2)
#linkedlist.delethead()
linkedlist.printLinkedlist()