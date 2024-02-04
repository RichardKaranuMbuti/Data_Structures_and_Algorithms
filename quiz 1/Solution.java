public class Solution {

    // Question 1: Remove Duplicates from Sorted Array
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    // Question 2: Rotate Array
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    // Question 3: Contains Duplicate
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) {
                return true;
            }
        }
        return false;
    }

    // Question 4: Single Number
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Question 1
        int[] nums1 = {1, 1, 2};
        System.out.println("Q1. New length after removing duplicates: " + solution.removeDuplicates(nums1));

        // Test Question 2
        int[] nums2 = {1, 2, 3, 4, 5, 6, 7};
        solution.rotate(nums2, 3);
        System.out.print("Q2. Array after rotation: ");
        for (int num : nums2) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Test Question 3
        int[] nums3 = {1, 2, 3, 1};
        System.out.println("Q3. Contains duplicate: " + solution.containsDuplicate(nums3));

        // Test Question 4
        int[] nums4 = {4, 1, 2, 1, 2};
        System.out.println("Q4. Single number: " + solution.singleNumber(nums4));
    }
}
