all:
	 gcc -c palindrome-pairs.c
	 gcc -c main.c
	 gcc -o main palindrome-pairs.o main.o

test_palindrome-pairs: clean
	 gcc -c palindrome-pairs.c
	 gcc -c test_palindrome-pairs.c
	 gcc -o test_palindrome-pairs.exe palindrome-pairs.o test_palindrome-pairs.o
	 ./test_palindrome-pairs.exe

test:	 test_palindrome-pairs

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c palindrome-pairs.c
	 gcc -c main.c
	 gcc -o main.exe palindrome-pairs.o main.o
	 ./main
