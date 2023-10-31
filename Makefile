all: main.o tokenizer.o history.o
	gcc -o tokenizer main.o tokenizer.o history.o

main.o: main.c
	gcc -c main.c -I.

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c -I.

history.o: history.c history.h tokenizer.h
	gcc -c history.c -I.

tester.o: tester.c tokenizer.h history.h
	gcc -c tester.c -I.

test: tester.o tokenizer.o history.o
	gcc -o tester tester.o tokenizer.o history.o
	./tester

clean:
	rm *.o tokenizer tester

