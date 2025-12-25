import pandas ad pd
import glob
Import os

#Creating Dummy traffic data for 3 days
data1= {“Road”: [‘Main St’,’2nd Ave’, ‘Main St’], ‘Speed’: [15, 45, 15], 
‘Count’: [120, 50, 120]}
data2={‘Road’: [‘3rd Blvd’, ‘4th Ln’], ‘Speed’: [None, 30], ‘Count’:[80,none]}
data3={‘Road’:[‘Main St’,’5th Ave’], Speed’:[25,60], ‘Count’: [110,40]}

#Saving them as CSV files
pd.DataFrame(data1).to_csv(‘traffic_day1.csv’, index=False)
pd.DataFrame(data2).to_csv(‘traffic_day2.csv’, index=False)
pd.DataFrame(data3).to_csv(‘traffic_day3.csv’, index=False

print(“Dummy csv files created successfully.”)
