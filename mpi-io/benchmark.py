import argparse
import os
import subprocess

mpirun_cmd = {
    'default': 'mpirun -n {nproc} {cmd}',
}

def parse_command_line():
    parser = argparse.ArgumentParser()

    parser.add_argument('-c', '--check-result', action='store_true',
                        help='Check read results (performance penality)')
    parser.add_argument('-d', '--data-size', type=int, default=10000,
                        help='Array to write size')
    parser.add_argument('-n', '--nproc-list', default='1,2,4,8',
                        help='Comma separated list of number of processus')

    action = parser.add_mutually_exclusive_group(required=True)
    action.add_argument('-w', '--writing-benchmark', action='store_true',
                        help='Run write benchamrk')
    action.add_argument('-r', '--reading-benchmark', action='store_true',
                        help='Run read benchamrk')
    action.add_argument('-p', '--plot', action='store_true',
                        help='Plot reading and writting benchmark results')

    args = parser.parse_args()
    args.nproc_list = [int(nproc) for nproc in args.nproc_list.split(',')]
    return args

def run(cmd, *, nproc=4, profile='default', output='output-{nproc}.txt'):
    """Run cmd in parallel and write stdout to file"""
    full_cmd = mpirun_cmd[profile].format(nproc=nproc, cmd=cmd)
    print(full_cmd)
    args = full_cmd.split()
    result = subprocess.run(args, stdout=subprocess.PIPE,
                            universal_newlines=True)
    filename = output.format(nproc=nproc)
    with open(filename, 'w') as f:
        f.write(result.stdout)
    print(filename)

def plot(nproc_list):
    import matplotlib
    matplotlib.use('Agg')
    import matplotlib.pyplot as plt
    import pandas as pd

    for prog in ['read', 'write']:
        figure, axes = plt.subplots(len(nproc_list), 1, sharex='col')
        axes = axes.flatten()

        for i,size in enumerate(nproc_list):
            times  = pd.read_table('times-{}-{}.txt'.format(prog, size), sep=' ',
                                    names=[prog])
                                    #names=['read', 'compute', 'write', ])
            times.plot.barh(stacked=True, ax=axes[i],
                            title='{} process'.format(size),
                            legend=True if i==0 else False)
            plt.sca(axes[i])
            plt.ylabel('Process rank')

        plt.xlabel('Wall-clock time')

        filename = 'times-{}.png'.format(prog)
        plt.savefig(filename)
        print(filename)

def main():
    os.makedirs('out', exist_ok=True)

    args = parse_command_line()

    if args.writing_benchmark:
        if not os.path.isfile('write'):
            raise OSError("Run: 'make' first")
        cmd = './write {data_size}'.format(data_size=args.data_size)
        output = 'times-write-{nproc}.txt'
        for nproc in args.nproc_list:
            run(cmd, nproc=nproc, output=output)

    elif args.reading_benchmark:
        if not os.path.isfile('read'):
            raise OSError("Run: 'make' first")
        if args.check_result:
            cmd = './read {data_size} 1'.format(data_size=args.data_size)
        else:
            cmd = './read {data_size} 0'.format(data_size=args.data_size)
        output = 'times-read-{nproc}.txt'
        for nproc in args.nproc_list:
            run(cmd, nproc=nproc, output=output)

    elif args.plot:
        plot(args.nproc_list)

if __name__ == '__main__':
    main()
