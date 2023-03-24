#include <iostream>
using namespace std;
#include <cstdlib> 

int Max(int Arr[], int N) {
    int max = Arr[0];
    for (int i = 1; i < N; i++)
        if (Arr[i] > max)
            max = Arr[i];
    return max;
}

int Min(int Arr[], int N) {
    int min = Arr[0];
    for (int i = 1; i < N; i++)
        if (Arr[i] < min)
            min = Arr[i];
    return min;
}


int *Counting_Sort(int Arr[], int N) {
    int max = Max(Arr, N);
    int min = Min(Arr, N);
    int *Sorted_Arr = new int[N];

    int *Count = new int[max - min + 1];

    for (int i = 0; i < N; i++) Count[Arr[i] - min]++;

    for (int i = 1; i < (max - min + 1); i++) Count[i] += Count[i - 1];

    for (int i = N - 1; i >= 0; i--) {
        Sorted_Arr[Count[Arr[i] - min] - 1] = Arr[i];
        Count[Arr[i] - min]--;
    }

    return Sorted_Arr;
}

int main(int argc, char* argv[]) {

    if (std::atoi(argv[1]) == 1) {
        int a[] = {2523,3613,9347,2881,9405,392,3626,5100,4312,605,3037,8870,2976,3422,7853,6575,2148,6619,405,2018,4830,9448,7251,8290,4318,8032,4951,5115,202,6403,9549,9077,6368,5248,8310,5774,5641,1937,7226,9953,8894,6615,5175,1870,38,9380,8445,2186,2352,5202,556,7182,4651,7808,5472,8969,5840,6775,437,2394,3178,6338,7823,9547,1586,6134,1673,7227,4423,8899,3532,9669,5514,8708,1539,5552,4440,6336,4091,6792,1539,4647,326,2542,8807,2151,7863,999,8926,8300,9745,8457,4638,7569,4356,6225,55,6029,9804,830};
        int length = sizeof(a) / sizeof(int);
        Counting_Sort(a, length);
    }

    if (std::atoi(argv[1]) == 2) {
        int b[] = {3244,9467,734,3310,4273,888,3941,4252,473,8198,5483,7359,8137,7939,8740,2573,3534,8321,8480,1669,5230,1456,5957,1844,5322,9773,9063,1280,6980,5948,7500,224,5415,8234,3534,9689,9122,3827,293,5948,8377,5776,9659,2867,67,8399,5440,9953,6721,272};
        int length = sizeof(b) / sizeof(int);
        Counting_Sort(b, length);
    }

    if (std::atoi(argv[1]) == 3) {
        int c[] = {8237,6224,5942,8806,9538,6749,8089,2471,5767,2912};
        int length = sizeof(c) / sizeof(int);
        Counting_Sort(c, length);
    }

    return EXIT_SUCCESS;
}
