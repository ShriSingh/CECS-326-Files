#### Shriyansh Singh
#### CECS 326 Sec-01
#### Prof. Giacalone
#### CSULB ID: 028243304
#### Due Date: February 10th, 2023, 11:59 PM
## CECS 326 Reading Assignment: Introduction to Operating Systems
### 20 points

### Assignment Description
Answer the following questions from the Chapter 1 reading from your text-book. Be thorough and complete with your answers. You may work on these questions with one or two other partners, but *all* students must submit the document individually in their own repositories along with each student's name documented with the submission.

1. What are the two main functions of an operating system?

**Answer:** The two main functions of an operating systems are:
    a) Providing the application programmers and users with a cleaner, more abstract("user-friendly") set of resources and services to use and interact with, so users and programmers can focus using the computer for their needs and purposes.
    b) Managing the computer resources among the hardware and software components of the system, to ensure that the computer is efficiently using the connected hardware devices and its software programs.

2. What is the difference between timesharing and multiprogramming systems?

**Answer:** The difference between timesharing and multiprogramming systems:
    a) Multiprogramming systems "multitask" by simultaneously running multiple, different instuctions and bouncing around between various programs at the same time until all sets of instructions from all the programs are completely execute; therefore preventing CPU idling and engaging all the processing power of CPU, 100% of the time. The programs are allocating a paritition of memory depending on the complexity of the instruction.
    b) Timesharing system is an extension of the multiprogramming system, wherein multiple programs are given a paritition of time to run the programs with the shared computer resource. The difference is all the sets of instructions, one after the other, of a given program are executed at the same time.

3. The family-of-computers idea was introduced in the 1960s with the IBM System/360 mainframes. Is this idea now dead as a doornail or does it live on?

**Answer:** The Mainframe family-of-computers are still relevant in today's time, in the form of their size & sturcture, I/O Capacity, processing power, and Operating Sytems for their specific use cases. These style of computers, now known as supercomputers, are still used in various industries, like banking, insurance firms, cloud computing, etc. that require the processing power of processing large amounts of data, doing extremely massive/complicated calculations, and/or keeping track of massive amounts of inputs.

4. What is the difference between kernel and user mode? Explain how having two distinct modes aids in designing an operating system.

**Answer:** Kernel mode and User mode are the two modes of operation in a Computer.
    a) Kernel Mode: Holds the operating system, the most fundamental piece of software, all the instruction sets to the Hardware and peripheral, I/O devices. It can execute any high or low level instruction that the machine is capable of.
    b) User Mode: Holds the user programs and software, i.e. a subset of machine instructions. This mode contains the user interface, shell or GUI, at the lowest lowel, to high-level applications like web browsers, word processors, music players, games etc. The User mode is not allowed to affect the control of the machine nor its connected peripheral, I/O Devices.
Having two such distinct modes aide the designers of the Operating System in providing a stable, secure environment that can be built and improved upon, without the fear of the instructions from the user programs affecting the functioning of the machine.

5. On early computers, every byte of data read or written was handled by the CPU (i.e., there was no DMA). What implications does this have for multiprogramming?

**Answer:** Not having a DMA, or Direct Memory Access, would force CPU to be occupied in reading and writing data flow from the I/O devices, instead of executing instruction sets from the programs. This would result in low efficiency and greater CPU idling in certain tasks in Multiprogramming systems. With the presence of DMA, the CPU can solely focus on executing programs, while the DMA could the data flow between the I/O devices.

6. There are several design goals in building an operating system, for example, resource utilization, timeliness, robustness, and so on. Give an example of two design goals that may contradict one another.

**Answer:** Two such design tools that contradict one another are:
    a) Resource Utilization: Operating System should be able to utilize the resources of the computer efficiently, i.e. the CPU, Memory, I/O Devices, etc. to the maximum extent possible, without wasting any of the resources.
    b) Robustness: Operating System should be able to handle and recover from any kind of error, fault, or failure in the system, without crashing or causing any damage to the system.
These two design goals contradict one another and require a delicate balance; an Operating System should be able to utilize the resources of the computer efficiently, but if the Operating System is not robust enough to handle errors or failures in the system, it would not be able to recover from it, and would crash, causing damage to the system, therefore reducing efficiency.

7 Which of the following instructions should be allowed only in kernel mode?
    (a) Disable all interrupts.
    (b) Read the time-of-day clock.
    (c) Set the time-of-day clock. (d) Change the memory map.

**Answer:** The only instructions that should be allowed only in kernel mode are (a) and (d), i.e., disable all interrupts and change the memory map, respectively. As these instructions require the fundamental, or lowest level control and access to the computer, and the Operating System, to be able to execute them. The other two instructions, (b) and (c), can be executed in both the modes, as they do not require the fundamental control to be able to execute them.

8. Consider a system that has two CPUs, each CPU having two threads (hyperthreading). Suppose three programs, P0, P1, and P2, are started with run times of 5, 10 and 20 msec, respectively. How long will it take to complete the execution of these programs? Assume that all three programs are 100% CPU bound, do not block during execution, and do not change CPUs once assigned.

**Answer:** It will 20 msec to complete the execution of all three programs, because although the CPUs with shortest program run times
will finish first, they will wait and idle for the CPU with the longest run time to finish, becuase of the 100% CPU bound nature of the programs.

9. What is a trap instruction? Explain its use in operating systems.

**Answer:** Trap instruction is a special instruction used in transferring the insturction processing control from the user mode to the kernel mode. This type of special instruction is used in Operating systems to help establish a safe, stable transition from user mode to kernel mode in order to execute certain instruction that require the services of the Operating System, like reading data from a file, accessing stored data in memory, etc. 

10. Modern operating systems decouple a process address space from the machine’s physical memory. List two advantages of this design.

**Answer:** The two advantages of the design of decoupling a process address space from the machine's physical memory are:
    a) The process address space is not limited to the physical memory of the machine, and can be extended to the virtual memory of the machine, which is much larger than the physical memory.
    b) The process address space can be shared among multiple processes, which can be executed simultaneously, without the need of the physical memory to be duplicated for each process. This saves a lot of memory space, and also reduces the time required to execute the processes.