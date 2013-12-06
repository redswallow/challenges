#!/usr/bin/python
t=int(raw_input())
for ti in xrange(t):
    sentence=raw_input()
    sentence=sentence.split(",?.")
    print sentence
    """
    if sentence[0:3]=="???":
        sentence=sentence.replace("???","It's",1)
    print sentence.replace("???", "its")
    """
