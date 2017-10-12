all:
	 gcc -c island-perimeter.c
	 gcc -c main.c
	 gcc -o main island-perimeter.o main.o

test_island-perimeter: clean
	 gcc -c island-perimeter.c
	 gcc -c test_island-perimeter.c
	 gcc -o test_island-perimeter.exe island-perimeter.o test_island-perimeter.o
	 ./test_island-perimeter.exe

test:	 test_island-perimeter

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c island-perimeter.c
	 gcc -c main.c
	 gcc -o main.exe island-perimeter.o main.o
	 ./main
