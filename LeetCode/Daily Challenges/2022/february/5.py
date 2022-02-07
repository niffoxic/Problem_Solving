from queue import PriorityQueue


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        root = point = ListNode(0)
        q = PriorityQueue()
        for i in lists:
            if i:
                q.put((i.val, i))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return root.next

  # 2nd
  
  class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        total = len(lists)
        i = 1
        while i < total:
            for j in range(0, total - i, i * 2):
                lists[j] = self.merge_them(lists[j], lists[i + j])
            i *= 2
        return lists[0] if total > 0 else None

    def merge_them(self, arr1, arr2):
        head = point = ListNode(0)
        while arr1 and arr2:
            if arr1.val <= arr2.val:
                point.next = arr1
                arr1 = arr1.next
            else:
                point.next = arr2
                arr2 = arr1
                arr1 = point.next.next
            point = point.next
        if not arr1:
            point.next = arr2
        else:
            point.next = arr1

        return head.next
