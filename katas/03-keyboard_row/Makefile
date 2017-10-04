all:
	 gcc -c keyboard-row.c
	 gcc -c main.c
	 gcc -o main keyboard-row.o main.o

test_keyboard-row: clean
	 gcc -c keyboard-row.c
	 gcc -c test_keyboard-row.c
	 gcc -o test_keyboard-row.exe keyboard-row.o test_keyboard-row.o
	 ./test_keyboard-row.exe

test:	 test_keyboard-row

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c keyboard-row.c
	 gcc -c main.c
	 gcc -o main.exe keyboard-row.o main.o
	 ./main
