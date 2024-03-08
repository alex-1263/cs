import time

import numpy as np
import matplotlib.pyplot as plt

from sklearn.cluster import MiniBatchKMeans, KMeans
from sklearn.metrics.pairwise import pairwise_distances_argmin
from sklearn.datasets.samples_generator import make_blobs

# Generate sample data
np.random.seed(0)
# minibatch随机抽样100例样本进行训练
batch_size = 100
centers = [[1, 1], [-1, -1], [1, -1]]
n_clusters = len(centers)
# 产生3个簇类的30000个样本数据
X, labels_true = make_blobs(n_samples=30000, centers=centers, cluster_std=0.7)

# k-means++算法
k_means = KMeans(init='k-means++', n_clusters=3, n_init=10)
t0 = time.time()
k_means.fit(X)
t_batch = time.time() - t0



# MiniBatchKMeans算法
mbk = MiniBatchKMeans(init='k-means++', n_clusters=3, batch_size=batch_size,
                      n_init=10, max_no_improvement=10, verbose=0)
t0 = time.time()
mbk.fit(X)
t_mini_batch = time.time() - t0

# 打印k-means++运行时间和性能度量
print("k-means++_runtime= ",t_batch)
print("k_means++_metics= ",k_means.inertia_)
# 打印minibatch_k_means++运行时间和性能度量值
print("MiniBatch_k_means++_runtime= ",t_mini_batch)
print("k_means_metics= ",mbk.inertia_)

#>
k-means++_runtime=  0.36002039909362793
k_means++_metics=  25164.97821695812
MiniBatch_k_means++_runtime=  0.15800929069519043
k_means_metics=  25178.611517320118