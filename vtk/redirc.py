import os
import sys
import tempfile

STDOUT = 1
STDERR = 2

class Redirector(object):
    def __init__(self, fd=STDOUT):
        self.fd = fd
        self.started = False

    def start(self):
        if not self.started:
            self.tmpfd, self.tmpfn = tempfile.mkstemp()

            self.oldhandle = os.dup(self.fd)
            os.dup2(self.tmpfd, self.fd)
            os.close(self.tmpfd)

            self.started = True

    def flush(self):
        if self.fd == STDOUT:
            sys.stdout.flush()
        elif self.fd == STDERR:
            sys.stderr.flush()

    def stop(self):
        if self.started:
            self.flush()
            os.dup2(self.oldhandle, self.fd)
            os.close(self.oldhandle)
            tmpr = open(self.tmpfn, 'rb')
            output = tmpr.read()
            tmpr.close()  # this also closes self.tmpfd
            os.unlink(self.tmpfn)

            self.started = False
            return output
        else:
            return None

def print_stdout_stderr(func):
    def decorated(*args, **kwargs):
        stdout_redirc = Redirector(fd=STDOUT)
        stderr_redirc = Redirector(fd=STDERR)

        stdout_redirc.start()
        stderr_redirc.start()

        return_values = func(*args, **kwargs)

        stdout = stdout_redirc.stop()
        stderr = stderr_redirc.stop()

        if stdout:
            print ' stdout '.center(50,'-')
            print stdout
            print '-'*50
            print

        if stderr:
            print ' stderr '.center(50,'-')
            print stderr
            print '-'*50

        return return_values
    return decorated
