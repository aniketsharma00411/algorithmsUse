package Array;

import org.junit.Test;

import static org.junit.Assert.*;

public class deleteElementTest {

    @Test
    public void testdeleteElement() {
        int[] array = new int[]{5,6,7,8,9};
        DeleteElement.deleteElement(array,array.length,5);
        int[] deletedArray = new int[]{6,7,8,9};

        assertArrayEquals(deletedArray,array);
    }
}