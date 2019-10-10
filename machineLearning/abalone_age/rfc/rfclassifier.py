import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sklearn
from sklearn.metrics import f1_score,accuracy_score
from sklearn.ensemble import RandomForestClassifier

column_names = ["sex", "length", "diameter", "height", "whole weight", 
                "shucked weight", "viscera weight", "shell weight", "rings"]
data = pd.read_csv("abalone.data", names=column_names)
print("Number of samples: %d" % len(data))
data.head()
for label in "MFI":
    data[label] = data["sex"] == label
del data["sex"]
data.head()
y = data.rings.values
del data["rings"] # remove rings from data, so we can convert all the dataframe to a numpy 2D array.
X = data.values.astype(np.float)
from sklearn.model_selection import train_test_split 
train_X, test_X, train_y, test_y = train_test_split(X, y)
print(train_X.shape)
print(test_X.shape)
print(train_y.shape)
print(test_y.shape)
n_features = X.shape[1]
model = RandomForestClassifier(n_estimators=30)
model.fit(train_X, train_y)
predicted_test_y = model.predict(test_X)
predicted_age = predicted_test_y+1.5
actual_age = test_y+1.5
print(accuracy_score(test_y, predicted_test_y))  
print(f1_score(test_y, predicted_test_y, average='weighted'))  
