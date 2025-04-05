# 🚀 Graph Algorithms – System Programming 2, Exercise 1

## 📘 Overview

This project implements a **Graph** and classical **Graph Algorithms** in C++, **without STL**.  
It includes:

- ✅ Breadth-First Search (BFS)
- ✅ Depth-First Search (DFS)
- ✅ Dijkstra's Algorithm
- ✅ Prim's Algorithm
- ✅ Kruskal's Algorithm

Additionally, the following **custom data structures** were implemented:

- 🔁 Queue (for BFS)
- ⚖️ Priority Queue (MinHeap for Dijkstra & Prim)
- 🔗 Linked List (for adjacency list)
- 🔀 Union-Find (for Kruskal)

---

## 📂 Project Structure

```
📦 Ex1_GraphAlgorithms
├── 📄 main.cpp              → Demo program
├── 📄 Makefile              → Build & test commands
├── 📁 include               → Header files
│   ├── algorithms.hpp
│   ├── graph.hpp
│   ├── list.hpp
│   ├── priority_queue.hpp
│   ├── queue.hpp
│   ├── union_find.hpp
│   └── utils.hpp
├── 📁 src                   → Implementation files
│   ├── algorithms.cpp
│   ├── graph.cpp
│   ├── priority_queue.cpp
│   ├── union_find.cpp
│   └── queue.cpp
├── 📁 test                  → Unit tests
│   ├── test_algorithms.cpp
│   └── test_data_structures.cpp
└── 📄 README.md             → This file
```

---

## ⚙️ Build & Run

### 🔨 Compile the program
```bash
make
```

### ▶️ Run the demo
```bash
make run
```

### 🧪 Run unit tests
```bash
make test
```

### 🧹 Clean compiled files
```bash
make clean
```

---

## 🔍 Memory Leak Check (Valgrind)

Make sure Valgrind is installed:

```bash
sudo apt update
sudo apt install valgrind
```

Run the check:

```bash
make valgrind
```

---

## 🧪 Testing Details

- All tests use the [doctest](https://github.com/doctest/doctest) framework.
- Located under the `test/` folder.
- Tests include:
  - Algorithm correctness
  - Data structure functionality
  - Edge cases and exception handling

---

## 👤 Author

**Aviv Oz**  
📧 avivoz4@gmail.com  
🎓 Ariel University – System Programming 2
=======
# ex1-graph-algorithms
Graph algorithms implemented in C++ using custom data structures (no STL)