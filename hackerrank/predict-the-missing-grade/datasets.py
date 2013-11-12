#!/usr/bin/env python
import json
import numpy as np

subjects={"English":0,"Physics":1,"Chemistry":2, "ComputerScience":3,"Biology":4,\
        "PhysicalEducation":5, "Economics":6,"Accountancy":7,"BusinessStudies":8,\
        "Mathematics":9,"serial":10}

def get_x(data):
    x=[np.nan]*9;
    for key in data.keys():
        if subjects[key]<=8:
            x[subjects[key]]=data[key]
    return x

def get_y(data):
    for key in data.keys():
        if subjects[key]==9:    #Mathematics
            y=data[key]
    return y

def load_training_data(filename):
    X=[];Y=[]
    f=open(filename,"r")
    nline=int(f.readline())
    for i in xrange(nline):
        data=json.loads(f.readline())
        X.append(get_x(data))
        Y.append(get_y(data))
    return (X,Y)

def load_test_data(xfilename,yfilename):
    X=[];Y=[]
    fx=open(xfilename,"r")
    fy=open(yfilename,"r")
    nline=int(fx.readline())
    for i in xrange(nline):
        data=json.loads(fx.readline())
        X.append(get_x(data))
        Y.append(int(fy.readline()))
    return (X,Y)

def load_input():
    X=[]
    n=int(raw_input())
    for i in xrange(n):
        data=json.loads(raw_input())
        X.append(get_x(data))
    return X
