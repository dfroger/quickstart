ext:
	python setup.py build_ext --inplace

.PHONY: test

test:
	PYTHONPATH=. python test/foo/test_foo.py

cover:
	PYTHONPATH=. nosetests --with-coverage --cover-package=demo

clean:
	rm -rf build/ demo/foo/foo.c demo/foo/*.so

