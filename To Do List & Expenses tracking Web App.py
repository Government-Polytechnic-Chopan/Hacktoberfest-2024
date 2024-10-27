import tkinter as tk
from tkinter import messagebox
import sqlite3

# Connect to SQLite database (or create it if it doesn't exist)
conn = sqlite3.connect('task_expense.db')
cursor = conn.cursor()

# Create tables for tasks and expenses
cursor.execute('''
CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY,
    task TEXT NOT NULL
)
''')

cursor.execute('''
CREATE TABLE IF NOT EXISTS expenses (
    id INTEGER PRIMARY KEY,
    description TEXT NOT NULL,
    amount REAL NOT NULL
)
''')

conn.commit()

# Function to add a task
def add_task():
    task = task_entry.get()
    if task:
        cursor.execute('INSERT INTO tasks (task) VALUES (?)', (task,))
        conn.commit()
        load_tasks()
        task_entry.delete(0, tk.END)
    else:
        messagebox.showwarning("Input Error", "Please enter a task.")

# Function to delete a task
def delete_task():
    selected_task = task_list.curselection()
    if selected_task:
        task_id = task_list.get(selected_task[0])
        cursor.execute('DELETE FROM tasks WHERE id = ?', (task_id,))
        conn.commit()
        load_tasks()
    else:
        messagebox.showwarning("Selection Error", "Please select a task to delete.")

# Function to add an expense
def add_expense():
    description = expense_entry.get()
    try:
        amount = float(amount_entry.get())
        cursor.execute('INSERT INTO expenses (description, amount) VALUES (?, ?)', (description, amount))
        conn.commit()
        load_expenses()
        expense_entry.delete(0, tk.END)
        amount_entry.delete(0, tk.END)
    except ValueError:
        messagebox.showwarning("Input Error", "Please enter a valid amount.")

# Function to load tasks from database
def load_tasks():
    cursor.execute('SELECT * FROM tasks')
    tasks = cursor.fetchall()
    task_list.delete(0, tk.END)
    for task in tasks:
        task_list.insert(tk.END, task[1])

# Function to load expenses from database
def load_expenses():
    cursor.execute('SELECT * FROM expenses')
    expenses = cursor.fetchall()
    expense_list.delete(0, tk.END)
    for expense in expenses:
        expense_list.insert(tk.END, f"{expense[1]}: {expense[2]:.2f}")

# Create main application window
app = tk.Tk()
app.title('Task and Expense Tracker')

# To-Do List
tk.Label(app, text='To-Do List').pack()

task_entry = tk.Entry(app)
task_entry.pack()

tk.Button(app, text='Add Task', command=add_task).pack()
tk.Button(app, text='Delete Task', command=delete_task).pack()

task_list = tk.Listbox(app)
task_list.pack()

# Expense Tracker
tk.Label(app, text='Expense Tracker').pack()

expense_entry = tk.Entry(app)
expense_entry.pack()

amount_entry = tk.Entry(app)
amount_entry.pack()

tk.Button(app, text='Add Expense', command=add_expense).pack()

expense_list = tk.Listbox(app)
expense_list.pack()

# Load initial data
load_tasks()
load_expenses()

# Run the application
app.mainloop()

# Close the database connection when the application is closed
conn.close()
