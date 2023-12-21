import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

# 1. 生成模拟数据
np.random.seed(42)
n_samples = 200
income = np.random.normal(loc=50000, scale=15000, size=n_samples)
age = np.random.normal(loc=35, scale=10, size=n_samples)
data = pd.DataFrame({'Income': income, 'Age': age})

# 保存数据到 'customer_data.csv' 文件
data.to_csv('customer_data.csv', index=False)

# 2. 加载数据集
customer_data = pd.read_csv('customer_data.csv')

# 3. 数据预处理
selected_attributes = customer_data[['Income', 'Age']]

# 4. 标准化数据
scaler = StandardScaler()
scaled_data = scaler.fit_transform(selected_attributes)

# 5. 使用K-means算法聚类
k = 3  # 假设分为3个簇
kmeans = KMeans(n_clusters=k, random_state=42)
customer_data['Cluster'] = kmeans.fit_predict(scaled_data)

# 6. 分析聚类结果
cluster_centers = pd.DataFrame(scaler.inverse_transform(kmeans.cluster_centers_), columns=['收入', '年龄'])
print("聚类中心:")
print(cluster_centers)

# 7. 可视化聚类结果
plt.scatter(customer_data['Income'], customer_data['Age'], c=customer_data['Cluster'], cmap='viridis')
plt.scatter(cluster_centers['Income'], cluster_centers['Age'], marker='X', s=200, c='red')
plt.xlabel('收入')
plt.ylabel('年龄')
plt.title('航空公司客户数据的K-means聚类')
plt.show()
