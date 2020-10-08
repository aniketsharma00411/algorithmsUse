package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class GetLargestElementIndexTest {

    @Test
    public void getLargestElementIndex() {
        int[] array = new int[]{5,6,7,8,9};
        int expected = 4;
        int acutal = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expected,acutal);
    }


    @Test
    public void getLargestElementIndexSedcond() {
        int[] array = new int[]{15,6,7,8,9, 5 , 12 , 1 , 9};
        int expected = 0;
        int acutal = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expected,acutal);
    }



}