%.o: %.cxx nbody.hxx
	g++ -c -O3 $<

profme: main.o nbody.o
	g++ -o $@ $^

clean:
	rm -f *.o profme
