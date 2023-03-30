INPUTSIZE=1
NTIMES=10
export INPUTSIZE
export NTIMES

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
	./counting_sort $(INPUTSIZE)
	./insertion_sort $(INPUTSIZE)
	./quick_sort $(INPUTSIZE)

measure: 
	sudo ../RAPL/main "./C/c_counting_sort $(INPUTSIZE)" $(NTIMES) C_counting_sort
	sudo ../RAPL/main "./C/c_insertion_sort $(INPUTSIZE)" $(NTIMES) C_insertion_sort
	sudo ../RAPL/main "./C/c_quick_sort $(INPUTSIZE)" $(NTIMES) c_quick_sort
	
	sudo ../RAPL/main "./C++/CountingSort $(INPUTSIZE)" $(NTIMES) C++_counting_sort
	sudo ../RAPL/main "./C++/InsertionSort $(INPUTSIZE)" $(NTIMES) C++_insertion_sort
	sudo ../RAPL/main "./C++/QuickSort $(INPUTSIZE)" $(NTIMES) C++_quick_sort
	
	sudo ../RAPL/main "python3 Python/counting_sort.py $(INPUTSIZE)" $(NTIMES) Python_counting_sort
	sudo ../RAPL/main "python3 Python/insertion_sort.py $(INPUTSIZE)" $(NTIMES) Python_insertion_sort
	sudo ../RAPL/main "python3 Python/quick_sort.py $(INPUTSIZE)" $(NTIMES)	Python_quick_sort
	
	sudo ../RAPL/main "node JavaScript/CountingSort.js $(INPUTSIZE)" $(NTIMES) JavaScript_counting_sort
	sudo ../RAPL/main "node JavaScript/InsertionSort.js $(INPUTSIZE)" $(NTIMES) JavaScript_insertion_sort
	sudo ../RAPL/main "node JavaScript/QuickSort.js $(INPUTSIZE)" $(NTIMES) JavaScript_quick_sort
	
	sudo ../RAPL/main "php PHP/CountingSort.php $(INPUTSIZE)" $(NTIMES) PHP_counting_sort
	sudo ../RAPL/main "php PHP/InsertionSort.php $(INPUTSIZE)" $(NTIMES) PHP_insertion_sort
	sudo ../RAPL/main "php PHP/QuickSort.php $(INPUTSIZE)" $(NTIMES) PHP_quick_sort
	
	sudo ../RAPL/main "java -cp Java CountingSort $(INPUTSIZE)" $(NTIMES) Java_counting_sort
	sudo ../RAPL/main "java -cp Java InsertionSort $(INPUTSIZE)" $(NTIMES) Java_insertion_sort
	sudo ../RAPL/main "java -cp Java QuickSort $(INPUTSIZE)" $(NTIMES) Java_quick_sort
	
	

clean:
	rm -rf counting_sort insertion_sort quick_sort *.o
	
	
