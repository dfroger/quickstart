all: clean create groupby

create:
	sqlite3 demo.db < create.sql

groupby:
	sqlite3 demo.db < groupby.sql

clean:
	rm -f demo.db
