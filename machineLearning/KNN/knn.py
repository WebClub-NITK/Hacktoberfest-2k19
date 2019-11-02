"""
A knn classifier predicts which class a point p should belong to. To do this we loop through
all the points and find the distance of p from each point. We then sort these
indices ie., we get an array with the sorted indices(find_nearest_neighbours).
We then select the first k of these indices and find to which class do majority 
of the k points lie using the majority votes function. knn_predict returns this
class

""" 
import numpy as np
import math
import operator
def distance(p1,p2):
    distance = 0
    length = p1.shape[0]
    for x in range(length):
        distance += np.square(p1[x] - p2[x])
    return np.sqrt(distance)  


def majority_votes(votes):
    """
    Votes is a list.
    Returns the vote (in votes) with maximum counts and a random maximum in case of a tie.
    Constructs the count of votes as a dictionary with keys as the votes and 
    values as the counts of the votes. You may use library functions like mode in scipy.stats.mstats or write your own code.
    """
    votes2 = {}
    for x in range(len(votes)):
        votes2[x] = votes[x]
    sortvotes = sorted(votes2.items(), key=operator.itemgetter(1), reverse=True)
    return(sortvotes[0][0])

def find_nearest_neighbours(p, points, k=5):
    """)
    Find k nearest neighbours of p and return their indices
    p : Point to classify
    points : List of predictors
    """
    #Finding nearest neighbours- pseudocode
    #loop over all the points
    #   find the distance between p and every other point
    # sort the distances and return thek nearest points

    distances = {}
    sort = {}
    length = p.shape[0] 
    for x in range(len(points)):
        dist = distance(p, points[x])
        distances[x] = dist
    sortdist = sorted(distances.items(), key=operator.itemgetter(1))
    neighbors = []
    for x in range(k):
        neighbors.append(sortdist[x][0])
    return neighbors    

#classes to which the k points belong is given by outcomes
def knn_predict(p, points, outcomes, k=5):
    """
        Use find_nearest_neighbors and majority_votes to predict the class to which the class p belongs
        p : Point to classify
        points : List of predictors
        outcomes : List Containing the possible outcomes/targets.
    """
    Votes = {}
    temp = len(np.unique(outcomes))
    for i in range(temp):
        Votes[i]=0
    neighbors = find_nearest_neighbours(p,points)
    for x in range(len(neighbors)):
        response = outcomes[neighbors[x]]#label end
        if response in Votes:
            Votes[np.int(response)] += 1
        else:
            Votes[np.int(response)] = 1
    Vote = list(Votes.values())
    sortvotes = majority_votes(Vote)
    return sortvotes





### kNN on the iris dataset ###

## Load the IRIS dataset.
from sklearn import datasets
iris = datasets.load_iris()

predictors = iris.data
outcomes = iris.target

## Using sklearn's KNN Classifier ##

from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors = 5)
knn.fit(predictors, outcomes)
sk_predictions = knn.predict(predictors)


## Using the classifier we built
my_predictions = np.array([knn_predict(p, predictors, outcomes, k=5) for p in predictors])


# Test and compare our model

print(np.mean(my_predictions == sk_predictions))

print(np.mean(my_predictions == outcomes))

print(np.mean(sk_predictions == outcomes))

























    