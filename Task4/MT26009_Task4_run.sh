#!/bin/bash
echo "Enter number of threads (1,2,4,8):"
read threads
outfile="MT26009_Task4_thread${threads}.csv"
echo "Threads,TaskClock,ContextSwitches,PageFaults,Cycles">"$outfile"
perf stat -x, \
-e task-clock,context-switches,page-faults,cycles \
./threads "$threads" 2> perf.tmp
taskclock=$(grep task-clock perf.tmp | cut -d',' -f1)
context=$(grep context-switches perf.tmp | cut -d',' -f1)
faults=$(grep page-faults perf.tmp | cut -d',' -f1)
cycles=$(grep -w cycles perf.tmp | cut -d',' -f1)
echo "$threads,$taskclock,$context,$faults,$cycles">> "$outfile"
rm perf.tmp
echo "Performance data saved to $outfile"
