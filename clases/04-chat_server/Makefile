all:
	 gcc -c chat-server.c
	 gcc -c main.c
	 gcc -o main chat-server.o main.o

test_chat-server: clean
	 gcc -c chat-server.c
	 gcc -c test_chat-server.c
	 gcc -o test_chat-server.exe chat-server.o test_chat-server.o
	 ./test_chat-server.exe

test:	 test_chat-server

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c chat-server.c
	 gcc -c main.c
	 gcc -o main.exe chat-server.o main.o
	 ./main
