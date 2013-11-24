#!/usr/bin/python

m=1000000007 #modulo

def mod(a,m):
    x=0
    for i in xrange(len(a)):
        x=(x*10+int(a[i]))%m
    return x

def compute_power(a, p, m):
  result = 1
  p_bin = bin(p)[2:]
  length = len(p_bin)
  for i in range(0, length):
    result = result**2 % m
    if p_bin[i] == '1':
      result = result * a % m
  return result

t=int(raw_input())
for ti in xrange(t):
    a,b=[n for n in raw_input().split()]
    ra=mod(a,m) 
    #rb=mod(b,m)
    print compute_power(ra,int(b),m)

