rm -f times.txt

for n in 10 20 30 40 50 60 70 80 90 100
do
    echo $n
    ./main $n >> times.txt
done

python plot.py
