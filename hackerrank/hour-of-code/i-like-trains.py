h1,m1=(int(n) for n in raw_input().split())
h2,m2=(int(n) for n in raw_input().split())
m=(m1+m2)%60
h=(h1+h2+(m1+m2)/60)%24
if h<10: str_h='0'+str(h) 
else: str_h=str(h)
if m<10: str_m='0'+str(m) 
else: str_m=str(m)
print "%s %s"%(str_h,str_m)
