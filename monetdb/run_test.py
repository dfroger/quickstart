import os
import subprocess
import shutil

import pymonetdb
import pymonetdb.control

HERE = os.path.dirname(os.path.realpath(__file__))

farm = os.path.join(HERE, 'dbfarm')
db = 'demo'
port = 56789
user = 'monetdb'
password = 'monetdb'
passphrase = 'monetdb'
table = 'names'
hostname = 'localhost'

def mdb_daemon(*args):
    subprocess.check_call(['monetdbd', ] + list(args))

# Create database farm with remote control
mdb_daemon('create', farm)
mdb_daemon('set', 'port={}'.format(port), farm)
mdb_daemon('set', 'control=yes', farm)
mdb_daemon('set', 'passphrase={}'.format(passphrase), farm)
mdb_daemon('start', farm)
mdb_daemon('get', 'all', farm)

# Create a remote control. Databases are not manage with the 'monetdb create',
# 'monetdb start', ...  command line tools like in run_test.sh, but instead
# use the remote control.
ctl = pymonetdb.control.Control(port=port, passphrase=passphrase)

# Create a `demo` database.
ctl.create(db)
ctl.start(db)
ctl.get(db)

# Get connection cursor
connection = pymonetdb.connect(username=user, password=password,
                               hostname=hostname, database=db,
                               port=port)
cursor = connection.cursor()

# Create a table
cursor.execute("CREATE TABLE {} (id integer,name varchar(20));".format(table))

# Add rows to table
cursor.execute("INSERT INTO {} VALUES (0, 'Alice');".format(table))
cursor.execute("INSERT INTO {} VALUES (1, 'Bob');".format(table))

# Get values
cursor.execute("SELECT * FROM {};".format(table))
cursor.fetchall()

# Clean everything
cursor.close()
connection.close()
ctl.stop(db)
ctl.destroy(db)
mdb_daemon('stop', farm)
shutil.rmtree(farm)

print('run_test.py completed successfully')
