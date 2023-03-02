

Análise e Teste de Software - 2023
Universidade do Minho


-- To generate the main program that monitors energy consumption
-- of programs that receives as argument:

cd RAPL
make


-- (an executable called main is produced)

-- this program main receives as argument the program to be executed and
-- the number of times such program will be run.

-- To test the main program we can use the fib.c program.

--  First, compile programs fibI.c and fibR.c (that compute the 
-- fibonnaci number passed as argument)

cd C
make compile


-- we can now run it with a given number:

make run
make INPUTSIZE=22 run


./fib 22


 fib(22): 28657 


-- To monitor energy of the fibonnacci program (executing it one time)

--  first we need to give access to the register where energy is defined:

sudo modprobe msr


-- and now we can run the main program

sudo ./main "fib 22" 1


-- a file "fib 22.J" will be produced with the energy/execution times!
