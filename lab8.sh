#!/bin/bash
make; 
echo "----------FIFO----------"
cat testInput.txt | ./lab8fifo 10 
echo "----------End FIFO----------"
echo
echo "----------LRU----------"
cat testInput.txt | ./lab8lru 10 
echo "----------End LRU----------"
echo
echo "----------Second Chance----------"
cat testInput.txt | ./lab8second 10 
echo "----------End Second Chance----------"
echo "FIFO 10K Test with cache size = 10, 50, 100, 250, 500"
cat testInput10k.txt | ./lab8fifo 10 
cat testInput10k.txt | ./lab8fifo 50 
cat testInput10k.txt | ./lab8fifo 100 
cat testInput10k.txt | ./lab8fifo 250
cat testInput10k.txt | ./lab8fifo 500 
echo
echo "LRU 10K Test with cache size = 10, 50, 100, 250, 500"
cat testInput10k.txt | ./lab8lru 10 
cat testInput10k.txt | ./lab8lru 50 
cat testInput10k.txt | ./lab8lru 100
cat testInput10k.txt | ./lab8lru 250 
cat testInput10k.txt | ./lab8lru 500 
echo
echo "Second Chance 10K Test with cache size = 10, 50, 100, 250, 500"
cat testInput10k.txt | ./lab8second 10
cat testInput10k.txt | ./lab8second 50 
cat testInput10k.txt | ./lab8second 100 
cat testInput10k.txt | ./lab8second 250 
cat testInput10k.txt | ./lab8second 500 
echo
make clean;
echo