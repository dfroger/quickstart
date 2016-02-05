CFLAGS = -O3 

%.o: %.c
	$(CC) -g -c $(CFLAGS) $<

main: main.o loop0.o loop1.o util.o
	$(CC) -g -o $@ $(CFLAGS) $^

run: main
	bash run.sh
	python plot.py


clean:
	rm -f main *.o
