class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num_1 = ""
        while l1:
            num_1 += str(l1.val)
            l1 = l1.next
        num_2 = ""
        while l2:
            num_2 += str(l2.val)
            l2 = l2.next

        res = str(int(num_1[::-1]) + int(num_2[::-1]))[::-1]
        cur = temp = ListNode(0)
        for e in res:
            cur.next = ListNode(int(e))
            cur = cur.next
        return temp.next
