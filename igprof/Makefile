CXX = g++

vvvibc.res: ig-vvvi-build-and-copy.gz 
	igprof-analyse -d -v -g -r MEM_TOTAL $< > $@

ig-vvvi-build-and-copy.gz: vvvi-build-and-copy
	igprof -mp -z -o ig-vvvi-build-and-copy.gz ./vvvi-build-and-copy || echo "Note: Ignore error code"

vvvi-build-and-copy: vvvi-build-and-copy.cxx 
	$(CXX) $< -o $@ -ldl -lpthread

clean:
	rm -f vvvi-build-and-copy ig-vvvi-build-and-copy.gz \
			ig-vvvi-build.gz  ig-vvvi-copy.gz vvvibc.res

