# Check PREFIX is correctly set.
ifneq ($(wildcard $(PREFIX)),)
    $(info "INFO: Install directory is: $(PREFIX)")
else
    $(error "WARNING: Install directory (PREFIX='$(PREFIX)') doest not exits. Use: make PREFIX=/path/to/install/prefix")
endif

EXE = helloscript hellostatic hellodynamic

all: $(EXE)

# ============================================================================
# Replace PREFIX with actual value
# ============================================================================
#
WITH_PREFIX = helloscript greetstatic.c greetdynamic.c

helloscript: helloscript.in
	sed s:PREFIX:${PREFIX}: $< > $@
	chmod +x helloscript

greetstatic.c: greetstatic.c.in
	sed s:PREFIX:${PREFIX}: $< > $@

greetdynamic.c: greetdynamic.c.in
	sed s:PREFIX:${PREFIX}: $< > $@

# ============================================================================
# Link with static library
# ============================================================================

greetstatic.o: greetstatic.c
	$(CC) -I. -c $<

hellostatic.o: hellostatic.c
	$(CC) -I. -c $<

libgreetstatic.a: greetstatic.o
	ar rcs $@ $<

hellostatic: hellostatic.o libgreetstatic.a
	$(CC) -o $@ hellostatic.o -L. -lgreetstatic

# ============================================================================
# Link with dynamic library
# ============================================================================

greetdynamic.o: greetdynamic.c
	$(CC) -I. -fPIC -c $<

hellodynamic.o: hellodynamic.c
	$(CC) -I. -fPIC -c $<

libgreetdynamic.so: greetdynamic.o
	$(CC) -shared -o $@ -Wl,-soname,$(PREFIX)/lib/libgreetdynamic.so $<

hellodynamic: hellodynamic.o libgreetdynamic.so
	$(CC) -o $@ hellodynamic.o -L. -lgreetdynamic

# ============================================================================
# Clean, install
# ============================================================================

clean:
	rm -f *.o *.a *.so $(WITH_PREFIX) $(EXE)

install: all
	mkdir -p $(PREFIX)/bin $(PREFIX)/lib
	cp helloscript hellostatic hellodynamic $(PREFIX)/bin
	cp libgreetdynamic.so $(PREFIX)/lib
