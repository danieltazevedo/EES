#include <bits/stdc++.h> 
using namespace std; 
#include <iostream>
#include <cstdlib> 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

// Driver Code
int main(int argc, char* argv[]) {

    if (std::atoi(argv[1]) == 1) {
        int a[] = {92594,17878,1684,86293,67057,80726,80395,23531,94259,3850};
        int length = sizeof(a) / sizeof(int);
        quickSort(a, 0, length - 1);
    }

    if (std::atoi(argv[1]) == 2) {
        int b[] = {1145,37918,4728,55301,11693,79251,93734,38981,65121,64340,98907,44544,91488,75720,28334,56379,72872,9570,5685,5778,94497,71062,22468,77876,98831,32550,4138,90394,17738,98604,44845,35236,52874,65925,90537,64567,45176,84271,19901,10297,64963,18808,71194,72803,10881,15880,29182,105,41803,51219,5883,36300,38634,28351,14176,37465,77254,34667,44211,94992,33271,89057,46580,86146,71334,37117,67065,16511,37740,86966,43160,2703,22127,14354,75507,49360,30235,21041,49465,72038,88613,71700,8338,27247,16403,22514,81064,93657,57181,25276,88650,6805,30685,35230,9303,2019,88700,76368,18530,26440};
        int length = sizeof(b) / sizeof(int);
        quickSort(b, 0, length - 1);
    }

    if (std::atoi(argv[1]) == 3) {
        int c[] = {82631,2775,57172,83873,71843,79922,41070,62649,11136,10027,67349,5758,56523,48956,884,20618,85247,65608,44501,46469,11284,159,83148,84169,80151,61456,96618,53867,72759,69136,63558,55390,88264,37082,55615,76459,17004,96685,39108,44492,23064,6458,50250,79587,71766,67486,205,57014,33095,61059,19835,60731,61218,19335,61253,57721,80791,57871,11588,53550,43360,91498,25292,31624,44932,97259,8083,78288,10296,63543,22780,33361,86353,73030,12948,58120,40516,29506,31486,89963,6917,51321,67047,84487,87008,28300,42208,67799,86171,70148,37702,29531,61646,62994,77507,6578,60254,1942,84866,86902,65486,7646,20263,51839,97028,49564,26311,53896,79070,74149,60212,2339,41822,27259,86826,28830,71911,29034,96630,74434,99182,34332,3966,77180,13678,97825,83758,90284,99768,84976,77187,81606,8974,97450,49797,22354,63366,76109,76250,58788,50258,52814,61127,92081,96425,47953,20911,68336,76987,33893,42771,76169,68225,63089,53349,98256,60914,53459,88540,77034,54787,82079,58640,80113,95882,8438,2467,59248,899,95070,18037,51157,47884,79164,59590,44310,27118,96854,28998,4105,30747,71769,96627,15325,51210,66328,13581,28477,36140,18473,5511,7279,553,64152,87393,96435,88942,89860,55683,89841,1282,73720,57350,49167,52885,16941,9829,96355,13795,38827,16812,60894,26949,29791,76219,78159,96120,89800,6636,48612,8274,28500,55891,25179,9004,43284,21614,97946,49497,77297,87787,50779,67370,61489,16298,36607,78430,42479,49314,8577,97659,66126,69472,24608,95918,62043,19119,8390,51844,42108,73354,76470,70608,29245,1649,79612,88882,23263,77558,38379,16912,81697,5510,634,43186,21809,53593,37969,80640,2907,62898,78299,69034,48722,2907,81304,10766,38379,89694,62610,80487,63048,55432,51095,8645,57081,30707,97527,96696,24617,52258,29960,22666,74121,46947,82204,12282,540,20173,92922,3448,99424,71222,88834,48146,90481,70138,58912,28860,76184,37874,25699,55584,93306,76794,64229,66739,23853,78109,79787,64822,46719,9748,87488,20840,56695,69693,33122,73587,89866,42397,77035,5642,13619,65869,53789,20452,52359,12701,65665,44895,66928,91364,479,76586,68159,81061,43326,8364,75522,39465,73187,22241,49213,60675,59434,22260,30368,8908,95848,36587,51305,89235,58581,81276,71457,12370,1729,23816,41424,83746,85064,8352,75110,85543,1290,59621,66604,60968,67986,42126,434,57525,80720,65999,18200,40154,4612,64921,49062,460,17860,16720,6047,76441,97996,77504,5164,16077,17673,46588,99823,2737,71292,74934,88280,72582,50907,71237,33551,18893,29715,33985,92770,26787,16336,27323,66941,20948,92244,32356,21408,26456,49076,43808,19249,63424,21312,24413,79502,38985,87353,95677,58074,58645,86963,62707,31228,37871,50296,81131,73116,80011,31468,65887,6799,47804,93210,90092,68753,1806,38800,6513,44614,87876,50321,63863,67653,71634,4629,47155,26971,91982,42832,1398,50628,29796,64105,98208,84019,14401,79339,57135,10764,10807,39374,33915,74963,32584,40360,43716,50742,79160,50230,95356,83389,551,75572,51042,88537,80201,98197,15509,88535,57381,16907,39163,3529,81012,53723,87548,11765,49414,61036,22529,76573,410,72797,51537,49347,13157,95253,89,92317,61835,11798,75706,62387,3722,26748,50924,83923,41297,82785,88810,15031,99692,44326,18560,97056,98049,22461,25173,63816,99849,64055,40389,259,36852,8278,65958,50009,19884,66048,58678,81719,94198,34385,44106,97920,77485,11383,98195,35135,94168,87005,50166,10213,31331,85078,23621,45733,23891,48795,9549,23740,12850,66290,40352,49702,74569,6310,16063,94453,88710,74741,92524,82908,9126,52983,97180,2964,64366,95375,38099,74886,98733,88265,1451,46416,89695,25073,92149,13587,73868,18050,53679,3070,693,94031,69124,75262,16694,85187,86067,5404,59928,78591,4665,85407,47926,1845,88371,12292,13573,42822,3531,12306,47439,4982,58722,37134,30055,67224,67073,20275,1626,20753,39697,2319,31136,8821,77581,47830,94008,80000,53235,70289,74944,74252,55696,22870,76097,60419,35163,6022,3241,55046,18328,50680,60028,93403,87814,6436,76979,54888,43063,78605,91993,82761,80925,23129,7934,58506,70960,18295,54859,40547,88584,29803,14799,60632,52673,7248,21051,4188,29623,24292,59234,47951,74972,35615,57706,79138,58403,34685,50378,17818,13291,42371,579,10568,81853,24866,85426,52813,43161,40285,9712,48097,70088,40863,8729,39114,64463,29780,59654,94086,70424,18889,42038,45396,70856,16096,40886,45611,67134,7617,63429,80425,66340,80361,90993,48193,5227,92771,17358,64740,33057,27070,12837,19497,84285,21566,58611,48749,51346,18266,42835,21770,53507,1225,83518,40715,17322,40756,86326,84456,48373,49755,81233,31066,30116,88578,79259,35343,81349,96618,83,30758,40040,29272,50256,24326,50838,8867,89427,18536,43485,32262,56658,13344,33488,56528,54059,67162,13637,40385,51618,78362,90141,49203,9428,20257,54133,88688,71953,51834,1658,88388,82593,58050,17661,32849,98728,84851,58068,88155,19740,1554,36770,76398,14898,70258,49279,68958,53772,62916,25695,21742,41278,15836,70945,50707,52446,41430,55747,40751,93264,73757,29139,75857,48159,63152,8706,46888,64356,83127,51395,84096,84681,88165,76846,15931,74775,26125,1241,28547,5393,26937,66641,63024,59125,37586,30083,11571,95368,85830,68674,88633,75939,14166,64490,24098,77318,89549,87338,58026,72676,55086,42122,73709,59603,18969,5992,50731,61446,7234,95630,66840,50523,62272,46216,9648,16210,76299,37572,11579,78481,6246,212,54420,20412,81054,94870,14083,70603,98561,72109,59631,53647,30584,33340,13250,49553,39333,80333,27351,62919,75964,10543,13442,38236,56759,23090,54446,33058,77014,66025,27891,99613,66237,82311,36377,63644,93534,50460,34247,92095,38922,10231,62094,69506,59923,91696,35411,15608,72030,79114,78527,47994,89658,91969,86230,62769,31412,57028,12180,24778,23054,40071,24391,5643,38735,60769,69287,32269,27581,19887,24364,82855,30118,2810,52361,6393,94506,4124,22002,66536,83239,529,14530,89249,8851,17112,52018,56615,74141,80550,81393,97195,20622,5785,19190,59357,82906,4830,91626,26839,24717,32342,9695,71187,35152,62056,77580,29658,82533,15934,12547,82124,16464,27077,71373,25315,44190,39743,81930,34683,36646};
        int length = sizeof(c) / sizeof(int);
        quickSort(c, 0, length - 1);
    }

    return EXIT_SUCCESS;
}

