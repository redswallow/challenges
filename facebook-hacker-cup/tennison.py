#!/usr/bin/python

fin=open('tennison.txt')
fout=open('tennison.out','wb')
t=int(fin.readline())
for ti in xrange(t):
    k,ps,pr,pi,pu,pw,pd,pl=[float(data) for data in fin.readline().split()]
    for i in xrange(k):
        
    print k,ps,pr,pi,pu,pw,pd,pl
