# Systems Programming Assignment 2

## Student Information

- **Name:** Abhiyanshu Anand
- **Roll Number:** MT26009
- **Course:** Systems Programming Refresher
- **Institute:** Indraprastha Institute of Information Technology Delhi (IIIT-Delhi)

---

## Repository Overview

This repository contains the source code, scripts, and supporting files developed for Assignment 2 of the Systems Programming Refresher course. The assignment focuses on practical Linux system programming concepts, including process management, memory debugging, and multithreaded application performance analysis. :contentReference[oaicite:0]{index=0}

---

## Repository Structure

```
.
├── Task1/
│   ├── Process supervisor programs
│   ├── Graceful and forceful termination implementations
│   └── Supporting source files
│
├── Task3/
│   ├── Memory leak analysis
│   ├── Rectified implementation
│   ├── System call tracing
│   └── Symbol table analysis
│
├── Task4/
│   ├── Multithreaded CPU-intensive application
│   ├── Makefile
│   ├── Bash automation script
│   ├── CSV performance data
│   ├── Python graph generation
│   └── Performance analysis files
│
└── Report.pdf
```

---

## Contents

### Task 1 – Job Supervisor
- Creation of independent child processes using `fork()`
- Execution of external programs with `execlp()`
- Parent-child synchronization using `waitpid()`
- Supervisor exit behavior
- Graceful (`SIGTERM`) and forceful (`SIGKILL`) process termination

### Task 3 – Memory Analysis
- Detection of memory errors using Valgrind
- Memory leak rectification
- Verification of corrected implementation
- System call tracing using `strace`
- Symbol table inspection using `nm`

### Task 4 – Multithreaded Performance Analysis
- CPU-intensive application using POSIX threads
- Build automation with Makefile
- Performance data collection using `perf`
- Automated execution through Bash scripting
- Graph generation using Python and Matplotlib
- Performance monitoring using `htop`

---

## Report

The repository includes a comprehensive report documenting:

- Objectives of each task
- Implementation details
- Commands used
- Experimental observations
- Performance analysis
- Screenshots
- Conclusions
- Git version control workflow

---

## Technologies Used

- C
- GCC
- POSIX Threads (pthread)
- Make
- Bash
- GDB
- Valgrind
- Strace
- nm
- Perf
- htop
- Python 3
- Matplotlib
- Git & GitHub

---

## Build

Compile the source files using GCC or the provided Makefile (where applicable).

Example:

```bash
make
```

Clean generated binaries:

```bash
make clean
```

---

## Author

**Abhiyanshu Anand**  
Roll Number: **MT26009**
