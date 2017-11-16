all:
	 gcc -c fizzbuzz.c
	 gcc -c main.c
	 gcc -o main fizzbuzz.o main.o

test_fizzbuzz: clean
	 gcc -c fizzbuzz.c
	 gcc -c test_fizzbuzz.c
	 gcc -o test_fizzbuzz.exe fizzbuzz.o test_fizzbuzz.o
	 ./test_fizzbuzz.exe

test:	 test_fizzbuzz

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c fizzbuzz.c
	 gcc -c main.c
	 gcc -o main.exe fizzbuzz.o main.o
	 ./main
