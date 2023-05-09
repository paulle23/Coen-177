#all: lab8fifo.c lab8lru.c lab8second.c
#	gcc -o lab8lru lab8lru.c
#	gcc -o lab8fifo lab8fifo.c
#	gcc -o lab8second lab8second.c
#clean:; rm -f *.out lab8lru lab8fifo lab8second

all: lab9.c lab9_1.c lab9_2.c lab9_3.c
	gcc -o step2 lab9.c
	gcc -o step3 lab9_1.c
	gcc -o step4 lab9_2.c
	gcc -o step5 lab9_3.c -lpthread
clean:;rm -f *.out step2 step3 step4 step5