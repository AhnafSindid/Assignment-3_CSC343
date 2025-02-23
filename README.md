1. When a process creates a new process using the fork() operation, which of the following state is shared which are not between the parent process and the child process? Explain your answers couple of sentences.
a. Stack  b. Heap c. Shared memory segments

Answer: When a process creates a new process using the fork() operation, shared memory segments is shared between the parent and child processes. Stack and heap is not shared between the processes. 

2. Discuss Apple’s mobile iOS  and android operating system services for concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.
   
Answer: Both apple and android uses multithreading to execute multiple threads concurrently. Apple uses Operation Queues for handling concurrent processing while android uses threads. There are many complications that concurrent processing adds to an operating system. Some
of them are as follows:
  •	Race conditions can happen when multiple processes try to access shared resources without proper execution, which can in term lead to misinformation or skewed data.
  •	Deadlocks can happen as processes would have to wait for resources used by each other.
  •	Performance bottlenecks can be seen as multiple process are trying to access the same limited data.
