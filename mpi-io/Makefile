CC = mpicc
EXE = write read

all: $(EXE)

FLAGS = -O3 -Wall -Wextra

%.o: %.c tool.h
	$(CC) -c $(FLAGS) $<

read: read.o tool.o
	$(CC) -o $@ $(FLAGS) $^

write: write.o tool.o
	$(CC) -o $@ $(FLAGS) $^

clean:
	rm -rf *.o $(EXE) data.bin times*.txt times*.png
