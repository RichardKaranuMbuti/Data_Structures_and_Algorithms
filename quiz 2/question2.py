class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detectCycle(head):
    if not head or not head.next:
        return None

    # Step 1: Use Floyd's cycle-finding algorithm to detect a cycle
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break  # Cycle detected

    # If no cycle is detected, return None
    if not fast or not fast.next:
        return None

    # Step 2: Find the starting point of the cycle
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    # slow now points to the start of the cycle
    return slow

# Example 1: Linked list with a cycle
node1 = ListNode(3)
node2 = ListNode(2)
node3 = ListNode(0)
node4 = ListNode(-4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2  # Creating a cycle

cycle_start = detectCycle(node1)
print(cycle_start.val)  # Output: 2

# Example 2: Linked list without a cycle
node1 = ListNode(1)
node2 = ListNode(2)

node1.next = node2

cycle_start = detectCycle(node1)
print(cycle_start)  # Output: None


## Explanation
"""
Here's how the algorithm works:

We first use Floyd's cycle-finding algorithm (tortoise and hare) to detect if there is a cycle in the 
linked list. If there is no cycle, we return None.
If a cycle is detected, we move the slow pointer back to the head of the linked list.
We then move both slow and fast pointers one step at a time until they meet. The point where they meet
 is the starting node of the cycle.
We return the node where the cycle begins.

Here's an explanation of why this works:
Suppose the cycle starts at node C, and the distance between the head and the start of the cycle is x. 
Let the length of the cycle be y. When the slow and fast pointers meet during the cycle detection phase, the slow pointer has traveled x + y steps, and the fast pointer has traveled x + y + n*y steps, where n is the number of cycles the fast pointer has made around the cycle. Since the fast pointer moves twice as fast as the slow pointer, we can say that x + y + n*y = 2(x + y), which simplifies to x = n*y.
When we move the slow pointer back to the head and move both slow and fast pointers one step at a time,
the fast pointer has moved n*y steps ahead of the slow pointer. Since x = n*y, the slow and fast
 pointers will meet at the start of the cycle (node C).
The time complexity of this algorithm is O(n), where n is the number of nodes in the linked list, 
because in the worst case (when there is no cycle), we visit each node once during the cycle detection 
phase. The space complexity is O(1) since we are using only a constant amount of extra space for the 
pointer variables.

"""
