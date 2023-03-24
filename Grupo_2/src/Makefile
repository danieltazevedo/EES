INPUTSIZE=1
NTIMES=10
export INPUTSIZE
export NTIMES

compile:
	gcc -O2 C/counting_sort.c -o counting_sort_c
	gcc -O2 C/insertion_sort.c -o insertion_sort_c
	gcc -O2 C/quick_sort.c -o quick_sort_c

run:
	./counting_sort $(INPUTSIZE)
	./insertion_sort $(INPUTSIZE)
	./quick_sort $(INPUTSIZE)

measure: 
	sudo ../RAPL/main "counting_sort_c $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "insertion_sort_c $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "quick_sort_c $(INPUTSIZE)" $(NTIMES)
	
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
	
	
