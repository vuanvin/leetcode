columns=$(cat file.txt | head -n 1 | wc -w)
for line in $(seq 1 $columns)  # (1 2 ... col)
do
    awk -v line=$line '{print $line}' file.txt | xargs
done