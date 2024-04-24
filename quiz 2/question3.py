class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    prev = None
    current = head

    while current:
        next_node = current.next  # Store the next node
        current.next = prev  # Reverse the link
        prev = current  # Move prev and current one step forward
        current = next_node

    return prev

# Create a linked list: 1 -> 2 -> 3 -> 4 -> None
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4

# Reverse the linked list
reversed_head = reverseList(node1)

# Print the reversed linked list
current = reversed_head
while current:
    print(current.val, end=" ")
    current = current.next

# Output: 4 3 2 1

"""
Here's how the reverseList function works:

We initialize two pointers: prev and current. prev will keep track of the reversed part of the 
linked list, and current will keep track of the remaining part of the linked list that needs to be
 reversed.
Initially, prev is set to None, and current is set to the head of the linked list.
We iterate through the linked list using a while loop. In each iteration, we perform the following 
steps:

a. Store the next node in the next_node variable (to avoid losing the reference).
b. Reverse the link by setting current.next to prev.
c. Move prev and current one step forward by updating their values with current and next_node, respectively.

After the loop ends, prev will be pointing to the new head of the reversed linked list.
We return prev as the head of the reversed linked list.
The time complexity of this algorithm is O(n), where n is the number of nodes in the linked list,
since we need to iterate through the entire list once. The space complexity is O(1), as we are using
only a constant amount of extra space for the pointer variables.

"""