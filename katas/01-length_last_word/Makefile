all:
	 gcc -c length-word.c
	 gcc -c main.c
	 gcc -o main length-word.o main.o

test_length-word: clean
	 gcc -c length-word.c
	 gcc -c test_length-word.c
	 gcc -o test_length-word.exe length-word.o test_length-word.o
	 ./test_length-word.exe

test:	 test_length-word

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c length-word.c
	 gcc -c main.c
	 gcc -o main.exe length-word.o main.o
	 ./main
