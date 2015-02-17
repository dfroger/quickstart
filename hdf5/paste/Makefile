all: paste

paste: paste.cxx
	g++ -g -o $@ $< -lhdf5_cpp -lhdf5

clean:
	rm -f paste *.o
