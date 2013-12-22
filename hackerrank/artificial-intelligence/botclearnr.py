#!/usr/bin/python

# Head ends here
def bfs(n,grid,start):
    moves={'RIGHT':(0,1),'LEFT':(0,-1),'DOWN':(1,0),'UP':(-1,0)}
    visited=set([])
    queue=[]
    queue.append((start,[]));
    while queue:
        node,path=queue.pop(0)
        if grid[node[0]][node[1]]=='d':
            return path
        for direction in moves.keys():
            x,y=[x+y for x,y in zip(node,moves[direction])]
            if (x>=0 and x<n and y>=0 and y<n and not (x,y) in visited):
                visited.add((x,y))
                queue.append(((x,y),path+[direction]))

def nextMove(posx,posy,board):
    start=posx,posy
    n=len(board)
    if board[posx][posy]=='d':
        print 'CLEAN'
    else:
        path=bfs(n,board,start)
        print path[0]

# Tail starts here
if __name__ == "__main__":
    pos = [int(i) for i in raw_input().strip().split()]
    board = [[j for j in raw_input().strip()] for i in range(5)]
    nextMove(pos[0], pos[1], board)
