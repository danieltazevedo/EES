/*
  > Counting sort is a sorting technique based on keys between a specific range.
  > integer sorting algorithm
  > Worst-case performance O(n+k)
  > Stabilized by prefix sum array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int *, int);

int main(int argc, char *argv[])
{
    int length;
    int *arr;

    if (argc < 2) {
        printf("Please provide a valid argument: %s [1|2|3]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (atoi(argv[1]) == 1)
    {
        int a[] = {92594, 17878, 1684, 86293, 67057, 80726, 80395, 23531, 94259, 3850};
        length = sizeof(a) / sizeof(int);
        arr = (int *) malloc(length * sizeof(int));
        memcpy(arr, a, length * sizeof(int));
    }
    else if (atoi(argv[1]) == 2)
    {
        int b[] = {1145, 37918, 4728, 55301, 11693, 79251, 93734, 38981, 65121};
        length = sizeof(b) / sizeof(int);
        arr = (int *) malloc(length * sizeof(int));
        memcpy(arr, b, length * sizeof(int));
    }
    else if (atoi(argv[1]) == 3)
    {
        int c[] = {82631, 2775, 57172, 83873, 71843, 79922, 41070, 62649};
        length = sizeof(c) / sizeof(int);
        arr = (int *) malloc(length * sizeof(int));
        memcpy(arr, c, length * sizeof(int));
    }
    else {
        printf("Invalid argument\n");
        return EXIT_FAILURE;
    }

    counting_sort(arr, length);

    free(arr);
    
    return EXIT_SUCCESS;
}

void counting_sort(int *a, int n)
{
    int i, l = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] > l)
            l = a[i];
    }

    int *b = (int *)malloc((l + 1) * sizeof(int));
    memset(b, 0, (l + 1) * sizeof(b[0]));

    for (i = 0; i < n; i++) b[a[i]]++;  // hashing number to array index

    for (i = 0; i < (l + 1); i++)  // unstable , stabilized by prefix sum array
    {
        if (b[i] > 0)
        {
            while (b[i] != 0)  // for case when number exists more than once
            {
                b[i]--;
            }
        }
    }

    free(b);
}