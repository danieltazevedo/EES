
RAPL=../RAPL

factorial : factorial.c ../RAPL/rapl.c
	gcc -O2 $(RAPL)/rapl.c factorial.c -o factorial -I$(RAPL) -lm 

clean:
	rm -rf *.o factorial
