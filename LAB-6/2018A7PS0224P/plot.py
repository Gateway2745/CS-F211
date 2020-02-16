import matplotlib.pyplot as plt 
import pandas as pd 
import numpy as np

r_df = pd.read_csv('recursive.csv')
r_size = r_df.iloc[:,0:1].values.flatten()
r_times = r_df.iloc[:,1:2].values.flatten()
r_mem = r_df.iloc[:,2:3].values.flatten() /1024

i_df = pd.read_csv('iterative.csv')
i_size = i_df.iloc[:,0:1].values.flatten()
i_times = i_df.iloc[:,1:2].values.flatten()
i_mem = i_df.iloc[:,2:3].values.flatten() /1024
   
plt.figure(figsize=(18, 10))

plt.subplot(121)
index = np.arange(len(r_size))
plt.bar(index - 0.2, r_times, 0.4, label='recursive merge sort time')
plt.bar(index + 0.2, i_times, 0.4, label='iterative merge sort time')
plt.xlabel('Size', fontsize=10)
plt.ylabel('Time', fontsize=10)
plt.xticks(index, r_size, fontsize=8)
plt.title('Time analysis')
plt.legend(loc='upper left')

plt.subplot(122)
index = np.arange(len(r_size))
plt.bar(index - 0.2, r_mem, 0.4, label='recursive stack space')
plt.bar(index + 0.2, i_mem, 0.4, label='iterative heap space')
plt.xlabel('Size', fontsize=10)
plt.ylabel('Memory (in MB)', fontsize=10)
plt.xticks(index, r_size, fontsize=8)
plt.title('Space analysis')
plt.legend(loc='upper left')

plt.savefig('ANALYSIS.png')
plt.show()