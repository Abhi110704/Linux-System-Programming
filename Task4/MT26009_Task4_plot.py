import matplotlib.pyplot as plt
threads=[1,2,4,8]
taskclock=[4614.46,509.33,510.26,1895.40]
context=[0,0,0,0]
faults=[630,630,635,643]
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
