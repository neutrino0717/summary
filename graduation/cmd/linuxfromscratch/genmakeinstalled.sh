cd log && mkdir -p result

for file2 in 17*.log; do
  if [ "$file1" ]; then
    echo "comm -23 $file1       $file2"
    comm -23 <(sort $file1) <(sort $file2)
  fi
  file1=$file2
done

unset file1 
unset file2
echo "=================================="
for file2 in 17*.log; do
  if [ "$file1" ]; then
    echo "comm -13 $file1       $file2"
    comm -13 <(sort $file1) <(sort $file2) > result/${file2%%.log}.txt
  fi
  file1=$file2
done

