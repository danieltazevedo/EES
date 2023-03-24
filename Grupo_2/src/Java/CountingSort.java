// Counting sort in Java programming

import java.util.Arrays;

class CountingSort {
  void countSort(int array[], int size) {
    int[] output = new int[size + 1];

    // Find the largest element of the array
    int max = array[0];
    for (int i = 1; i < size; i++) {
      if (array[i] > max)
        max = array[i];
    }
    int[] count = new int[max + 1];

    // Initialize count array with all zeros.
    for (int i = 0; i < max; ++i) {
      count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
      count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
      array[i] = output[i];
    }
  }

  // Driver code
  public static void main(String args[]) {
    CountingSort cs = new CountingSort();
    if(Integer.parseInt(args[0])==1 ) { 
        int a[] = {2523,3613,9347,2881,9405,392,3626,5100,4312,605,3037,8870,2976,3422,7853,6575,2148,6619,405,2018,4830,9448,7251,8290,4318,8032,4951,5115,202,6403,9549,9077,6368,5248,8310,5774,5641,1937,7226,9953,8894,6615,5175,1870,38,9380,8445,2186,2352,5202,556,7182,4651,7808,5472,8969,5840,6775,437,2394,3178,6338,7823,9547,1586,6134,1673,7227,4423,8899,3532,9669,5514,8708,1539,5552,4440,6336,4091,6792,1539,4647,326,2542,8807,2151,7863,999,8926,8300,9745,8457,4638,7569,4356,6225,55,6029,9804,830};
        int size = a.length;
        cs.countSort(a, size);
    }

    if(Integer.parseInt(args[0])==2 ) {
        int b[] = {3244,9467,734,3310,4273,888,3941,4252,473,8198,5483,7359,8137,7939,8740,2573,3534,8321,8480,1669,5230,1456,5957,1844,5322,9773,9063,1280,6980,5948,7500,224,5415,8234,3534,9689,9122,3827,293,5948,8377,5776,9659,2867,67,8399,5440,9953,6721,272};
        int size = b.length;
        cs.countSort(b, size);
    }

    if(Integer.parseInt(args[0])==3 ) {
        int c[] = {8237,6224,5942,8806,9538,6749,8089,2471,5767,2912};
        int size = c.length;
        cs.countSort(c, size);
    }
  }
}