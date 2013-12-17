n=int(raw_input())
price=[int(p) for p in raw_input().split()]
m=int(raw_input())
price=sorted(price)
print sum(price[0:m])
