package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class MoveZerosToEndTest {

    @Test
    public void moveZeroToEnd() {
        int[] array = new int[]{5,0,0,8,9};
        int[] expected = new int[]{5,8,9,0,0};
        MoveZerosToEnd.moveZeroToEnd(array);
        assertArrayEquals(expected,array);
    }

    @Test
    public void moveZeroToEndSecond() {
        int[] array = new int[]{5,8,9};
        int[] expected = new int[]{5,8,9};
        MoveZerosToEnd.moveZeroToEnd(array);
        assertArrayEquals(expected,array);
    }


}