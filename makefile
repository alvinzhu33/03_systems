compile: devise.c
	gcc devise.c

run: compile
	./a.out

clean:
	rm *.o
	rm *~
	rm *.txt
