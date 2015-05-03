# sudo apt-get install libgdb-dev for lib iberty
EXE = main
SRC = main.cxx
CXX = mpicxx

CONDADIR = /local/froger/miniconda/envs/mpip
LIBDIR = $(CONDADIR)/lib
MPIP_LDFLAGS = -L$(LIBDIR) -Wl,-rpath,$(LIBDIR) -lmpiP -lm -lbfd -liberty -lunwind -ldwarf -lelf

$(EXE): $(SRC)
	$(CXX) -o $@ -g $< $(MPIP_LDFLAGS)

run: $(EXE)
	MPIP="-t 10.0" mpirun -n 4 ./$(EXE)

clean:
	rm -f $(EXE) *.mpiP
