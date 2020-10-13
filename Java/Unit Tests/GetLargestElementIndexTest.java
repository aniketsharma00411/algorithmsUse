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
    public void getLargestElementIndexSecond() {
        int[] array = new int[]{15,6,7,8,9, 5 , 12 , 1 , 9};
        int expected = 0;
        int acutal = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expected,acutal);
    }

    @Test
    public void shouldReturnFirstIndexIfOnlyOneElementIsPresent(){
        int[] array = new int[]{2};
        int expectedIndex = 0;
        int actualIndex = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expectedIndex,actualIndex);
    }

    @Test
    public void shouldReturnTheLeastIndexIfTwoIndicesHaveTheLargestElement() {
        int[] array = new int[]{2,6,6};
        int expectedIndex = 1;
        int actualIndex = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expectedIndex,actualIndex);
    }

    @Test
    public void shouldReturnZeroIfTheSizeOfTheArrayIsZero() {
        int[] array = new int[]{};
        int expectedIndex = 0;
        int actualIndex = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expectedIndex,actualIndex);
    }

    @Test
    public void shouldReturnMinimalIndexIfAllElementsAreEqual() {
        int[] array = new int[]{2,2,2,2,2};
        int expectedIndex = 0;
        int actualIndex = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expectedIndex,actualIndex);
    }

    @Test
    public void shouldReturnTheLeastIndexIfTwoOrMoreIndicesHaveTheLargestElement() {
        int[] array = new int[]{1,4,4,5,6,6,6};
        int expectedIndex = 4;
        int actualIndex = GetLargestElementIndex.getLargestElementIndex(array);
        assertEquals(expectedIndex,actualIndex);
    }





}