import java.util.Scanner;

public class task1 {
    public static int summation(int[] arr) {
        int sum = 0;
        for(int num : arr) {
            sum += num;
        }
        return sum;
    }

    public static int maximum(int[] arr) {
        int max = arr[0];
        for(int num : arr) {
            if(num > max) max = num;
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i+1) + ": ");
            arr[i] = scanner.nextInt();
        }
        System.out.println("Summation: " + summation(arr));
        System.out.println("Maximum: " + maximum(arr));
    }
}
