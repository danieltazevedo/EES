INPUTSIZE=1
NTIMES=10
export INPUTSIZE
export NTIMES

compile:
	gcc -O2 C/counting_sort.c -o c_counting_sort
	gcc -O2 C/insertion_sort.c -o c_insertion_sort
	gcc -O2 C/quick_sort.c -o c_quick_sort

run:
	./counting_sort $(INPUTSIZE)
	./insertion_sort $(INPUTSIZE)
	./quick_sort $(INPUTSIZE)

measure: 
	sudo ../RAPL/main "c_counting_sort $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "c_insertion_sort $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "c_quick_sort $(INPUTSIZE)" $(NTIMES)
	
	sudo ../RAPL/main "python3 Python/counting_sort.py $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "python3 Python/insertion_sort.py $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "python3 Python/quick_sort.py $(INPUTSIZE)" $(NTIMES)
	
	sudo ../RAPL/main "node JavaScript/CountingSort.js $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "node JavaScript/InsertionSort.js $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "node JavaScript/QuickSort.js $(INPUTSIZE)" $(NTIMES)
	
	sudo ../RAPL/main "php PHP/CountingSort.php $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "php PHP/InsertionSort.php $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "php PHP/QuickSort.php $(INPUTSIZE)" $(NTIMES)
	
	

clean:
	rm -rf counting_sort insertion_sort quick_sort *.o
	
	
