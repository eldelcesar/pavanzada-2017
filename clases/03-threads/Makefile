all:
	 gcc -c threads.c
	 gcc -c main.c
	 gcc -o main threads.o main.o

test_threads: clean
	 gcc -c threads.c
	 gcc -c test_threads.c
	 gcc -o test_threads.exe threads.o test_threads.o
	 ./test_threads.exe

test:	 test_threads

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c threads.c
	 gcc -c main.c
	 gcc -o main.exe threads.o main.o
	 ./main
