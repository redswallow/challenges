#!/usr/bin/env python
from datasets import load_data
from scipy.stats import nanmean
import numpy as np

""" get training data """
Xtr,Ytr=load_data("data/training.json")
""" remove NAN from data """
mean=nanmean(Xtr,axis=0)
for rows in xrange(len(Xtr)):
    for cols in xrange(len(Xtr[rows])):
        if np.isnan(Xtr[rows][cols]):
            Xtr[rows][cols]=mean[cols]

"""training"""
from sklearn.tree import DecisionTreeClassifier
learner = DecisionTreeClassifier(max_depth=None,random_state=0).fit(Xtr, Ytr)

"""predicting"""
Yhat=learner.predict(Xtr)
print learner.score(Xtr,Ytr)
