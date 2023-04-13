#### Shriyansh Singh
#### CSULB ID: 028243304
#### Prof. Giacalone
#### Due Date and Time: April 12th, 2023, 11:59 PM

------------------------------------------------------------------------------------------------------------------------------

### CECS 326 Reading Assignment: Deadlock
#### 20 points

#### Assignment Description
Answer the following questions from the Chapter 6 reading from your text book. Be complete with your answers. You may work on these questions with one or two other partners, but *all* students must submit the document individually in their own repositories along with each student's name documented with the submission.

------------------------------------------------------------------------------------------------------------------------------

1. Students working at individual PCs in a computer laboratory send their files to be printed by a server that spools the files on its hard disk. Under what conditions may a deadlock occur if the disk space for the print spool is limited? How may the deadlock be avoided?

    **Answer:** Deadlock can occur if the server runs out of disk space for the print spool exactly when the students have sent many of their files to be printed by the server. The server needs to print the files sent by the students, but the disk space of the print spool required to store has ran out, so the server cannot spool the file and fulfill the incoming request. Deadlock in this situation can be avoided by immediately starting to file before it is fully spooled, thus freeing up disk space for the server to spool the remaining part of the file and other incoming files. 

2. In the preceding question, which resources are preemptable and which are nonpreemptable?

    **Answer:** In the situation from question 1, the printer is a nonpreemptable resource, because it cannot be used, shared, or taken away until the requested file is printed, without affecting the performance and print job. The disk space of the print spool is a preemptabel resources, because it can be used or taken away by the server as soon as the file is requested to be printed.  

3. The four conditions (mutual exclusion, hold and wait, no preemption and circular wait) are necessary for a resource deadlock to occur. Give an example to show that these conditions are not sufficient for a resource deadlock to occur. When are these conditions sufficient for a resource deadlock to occur?

    **Answer:** Although the four conditions--mutual exclusion, hold and exit, no preemption, and circular wait--are key indicators of a deadlock, there are situations were it might seem as if all the resources are held up by the various processes, but it cannot be referred as a deadlock. For example, let's say there are four processes A, B, C, D and two instances of two resources P and Q. A & D requests P and B & C request Q and get them. However, when processes A & B and B & C request resources P & Q respectively, they are blocked as they are being used up as mentioned before. When the processes finish utilizing the first resource, they can obtain and utilize the second-requested resources and finish their tasks. This is not a deadlock, because the processes are not held up waiting for each other to finish their tasks.

4. Suppose four cars each approach an intersection from four different directions simultaneously. Each corner of the intersection has a stop sign. Assume that traffic regulations require that when two cars approach adjacent stop signs at the same time, the car on the left must yield to the car on the right. Thus, as four cars each drive up to their individual stop signs, each waits (indefinitely) for the car on the left to proceed. Is this anomaly a communication deadlock? Is it a resource deadlock?

    **Answer:** This anomaly can be considered as a communication or a resource deadlock, where processes(in this case cars) are held up becuase they are waiting for each other to communicate the message to yield to the car on the right they can proceed or give the resource--the right of way--to the car on the right, respectively to proceed. This anomaly is more of a competition synchronization, where cars are waiting for the resources in a circular fashion, and all can freely proceed when at least one of them gives way to the first car to approach the intersection, for instance.

5. A system has two processes and three identical resources. Each process needs a maximum of two resources. Is deadlock possible? Explain your answer.

    **Answer:** A deadlock is a state when two processes are competing for the same resources or reach an event and are indefintely waiting for each other to finish their tasks in order to acquire the resource or the event. In this situation, a deadlock can occur both the processes end up holding one resource each and could be deadlocked if they go for the second resources at the same time. They are in a circular wait, waiting for the other process to release the resource they are holding and vice versa.

6. The banker's algorithm is being run in a system with `m` resource classes and `n` processes. In the limit of large `m` and `n`, the number of operations that must be performed to check a state for safety is proportional to `m^{a}*n^{b}`. What are the values of `a` and `b`?

    **Answer:** The time complexity of a banker's algorithm is O(`m` * `n`^2), where `m` is the number of resource classes and `n` is the number of processes. Thereforce it is safe to assume that the number of processes is much greater than the number of resrouce classes. Thus, the values of `a` and `b` can be considered as `0` and `2` respectively, as n^2 is considered of sole importance in the time complexity of the safety check.

7. A distributed system using mailboxes has two IPC primitives, send and receive. The latter primitive specifies a process to receive from and blocks if no message from that process is available, even though messages may be waiting from other processes. There are no shared resources, but processes need to communicate frequently about other matters. Is deadlock possible? Discuss.

    **Answer:** A state of communication deadlock is possible in this situation where the latter IPC primitive blocks the other primitive from sending the message to the process, even though the message is may been sent but are caught up in a delay or is corrupted and lost. In this situation, both primitives are stuck is waiting for the other to give signal to send or receive the message, respectively.

8. One way to prevent deadlocks is to eliminate the hold-and-wait condition. In the textbook it was proposed that before asking for a new resource, a process must first release whatever resources it already holds (assuming that is possible). However, doing so introduces the danger that it may get the new resource but lose some of the existing ones to competing processes. Propose an improvement to this scheme.

    **Answer:** One way to improve the scheme is to require a process requesting the resource to first temporarily realease all the resources it has. Once the process receive its desired reaource, all the other resources it released can be returned for its use. This will prevent the process holding onto resources that it can't use yet (because it is waiting for the other desired resource), preventing potential deadlocks caused by the process.
