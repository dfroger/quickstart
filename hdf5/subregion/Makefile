all: write read

write: write.cxx
	g++ -o $@ $< -lhdf5_cpp -lhdf5

read: read.cxx
	g++ -o $@ $< -lhdf5_cpp -lhdf5
