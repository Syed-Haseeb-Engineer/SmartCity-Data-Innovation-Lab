import sqlite3

# Create a connection to a temporary memory database
conn = sqlite3.connect(':memory:')
cursor = conn.cursor()

# 1. Create the Table
cursor.execute('''
CREATE TABLE Feedback (
    FeedbackID INTEGER PRIMARY KEY,
    CitizenName TEXT,
    Category TEXT,
    Details TEXT,
    Status TEXT
)
''')

# Insert some sample data
sample_data = [
    (101, 'Ravi Sharma', 'Traffic', 'Traffic light broken at Sector 4', 'Open'),
    (102, 'Priya Singh', 'Water', 'No water supply in morning', 'Open'),
    (103, 'Amit Verma', 'Traffic', 'Pothole on Main Road', 'Closed'),
    (104, 'Sneha Gupta', 'Traffic', 'Heavy congestion near school', 'Open')
]
cursor.executemany('INSERT INTO Feedback VALUES (?,?,?,?,?)', sample_data)

# 2. Run the SQL Query to find Open Traffic complaints
print("Executing Query: SELECT * FROM Feedback WHERE Status='Open' AND Category='Traffic'")
cursor.execute("SELECT * FROM Feedback WHERE Status='Open' AND Category='Traffic'")

# Fetch and display results
results = cursor.fetchall()
for row in results:
    print(row)
