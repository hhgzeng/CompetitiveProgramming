import pandas as pd

# data = {'A': [1, 2, 3], 'B': [4, 5, 6]}
# df = pd.DataFrame(data)

# sum_value = df['B'].sum()

# print(sum_value)

# 读取文件的数据 read file
data = pd.read_excel('data.xlsx')
# 打印前五行数据 print the first five lines data
print(data.head())
# 打印后五行数据 print the last five lines data
print(data.tail())