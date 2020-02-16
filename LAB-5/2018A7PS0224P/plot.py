import matplotlib.pyplot as plt 
import pandas as pd 
import numpy as np

t_df = pd.read_csv('times.csv', header = None)
t_size = t_df.iloc[:,:-1].values.flatten()
t_times = t_df.iloc[:,-1:].values.flatten()

m_df = pd.read_csv('memory.csv', header = None)
m_size = m_df.iloc[:,:-1].values.flatten()
m_times = m_df.iloc[:,-1:].values.flatten() / 1024

bestfit = np.polyfit(t_size,t_times,2)

a = []
b = []

for x in range(10,100000,50):
    y = bestfit[0] * x**2 + bestfit[1]*x + bestfit[2]
    a.append(x)
    b.append(y)
   
plt.figure()
plt.subplot(121)

plt.plot(a,b, color='blue', label='estimate')
plt.plot(t_size, t_times, color='red', label='measured')
plt.xlabel('Number of Records')
plt.ylabel('Time in ms')
leg = plt.legend()

plt.subplot(122)
plt.plot(m_size, m_times, color='red')
plt.xlabel('Number of Records')
plt.ylabel('Stack Memory in Mega Bytes (MB)')

plt.show()