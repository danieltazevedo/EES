INPUTSIZE ?= 3
NTIMES ?= 2

compile:
	gcc -O2 C/counting_sort.c -o C/c_counting_sort
	gcc -O2 C/insertion_sort.c -o C/c_insertion_sort
	gcc -O2 C/quick_sort.c -o C/c_quick_sort

	g++ -O2 C++/CountingSort.cpp -o C++/CountingSort
	g++ -O2 C++/InsertionSort.cpp -o C++/InsertionSort
	g++ -O2 C++/QuickSort.cpp -o C++/QuickSort

	javac Java/CountingSort.java
	javac Java/InsertionSort.java
	javac Java/QuickSort.java


run:
	./C/c_counting_sort $(INPUTSIZE)
	./C/c_insertion_sort $(INPUTSIZE)
	./C/c_quick_sort $(INPUTSIZE)

	./C++/CountingSort $(INPUTSIZE)
	./C++/InsertionSort $(INPUTSIZE)
	./C++/QuickSort $(INPUTSIZE)

	python3 Python/counting_sort.py $(INPUTSIZE)
	python3 Python/insertion_sort.py $(INPUTSIZE)
	python3 Python/quick_sort.py $(INPUTSIZE)

	node JavaScript/CountingSort.js $(INPUTSIZE)
	node JavaScript/InsertionSort.js $(INPUTSIZE)
	node JavaScript/QuickSort.js $(INPUTSIZE)

	php PHP/CountingSort.php $(INPUTSIZE)
	php PHP/InsertionSort.php $(INPUTSIZE)
	php PHP/QuickSort.php $(INPUTSIZE)

	java -cp Java CountingSort $(INPUTSIZE)
	java -cp Java InsertionSort $(INPUTSIZE)
	java -cp Java QuickSort $(INPUTSIZE)


measure: 
	sudo ../RAPL/main "./C/c_counting_sort $(INPUTSIZE)" $(NTIMES) C counting_sort
	sudo ../RAPL/main "./C/c_insertion_sort $(INPUTSIZE)" $(NTIMES) C insertion_sort
	sudo ../RAPL/main "./C/c_quick_sort $(INPUTSIZE)" $(NTIMES) C quick_sort
	
	sudo ../RAPL/main "./C++/CountingSort $(INPUTSIZE)" $(NTIMES) C++ counting_sort
	sudo ../RAPL/main "./C++/InsertionSort $(INPUTSIZE)" $(NTIMES) C++ insertion_sort
	sudo ../RAPL/main "./C++/QuickSort $(INPUTSIZE)" $(NTIMES) C++ quick_sort
	
	sudo ../RAPL/main "python3 Python/counting_sort.py $(INPUTSIZE)" $(NTIMES) Python counting_sort
	sudo ../RAPL/main "python3 Python/insertion_sort.py $(INPUTSIZE)" $(NTIMES) Python insertion_sort
	sudo ../RAPL/main "python3 Python/quick_sort.py $(INPUTSIZE)" $(NTIMES)	Python quick_sort
	
	sudo ../RAPL/main "node JavaScript/CountingSort.js $(INPUTSIZE)" $(NTIMES) JavaScript counting_sort
	sudo ../RAPL/main "node JavaScript/InsertionSort.js $(INPUTSIZE)" $(NTIMES) JavaScript insertion_sort
	sudo ../RAPL/main "node JavaScript/QuickSort.js $(INPUTSIZE)" $(NTIMES) JavaScript quick_sort
	
	sudo ../RAPL/main "php PHP/CountingSort.php $(INPUTSIZE)" $(NTIMES) PHP counting_sort
	sudo ../RAPL/main "php PHP/InsertionSort.php $(INPUTSIZE)" $(NTIMES) PHP insertion_sort
	sudo ../RAPL/main "php PHP/QuickSort.php $(INPUTSIZE)" $(NTIMES) PHP quick_sort
	
	sudo ../RAPL/main "java -cp Java CountingSort $(INPUTSIZE)" $(NTIMES) Java counting_sort
	sudo ../RAPL/main "java -cp Java InsertionSort $(INPUTSIZE)" $(NTIMES) Java insertion_sort
	sudo ../RAPL/main "java -cp Java QuickSort $(INPUTSIZE)" $(NTIMES) Java quick_sort


clean:
	rm -rf C/c_counting_sort C/c_insertion_sort C/c_quick_sort C++/CountingSort C++/InsertionSort C++/QuickSort Java/CountingSort.class Java/InsertionSort.class Java/QuickSort.class *.J ../final.csv


	