CC = g++
CFLAGS = -g -Wall -std=c++11

a.out: numlist.o lab2.o
	$(CC) $(CFLAGS) numlist.o lab2.o -o a.out

numlist.o: numlist.cc numlist.h
	$(CC) $(CFLAGS) -c numlist.cc

lab2.o: lab2.cc numlist.h
	$(CC) $(CFLAGS) -c lab2.cc

clean:
	rm -rf numlist.o lab2.o a.out