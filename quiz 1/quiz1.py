# Question 1: Remove Duplicates from Sorted Array
def remove_duplicates(nums):
    if not nums:
        return 0
    length = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i-1]:
            nums[length] = nums[i]
            length += 1
    return length

# Question 2: Rotate Array
def rotate_array(nums, k):
    n = len(nums)
    k %= n
    nums[:] = nums[-k:] + nums[:-k]

# Question 3: Contains Duplicate
def contains_duplicate(nums):
    nums_set = set(nums)
    return len(nums_set) < len(nums)

# Question 4: Single Number
def single_number(nums):
    unique = 0
    for num in nums:
        unique ^= num
    return unique

# Usage
nums1 = [1, 1, 2,1, 1, 2,1, 1, 2]
print("Q1. New length after removing duplicates:", remove_duplicates(nums1))
print("Modified array:", nums1[:remove_duplicates(nums1)])

nums2 = [1,2,3,4,5,6,7,1,2,3,4,5,6,7]
k = 3
rotate_array(nums2, k)
print("Q2. Array after rotation:", nums2)

nums3 = [1,2,3,1, 1,2,3,4,5,6,7]
print("Q3. Contains duplicate:", contains_duplicate(nums3))

nums4 = [4,1,2,1,2,1,2,3,4,5,6,7]
print("Q4. Single number:", single_number(nums4))
