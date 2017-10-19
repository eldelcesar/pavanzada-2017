all:
	 gcc -c frequent-elements.c
	 gcc -c main.c
	 gcc -o main frequent-elements.o main.o

test_frequent-elements: clean
	 gcc -c frequent-elements.c
	 gcc -c test_frequent-elements.c
	 gcc -o test_frequent-elements.exe frequent-elements.o test_frequent-elements.o
	 ./test_frequent-elements.exe

test:	 test_frequent-elements

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c frequent-elements.c
	 gcc -c main.c
	 gcc -o main.exe frequent-elements.o main.o
	 ./main
