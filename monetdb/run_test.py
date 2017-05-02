import os
import subprocess
import shutil

try:
    import pymonetdb
    import pymonetdb.control as control
except ImportError:
    import monetdb.control as control

HERE = os.path.dirname(os.path.realpath(__file__))

farm = os.path.join(HERE, 'dbfarm')
db = 'demo'
port = 56789
user = 'monetdb'
password = 'monetdb'
table = 'names'

def mdb_daemon(*args):
    subprocess.check_call(['monetdbd', ] + list(args))

# Create database farm
mdb_daemon('create', farm)
mdb_daemon('set', 'port={}'.format(port), farm)
mdb_daemon('start', farm)
mdb_daemon('get', 'all', farm)

# Stop farm
mdb_daemon('stop', farm)
shutil.rmtree(farm)


#hostname = 'localhost'
#passphrase = 'monetdb'
#unix_socket = None

#database = 'demo'

#c = control.Control(hostname=hostname, port=port, passphrase=passphrase,
                    #unix_socket=unix_socket)
#c = pymonetdb.connect(database, hostname=hostname, port=port)
