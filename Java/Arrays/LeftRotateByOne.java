package Array;

public class LeftRotateByOne {

    public static void leftRotateByOne(int[] a) {
        int temp = a[0];
        int n = a.length;
        System.arraycopy(a, 1, a, 0, n - 1);
        a[n - 1] = temp;
    }

}
