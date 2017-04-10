FARM     = $(PWD)/dbfarm
DB       = pvnext
PORT     = 56789
USER     = monetdb
PASSWORD = monetdb
CONFIG   = monetdb_config

MONETDB        = monetdb -p $(PORT)
MONETDB_DAEMON = monetdbd
MONETDB_CLIENT = DOTMONETDBFILE=$(CONFIG) mclient -p $(PORT)

.PHONY: help config farm db setup client clean status

help:
	@echo "Use the 3 major targets in order:"
	@echo "    make setup      setup everthing (execute targets: config, farm, db)"
	@echo "    make client     start monetdb interactive client"
	@echo "    make clean      clean everything"
	@echo
	@echo "Or one of the minor targets:"
	@echo "    make help       print this message"
	@echo "    make config     create configuration file"
	@echo "    make farm       create database farm"
	@echo "    make db         create database"
	@echo "    make status     print farm and database statuses"

setup: config farm db

config:
	echo "user=$(USER)" > $(CONFIG)
	echo "password=$(PASSWORD)" >> $(CONFIG)

farm:
	$(MONETDB_DAEMON) create           $(FARM)
	$(MONETDB_DAEMON) set port=$(PORT) $(FARM)
	$(MONETDB_DAEMON) start            $(FARM)

db:
	$(MONETDB) create $(DB)
	$(MONETDB) start  $(DB)

client:
	$(MONETDB_CLIENT) --database $(DB)

status:
	$(MONETDB_DAEMON) get all $(FARM)
	$(MONETDB) status

clean:
	$(MONETDB) stop $(DB)
	$(MONETDB) destroy $(DB)
	$(MONETDB_DAEMON) stop $(FARM)
	rm -rf $(FARM) $(CONFIG)
