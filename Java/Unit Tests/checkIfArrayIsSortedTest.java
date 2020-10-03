package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class checkIfArrayIsSortedTest {

    @Test
    public void isSorted() {
        int[] array = new int[]{5,6,7,8,9};
        boolean result = checkIfArrayIsSorted.isSorted(array);
        assertTrue(result);
    }

    @Test
    public void isSortedNOtSorted() {
        int[] array = new int[]{10,5,6,7,8,9};
        boolean result = checkIfArrayIsSorted.isSorted(array);
        assertFalse(result);
    }


}