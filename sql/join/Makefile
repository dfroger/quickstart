all: clean create join

create:
	sqlite3 demo.db < create.sql

join:
	sqlite3 demo.db < join.sql

clean:
	rm -f demo.db
