import csv
import matplotlib.pyplot as plt
threads=[]
taskclock=[]
context=[]
faults=[]
for f in ["thread1.csv","thread2.csv","thread4.csv","thread8.csv"]:
	with open(f) as file:
		reader = csv.DictReader(file)
		for row in reader:
			threads.append(int(row["Threads"]))
			taskclock.append(float(row["TaskClock"]))
			context.append(int(row["ContextSwitches"]))
			faults.append(int(row["PageFaults"]))
plt.figure(figsize=(6,4))
plt.plot(threads,taskclock,marker='o')
plt.xlabel("Threads")
plt.ylabel("task Clock(ms)")
plt.title("Task Clock vs Threads")
plt.grid(True)
plt.savefig("taskclock.png")
plt.close()

plt.figure(figsize=(6,4))
plt.plot(threads,context,marker='o')
plt.xlabel("Threads")
plt.ylabel("Context Switches")
plt.title("Context Switches vs Threads")
plt.grid(True)
plt.savefig("context.png")
plt.close()

plt.figure(figsize=(6,4))
plt.plot(threads,faults,marker='o')
plt.xlabel("Threads")
plt.ylabel("Page Faults")
plt.title("Page Faults vs Threads")
plt.grid(True)
plt.savefig("pagefaults.png")
plt.close()

print("Graphs generated successfully.")
