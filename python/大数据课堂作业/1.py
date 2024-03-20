import pandas as pd

# 读取csv文件数据
job_data = pd.read_csv('step1/job_all.csv')

# 1.查看大数据岗位招聘数据集重复值的数目，如果存在重复值，查看有重复值的列和对应重复值的数目。
# 查看大数据岗位招聘数据集重复值的数目
job_data.  # 请在左侧补充代码
# 查看有重复值的列和对应重复值的数目
def getDuplicateValColumns(df):
    Dupvalcol = {}
    for col in df.columns:
        if >0:  # 请在左侧补充代码
            Dupvalcol[col] =    # 请在左侧补充代码
    return Dupvalcol

print('存在重复值的列：', getDuplicateValColumns(job_data))

# 2.删除大数据岗位招聘数据集行数据重复的数据，并再次查看数据集重复值的数目
job_data=   # 请在左侧补充代码
job_data.   # 请在左侧补充代码

# 3.查看大数据岗位招聘数据集每个属性列存在缺失值的数目。
job_data.   # 请在左侧补充代码

# 4.分别筛选有缺失值的行和列。
# 筛选有缺失值的前20个行索引
print(job_data.loc[].index[:20])    # 请在左侧补充代码
# 筛选有缺失值的列名
print(job_data.loc[].columns)   # 请在左侧补充代码

# 5.将工作地点的缺失值填充为“未知”，并再次查看'工作地点'列的缺失值数目。
job_data['工作地点'].fillna()
print(job_data.isnull().sum(axis=0)['工作地点'])

# 6.删除有缺失值的行，并再次查看数据集中缺失值数目。
job_data.   # 请在左侧补充代码
print(job_data.isnull().sum(axis=0))

