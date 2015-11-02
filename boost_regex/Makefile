main: main.o
	g++ -o $@ $< -Wl,-rpath,$(CONDA_ENV_PATH)/lib -L$(CONDA_ENV_PATH)/lib -lboost_regex

main.o: main.cxx
	g++ -c -I$(CONDA_ENV_PATH)/include $<

clean:
	rm -f main.o main
