all:
	 gcc -c palindromes.c
	 gcc -c main.c
	 gcc -o main palindromes.o main.o

test_palindromes: clean
	 gcc -c palindromes.c
	 gcc -c test_palindromes.c
	 gcc -o test_palindromes.exe palindromes.o test_palindromes.o
	 ./test_palindromes.exe

test:	 test_palindromes

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c palindromes.c
	 gcc -c main.c
	 gcc -o main.exe palindromes.o main.o
	 ./main
