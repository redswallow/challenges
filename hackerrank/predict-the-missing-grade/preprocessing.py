#!/usr/bin/env python
import numpy as np
from scipy.stats import nanmean

def fill_missing_values(X):
    """ imputing missing values before building a learner """
    mean=nanmean(X,axis=0)
    for rows in xrange(len(X)):
        for cols in xrange(len(X[rows])):
            if np.isnan(X[rows][cols]):
                X[rows][cols]=mean[cols]
    return X
