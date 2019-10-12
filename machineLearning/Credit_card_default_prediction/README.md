

### Description

Your task is to predict the probability that a credit card owner will default based on his/her characteristics and payment history. This is a **classification** problem.

The dataset can be found [here](https://archive.ics.uci.edu/ml/datasets/default+of+credit+card+clients).
There is a starter IPython notebook in the folder associated with this issue. It contains the train-test split for the dataset.

The features convey the following information:
	**X1**: Amount of the given credit (New Taiwan dollar): it includes both the individual consumer credit and his/her family (supplementary) credit.
	**X2**: Gender (1 = male; 2 = female).
	**X3**: Education (1 = graduate school; 2 = university; 3 = high school; 4 = others).
	**X4**: Marital status (1 = married; 2 = single; 3 = others).
	**X5**: Age (year).
	**X6 - X11**: History of past payment (from April to September, 2005) 
 <sub>Where 
 X6 = the repayment status in September, 2005; 
 X7 = the repayment status in August, 2005; 
 ... 
 X11 = the repayment status in April, 2005.</i></sub>
  
<sub>And the measurement scale for the repayment status is: 
-1 = pay duly; 
1 = payment delay for one month; 
2 = payment delay for two months; 
... 
8 = payment delay for eight months; 
9 = payment delay for nine months and above.</sub>
	
**X12-X17**: Amount of bill statement (New Taiwan dollar). 
<sub> Where 
X12 = amount of bill statement in September, 2005;
X13 = amount of bill statement in August, 2005; 
...
X17 = amount of bill statement in April, 2005. </sub>

**X18-X23**: Amount of previous payment (New Taiwan dollar). 
<sub> Where 
X18 = amount paid in September, 2005; 
X19 = amount paid in August, 2005; . . .
  . . . X23 = amount paid in April, 2005. </sub>

---

### Details
- Technical Specifications: pandas, python, sci-kit, numpy
- Type of issue: Multiple
- Time Limit: 
  - Plots must be implemented within **24 hours** of being taken up.
  - Algorithms must be implemented within **2 days** of being taken up.
  - Cross-validations/ensembles must be implemented within **3 days** of being taken up.
  
---

### Issue requirements / progress
All algorithms and ensembles must be scores using *RMSE*, *Logloss* and *Accuracy* metrics. Each pull request must only fulfill one of the tasks below.

#### Plots:
- [ ] Scatterplot (X12-X17 vs X12-X17) 
- [ ] Heatmap
- [ ] lmplot 

#### Algorithms:
- [ ] Support vector classifier
- [ ] Logistic regression
- [ ] K-nearest neighbors
- [ ] Gaussian Naive Bayes
- [ ] Random forest classifier
- [ ] XGBoost Classifier
- [ ] LightGBM Classifier
- [ ] Multi-layer Perceptron Classifier
- [ ] Decision Trees Classifier

#### Cross-validations/Ensembles:
- [ ] 10-fold cross-validation of XGBoost
- [ ] 10-fold cross-validation of LightGBM
- [ ] Average (non-weighted) the predictions of a 10-fold cross-validation of XGBoost and LightGBM (both must be implemented in the fold)


---

### Resources
List of resources that might be required / helpful.
Here are a few resources that may help you:
1. NumPy documentation: https://docs.scipy.org/doc/numpy-1.13.0/reference/index.html
2. Scikit-learn documentation: https://scikit-learn.org/stable/documentation.html
3. Pandas documentation: https://pandas.pydata.org/pandas-docs/stable/
4. Jupyter Notebook installation and tutorial :	https://www.dataquest.io/blog/jupyter-notebook-tutorial/
5. XGBoost documentation: https://xgboost.readthedocs.io/en/latest/
6. LightGBM documentation: https://lightgbm.readthedocs.io/en/latest/
7. Scikit-learn documentation
	- Logistic regression: https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LogisticRegression.html
	- Support vector classifier: https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html
	- K-nearest neighbors: https://scikit-learn.org/stable/modules/generated/sklearn.neighbors.KNeighborsClassifier.html
    - Gaussian Naive Bayes: https://scikit-learn.org/stable/modules/generated/sklearn.naive_bayes.GaussianNB.html
	- Random forest classifier : https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestClassifier.html
	- Multi-layer perceptron classifier: https://scikit-learn.org/stable/modules/generated/sklearn.neural_network.MLPClassifier.html#sklearn.neural_network.MLPClassifier
	- Decision tree classifier: https://scikit-learn.org/stable/modules/generated/sklearn.tree.DecisionTreeClassifier.html
8.	Seaborn documentation
	a. Scatter-plot: https://seaborn.pydata.org/generated/seaborn.scatterplot.html
	b. Heat-map: http://seaborn.pydata.org/generated/seaborn.heatmap.html
	c. lmplot: https://seaborn.pydata.org/generated/seaborn.lmplot.html

---

### Directory Structure
The following convention must be adhered to when placing your solution files.
#### Plots:
- For Scatter-plot
`/machineLearning/credit_default/plots/sp/<solution_file>`
- For Heatmap
`/machineLearning/credit_default/plots/hm/<solution_file>`
- For lmplot
`/machineLearning/credit_default/plots/lp/<solution_file>`

#### Algorithms:
-   For Support Vector Classifier:  
    `/machineLearning/credit_default/algo/svc/<solution_file>`
-   For Logistic Regression:  
    `/machineLearning/credit_default/algo/lr/<solution_file>`
-	For K-Nearest Neighbors: 
	`/machineLearning/credit_default/algo/knn/<solution_file>`
-	For Gaussian Naive Bayes:
	`/machineLearning/credit_default/algo/gnb/<solution_file>`
-	For Decision Trees Classifier:
	`/machineLearning/credit_default/algo/dtc/<solution_file>`
-	For Random Forest Classifier:
	`/machineLearning/credit_default/algo/rfc/<solution_file>`
- 	For Multi-layer Perceptron Classifier:
	`/machineLearning/credit_default/algo/mlp/<solution_file>`
-	For XGBoost:
	`/machineLearning/credit_default/algo/xgb/<solution_file>`
-	For LightGBM:
	`/machineLearning/credit_default/algo/lgbm/<solution_file>`

#### Ensembles:
-   For 10-fold XGBoost:  
    `/machineLearning/credit_default/ens/10-xgb/<solution_file>`
- 	For 10-fold LightGBM:
	`/machineLearning/credit_default/ens/10-lgbm/<solution_file>`
- 	For average(non-weighted) of predictions of 10-fold XGBoost and 10-fold LightGBM
	`/machineLearning/credit_default/ens/avg/<solution_file>`

#### Note
Please claim the issue first by commenting here before starting to work on it. Feel free to contact @amukh18 or @CinnamonRolls1 with any issues at any time.


