#!/bin/bash
make; 
echo "----------FIFO----------"
cat accesses.txt | ./lab8fifo 50 
echo
echo "----------End FIFO----------"
echo
echo "----------LRU----------"
cat accesses.txt | ./lab8lru 50 
echo
echo "----------End LRU----------"
echo
echo "----------Second Chance----------"
cat accesses.txt | ./lab8second 50 
echo
echo "----------End Second Chance----------"
echo
make clean;
echo