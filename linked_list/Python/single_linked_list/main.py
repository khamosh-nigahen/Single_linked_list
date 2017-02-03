
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head =  None
	
	def printList(self):
		temp = self.head
		while(temp):
			print "\tNode data : %r" %(temp.data)
			temp = temp.next

	def insertAtFront(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	def insertionAfterGivenNode(self, prev_node, new_data):
		new_node = Node(new_data)
		new_node.next = prev_node.next
		prev_node.next = new_node

	def insertAtEnd(self, new_data):
		new_node = Node(new_data)
		if self.head == None:
			self.head = new_node
			return
		temp = self.head
		while(temp.next):
			temp = temp.next
		temp.next = new_node
	def delNodeWithGivenKey(self, key):
		temp = self.head
		prev = temp
		
		if (temp is None):
			return "List is Empty."
		
		while (temp.data != key):
			prev = temp
			temp = temp.next
		
		prev.next = temp.next
		temp = None
	def delNodeWithGivenPosition(self, pos):
		temp = self.head
		
		if(temp is None):
			return "List is Empty."

		prev = temp
		for i in range(pos):
			if (temp.next is None):
        				raise Exception('You are Trying to delete a node that doesn\'t exist')
			prev = temp
			temp = temp.next
		prev.next = temp.next
		temp = None
			
		
if __name__ == '__main__':
	llist = LinkedList()

	llist.head = Node(1)
	second =  Node(2)
	third =  Node(3)

	llist.head.next = second
	second.next = third

	print "Original Single Linked List"
	llist.printList()

	llist.insertAtFront(0)
	print "Linked List after inserting at front"
	llist.printList()

	llist.insertionAfterGivenNode(second, 2.5)
	print "Linked List after insertion at given node"
	llist.printList()

	llist.insertAtEnd(4)
	print "Linked List after insertion at End"
	llist.printList()

	llist.delNodeWithGivenKey(2.5)
	print "Linked List after deleing a Node with given Key"
	llist.printList()

	llist.delNodeWithGivenPosition(4)
	print "Linked List afer deleting Node at Given Position"
	llist.printList()


