import tkinter as tk
from tkinter import messagebox
import os
import psutil
import getpass
import shutil

def monitor():
    # Process IDs and names
    processes = {p.pid: p.info['name'] for p in psutil.process_iter(['name'])}

    # Find the process with maximum CPU usage
    max_cpu_process = max(processes, key=lambda pid: psutil.Process(pid).cpu_percent())

    print(f"Process {processes[max_cpu_process]} ({max_cpu_process}) is using the most CPU.")

def on_startup():
    response = messagebox.askquestion("Startup", "Do you want this application to start on system startup?")
   
    if response == 'yes':
        # Creating a shortcut to the script in the startup directory
        USER_NAME = getpass.getuser()
        BAT_PATH = r'C:\Users\%s\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup' % USER_NAME
        BAT_PATH = BAT_PATH.replace("\\", "/")

        # Copy your script to the startup directory
        shutil.copyfile('E:\\college\\coding\\programing\\cc++\\tests\\test2.py', f'{BAT_PATH}/script.py')
        print(f"Script added to startup.")

    elif response == 'no':
        print("Script not added to startup.")
import ctypes, sys

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

if is_admin():
    # Code of your program here
    root = tk.Tk()
    root.withdraw()  # Hide the main window

    monitor()
    on_startup()
else:
    # Re-run the program with admin rights
    ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, __file__, None, 1)