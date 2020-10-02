#! /usr/bin/python3

# 解説PDFにて

n = int(input())
sum = 0
for a in range(1, n):
    sum += (n-1) // a
print(sum)
