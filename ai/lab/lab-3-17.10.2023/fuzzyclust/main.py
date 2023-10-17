import numpy as np
import matplotlib.pyplot as plt
import skfuzzy as fuzz

np.random.seed(0)
n_points = 300
X = np.zeros((n_points, 2))

X[:100, :] = np.random.normal(loc=(-5, -5), scale=1, size=(100, 2))
X[100:200, :] = np.random.normal(loc=(0, 5), scale=1, size=(100, 2))
X[200:300, :] = np.random.normal(loc=(5, -5), scale=1, size=(100, 2))

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.scatter(X[:, 0], X[:, 1], color='grey', marker='o')
plt.title("Before Clustering")

n_clusters = 3
cntr, u, u0, d, jm, p, fpc = fuzz.cluster.cmeans(
    X.T, c=n_clusters, m=2, error=0.005, maxiter=1000
)

# Find the cluster membership of each data point
cluster_membership = np.argmax(u, axis=0)

# 4. Plot the data after clustering
plt.subplot(1, 2, 2)
for i in range(n_clusters):
    plt.scatter(X[cluster_membership == i, 0], X[cluster_membership == i, 1], label=f'Cluster {i + 1}')

plt.scatter(cntr[:, 0], cntr[:, 1], s=200, c='black', marker='X', label='Centroids')
plt.title("After Fuzzy C-Means Clustering")
plt.legend()
plt.tight_layout()
plt.show()
