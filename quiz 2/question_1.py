
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def hasCycle(head):
    if not head or not head.next:
        return False

    # Initialize two pointers: slow and fast
    slow = head
    fast = head.next

    # Move slow pointer one step and fast pointer two steps
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        # If slow and fast pointers meet, there is a cycle
        if slow == fast:
            return True

    # If we reach the end of the list without meeting, there is no cycle
    return False


# Example 1: Linked list with a cycle
node1 = ListNode(3)
node2 = ListNode(2)
node3 = ListNode(0)
node4 = ListNode(-4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2  # Creating a cycle

print(hasCycle(node1))  # Output: True

# Example 2: Linked list without a cycle
node1 = ListNode(1)
node2 = ListNode(2)

node1.next = node2

print(hasCycle(node1))  # Output: False

# Explanation
'''
We initialize two pointers, slow and fast, both pointing to the head of the linked list.
We move the slow pointer one step, and the fast pointer two steps at each iteration.
If there is a cycle in the linked list, the slow and fast pointers will eventually meet because 
the fast pointer will catch up with the slow pointer from behind.
If there is no cycle, the fast pointer will eventually reach the end of the list, and the loop will 
terminate.
The time complexity of this algorithm is O(n), where n is the number of nodes in the linked list, 
because in the worst case (when there is no cycle), the fast pointer will visit every node once.
 The space complexity is O(1) since we are using only two pointer variables.
'''