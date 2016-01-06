%.o: %.c
	$(CC) -c -O3 $<

main: main.o loop0.o loop1.o util.o
	$(CC) -o $@ $^

clean:
	rm -f main *.o
