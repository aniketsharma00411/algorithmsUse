package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class rotateArrayDTimesTest {

    @Test
    public void rotateArr() {
        int[] array = new int[]{5,6,7,7,8 , 8,8,9};
        RotateArrayDTimes.rotateArr(array,array.length,1);
        int[] expected = new int[]{9,8,8,8,7,7,6,5};
        assertArrayEquals(expected,array);
    }
}