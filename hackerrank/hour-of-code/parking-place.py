n,m,k=(int(i) for i in raw_input().split())
place=set([])
for i in xrange(m):
    place.add(int(raw_input()))
for i in xrange(k):
    query=int(raw_input())
    if query in place:
        print 1
    else:
        print 0
