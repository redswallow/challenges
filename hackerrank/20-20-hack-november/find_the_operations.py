#!/usr/bin/python
from numpy import *

def ToReducedRowEchelonForm( M):
    if not M: return
    lead = 0
    rowCount = len(M)
    columnCount = len(M[0])
    for r in range(rowCount):
        if lead >= columnCount:
            return
        i = r
        while M[i][lead] == 0:
            i += 1
            if i == rowCount:
                i = r
                lead += 1
                if columnCount == lead:
                    return
        M[i],M[r] = M[r],M[i]
        lv = M[r][lead]
        M[r] = [ mrx / lv for mrx in M[r]]
        for i in range(rowCount):
            if i != r:
                lv = M[i][lead]
                M[i] = [ iv - lv*rv for rv,iv in zip(M[r],M[i])]
        lead += 1

def get_filplist(n,d):
    filplist=[]
    for i in xrange(n):
        for j in xrange(n):
            temp=[0]*(n*n);temp[i*n+j]=1
            for k in xrange(1,d+1):
                if i+k<n: temp[i*n+k*n+j]=1
                if i-k>=0: temp[i*n-k*n+j]=1
                if j+k<n: temp[i*n+j+k]=1
                if j-k>=0: temp[i*n+j-k]=1
            filplist.append(temp)
    return filplist


n,d=[int(num) for num in raw_input().split()]
a=get_filplist(n,d)
b=[]
#for i in xrange(n):
#    b.extend([int(num) for num in raw_input().split()])
b=[1,0,1,1,1,0,0,0,0]
for i in xrange(len(b)):
    a[i].append(b[i])
s=[];step=[]

lead = 0
rowCount = len(a);columnCount = len(a[0])
for r in range(rowCount):
    if lead >= columnCount:
        break
    i = r
    while a[i][lead] == 0:
        i += 1
        if i == rowCount:
            i = r
            lead += 1
            if columnCount == lead:
                break
    a[i],a[r] = a[r],a[i]
    lv = a[r][lead]
    a[r] = [ mrx / lv for mrx in a[r]]
    for i in range(rowCount):
        if i != r:
            lv = a[i][lead]
            a[i] = [ iv - lv*rv for rv,iv in zip(a[r],a[i])]
    lead += 1

for i in xrange(n*n):
    temp=0
    for j in xrange(n*n+1):
        if i!=j and a[i][j]!=0:
                temp=temp+1
    if not temp:
        step.append([i/n,i%n])
if not step:
    print "Impossible"
else:
    print "Possible"
    print len(step)
    for i in xrange(len(step)):
        x,y=step[i]
        print "%d %d"%(x,y)
