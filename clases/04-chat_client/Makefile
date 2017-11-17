all:
	 gcc -c chat-client.c
	 gcc -c main.c
	 gcc -o main chat-client.o main.o

test_chat-client: clean
	 gcc -c chat-client.c
	 gcc -c test_chat-client.c
	 gcc -o test_chat-client.exe chat-client.o test_chat-client.o
	 ./test_chat-client.exe

test:	 test_chat-client

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c chat-client.c
	 gcc -c main.c
	 gcc -o main.exe chat-client.o main.o
	 ./main
