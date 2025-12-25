# 1. Read and Join all CSV files
all_files = glob.glob('traffic_day*.csv')
df_list = [pd.read_csv(filename) for filename in all_files]
df_master = pd.concat(df_list, ignore_index=True)

# 2. Remove Duplicates
df_master = df_master.drop_duplicates()

# 3. Fill Missing Values
# Fill missing Speed with the mean (average) speed
df_master['Speed'] = df_master['Speed'].fillna(df_master['Speed'].mean())
# Fill missing Count with 0
df_master['Count'] = df_master['Count'].fillna(0)

# 4. Add "Traffic Level" column
def categorize_traffic(speed):
    if speed < 20: return 'High'
    elif speed <= 40: return 'Medium'
    else: return 'Low'

df_master['Traffic Level'] = df_master['Speed'].apply(categorize_traffic)


# Display the final table for the screenshot
df_master
