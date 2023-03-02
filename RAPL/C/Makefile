INPUTSIZE=10
NTIMES=10
export INPUTSIZE
export NTIMES

compile:
	gcc -O2 -o fibI fibI.c
	gcc -O2 -o fibR fibR.c

run:
	./fibI $(INPUTSIZE)
	./fibR $(INPUTSIZE)

measure: 
	sudo ../RAPL/main "fibI $(INPUTSIZE)" $(NTIMES)
	sudo ../RAPL/main "fibR $(INPUTSIZE)" $(NTIMES)


mem: 
	{ /usr/bin/time -v ./fibI $(INPUTSIZE) > /dev/null; } 2>&1 | grep "Maximum resident" #| sed "s/[^0-9]\+\([0-9]\+\).*/\1/"
	{ /usr/bin/time -v ./fibR $(INPUTSIZE) > /dev/null; } 2>&1 | grep "Maximum resident" #| sed "s/[^0-9]\+\([0-9]\+\).*/\1/"

clean:
	rm -rf fibI fibR *.o