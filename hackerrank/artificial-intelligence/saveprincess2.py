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
            return path
        for direction in moves.keys():
            x,y=[x+y for x,y in zip(node,moves[direction])]
            if (x>=0 and x<n and y>=0 and y<n and not (x,y) in visited):
                visited.add((x,y))
                queue.append(((x,y),path+[direction]))

def nextMove(n,r,c,grid):
    start=r,c
    for i in xrange(n):
        for j in xrange(n):
            if grid[i][j]=='p':end=i,j
    path=bfs(n,grid,start,end)
    return path[0]
# Tail starts here
n = input()
r,c = [int(i) for i in raw_input().strip().split()]
grid = []
for i in xrange(0, n):
    grid.append(raw_input())

print nextMove(n,r,c,grid)
