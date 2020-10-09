package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class LeftRotateByOneTest {

    @Test
    public void leftRotateByOne() {
        int[] array = new int[]{5,6,7,8,9};
        LeftRotateByOne.leftRotateByOne(array);
        int[] expected = new int[]{6,7,8,9,5};
        assertArrayEquals(expected,array);
    }
}