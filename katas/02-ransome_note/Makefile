all:
	 gcc -c ransome-note.c
	 gcc -c main.c
	 gcc -o main ransome-note.o main.o

test_ransome-note: clean
	 gcc -c ransome-note.c
	 gcc -c test_ransome-note.c
	 gcc -o test_ransome-note.exe ransome-note.o test_ransome-note.o
	 ./test_ransome-note.exe

test:	 test_ransome-note

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c ransome-note.c
	 gcc -c main.c
	 gcc -o main.exe ransome-note.o main.o
	 ./main
