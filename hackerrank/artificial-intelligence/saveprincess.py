#!/bin/python
# Head ends here

def bfs(n,grid,start,end):
    moves={'RIGHT':(0,1),'LEFT':(0,-1),'DOWN':(1,0),'UP':(-1,0)}
    visited=set([])
    queue=[]
    queue.append((start,[]));
    while queue:
        node,path=queue.pop(0)
        if node==end:
            for step in path:
                print step
        for direction in moves.keys():
            x,y=[x+y for x,y in zip(node,moves[direction])]
            if (x>=0 and x<n and y>=0 and y<n and not (x,y) in visited):
                visited.add((x,y))
                queue.append(((x,y),path+[direction]))

def displayPathtoPrincess(n,grid):
    for i in xrange(n):
        for j in xrange(n):
            if grid[i][j]=='m':start=i,j
            if grid[i][j]=='p':end=i,j
    bfs(n,grid,start,end)
#print all the moves here
# Tail starts here
m = input()

grid = []
for i in xrange(0, m):
    grid.append(raw_input().strip())

displayPathtoPrincess(m,grid)
