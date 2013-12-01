#!/usr/bin/python

def gameplay(team):
    #init game
    game=[];bench=[];
    for i in xrange(p):team[i][4]=1;game.append(team[i])
    bench=[player for player in team if player[4]==0]
    if bench==[]: return game
    for i in xrange(m):
        game.sort(key=lambda x:(x[4],x[3]))
        bench.sort(key=lambda x:(x[4],x[3]),reverse=True)
        o=game.pop();i=bench.pop()
        game.append(i);bench.append(o)
        for i in xrange(p):game[i][4]+=1
    return game

fin=open('basketball_game.txt')
fout=open('basketball_game.out','wb')
t=int(fin.readline())
for ti in xrange(t):
    n,m,p=[int(data) for data in fin.readline().split()]
    players=[]
    for i in xrange(n):
        name,short_percentage,height=[data for data in fin.readline().split()]
        short_percentage=int(short_percentage);height=int(height)
        players.append([name,short_percentage,height,0,0]);
    players.sort(key=lambda x:(x[1],x[2]),reverse=True)
    for i in xrange(len(players)):
        players[i][3]=i+1
    game_players=[];
    game_players.extend(gameplay(players[1::2]));
    game_players.extend(gameplay(players[::2]));
    game_players.sort(key=lambda x:x[0])

    fout.write("Case #%d: "%(ti+1))
    for player in game_players: fout.write("%s "%player[0])
    fout.write('\n')
