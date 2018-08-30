# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST_2(self, array):
        #print array
        l = len(array)
        if l == 0:
            return None
        elif l == 1:
            return TreeNode(array[0])
        else:
           
            mid = l // 2
            #print 'mid = ', mid
            root = TreeNode(array[mid])
            left = self.sortedListToBST_2(array[:mid])
            if mid == l - 1:
                right = None
            else:
                right = self.sortedListToBST_2(array[mid + 1: l])
            
            root.left = left
            root.right = right

            
            return root
            
        
        
    
    def sortedListToBST(self, head):
        """
        :type head: ListNode    
        :rtype: TreeNode
        """
        array = []
        while(head != None):
            array.append(head.val)
            head = head.next
        
        return self.sortedListToBST_2(array)
