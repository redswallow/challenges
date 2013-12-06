#!/usr/bin/python

r,c=[int(num) for num in raw_input().split()]
m=[]
n=0
dist={}
mat={}
visited=set([])
visited_d=0
s=0

for ri in xrange(r):
    mline=[int(num)for num in raw_input().split()]
    for ci in xrange(c):
        if mline[ci]==1:
            dist[n]=[ri,ci]
            n=n+1
for i in xrange(0,n-1):
    for j in xrange(i+1,n):
        d=max(abs(dist[j][0]-dist[i][0]),abs(dist[j][1]-dist[i][1]))
        mat[i*n+j]=d

sorted(mat.items(), lambda x, y: cmp(x[1], y[1]), reverse=True)

keys=list(mat)
key=keys[0]
x,y=key/c,key%c
visited.add(x);visited.add(y)
visited_d=mat[key]
s=s+visited_d;
while len(visited)!=n:
    for key in keys[1:]:
        x,y=key/c,key%c
        if x not in visited or y not in visited:
            visited.add(x);visited.add(y)
            visited_d=max(mat[key],visited_d)
            s=s+visited_d;

print s
