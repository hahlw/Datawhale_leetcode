class Solution(object):
    def merge(nums1, m, nums2, n):
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(n):
            current = nums2[i]
            index = m-1
            while current < nums1[index] and index >= 0:
                nums1[index+1] = nums1[index]
                index -= 1
            nums1[index+1] = current
            m += 1
        return nums1