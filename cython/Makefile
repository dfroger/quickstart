ext:
	python setup.py build_ext --inplace

.PHONY: test

test:
	PYTHONPATH=. nosetests

cover:
	PYTHONPATH=. nosetests --with-coverage --cover-package=demo

clean:
	rm -rf build/ demo/foo/foo.c demo/foo/*.so

