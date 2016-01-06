%.o: %.c
	$(CC) -g -c -O3 $<

main: main.o loop0.o loop1.o util.o
	$(CC) -g -o $@ $^

clean:
	rm -f main *.o
