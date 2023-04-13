##### Shriyansh Singh
##### CSULB ID: 028243304
##### Prof. Giacalone
##### Due Date and Time: February 23rd, 2023, 11:59 PM

## CECS 326 Reading Assignment: Processes and Threads
### 20 points

#### Assignment Description
Answer the following questions from the chapter 2 reading from your text book. Be complete with your answers. You may work on these questions with one or two other partners, but *all* students must submit the document individually in their own repositories along with each student's name documented with the submission.

1. Assume that you are trying to download a large 2-GB file from the Internet. The file is available from a set of mirror servers, each of which can deliver a subset of the file’s bytes; assume that a given request specifies the starting and ending bytes of the file. Explain how you might use threads to improve the download time.

**Answer:** Threads can download time of the large file as you split the overall downloading process by creating multiple mini-processes; multiple threads can be created, due to faster creation and deployment process, and assigned to each of the mirror servers to download the subsets of the file's bytes simultaneously. Therefore, using threads enables parallelism in the downloading process, increasing efficiency, and thus a faster download time.
   
2. What is the biggest advantage of implementing threads in user space? What is the biggest disadvantage?

**Answer:** The biggest advantage of implementing threads in the user space is faster creation, deployment, switching, and management of threads, without the going through system calls and kernel space. The biggest disadvantage of user threads in user space is complex or difficult implementation of system calls without stopping all threads or making changes to the operating system or the user programs.

3. Does Peterson’s solution to the mutual-exclusion problem shown in Fig. 2-24 of MOS4e work when process scheduling is preemptive? How about when it is nonpreemptive?

**Answer:** Peterson's solution to the mutual-exclusion problem of MOS4e works only when process scheduling is non-preemptive, or co-operative, because his solution assume the running process is willing to give up the CPU to the interruption from next in-line, waiting process during its critical region. However, when the process scheduling is preemptive, the running process may be either not be willing to give up the CPU and cooperate or the next in-line process may try to enter its critical region before the running process has finished its critical region, causing a deadlock.
   
4. The producer-consumer problem can be extended to a system with multiple producers and consumers that write (or read) to (from) one shared buffer. Assume that each producer and consumer runs in its own thread. Will the solution presented in Fig. 2-28 of MOS4e, using semaphores, work for this system?

**Answer:** The producer-consumer problem's solution presented in Fig. 2-28 using semaphores will work for this system, becuase the solution uses three semphores: empty, full, and mutex. Since the problem is related to issue of "processes shar[ing] a common, fixed-size buffer," the 3 semphores can be used to achieve mutual exclusion in buffer access by keeping track of empty and full buffer slots(thus enabling synchronization--producer and consumer stop running when the buffer is full or buffer, respectively), but importantly, that the producer and consumer don't access the buffer at the same time.
   
5. How could an operating system that can disable interrupts implement semaphores?

**Answer:** An operating system with the ability to disable interrupts is able to semaphores, because this prevents other processes or threads to access the current semphores until its active operation is completed or blocked. This is forces the other processes or threads to be put on hold and wait in the queue, enabling mutual exclusion and preventing chaos.

6. A fast-food restaurant has four kinds of employees:
    (a) order takers, who take customers’ orders; 
    (b) cooks, who prepare the food;
    (c) packaging specialists, who stuff the food into bags; and
    (d) cashiers, who give the bags to customers and take their money.
    Each employee can be regarded as a communicating sequential process. What form of interprocess communication do they use? Relate this model to processes in UNIX.

**Answer:** The fast-food restaurant employees are using message sharing, as a form of interprocess communication to communicate with each other. The individual operations preformed by the employees are using the same message shared among, passing them one to the next, until the food is delivered and the money taken for the order. This is similar to one of the processes in Unix, called "Shared memory," where multiple processes "share," or access the same memory to perform their operations.

7. Five jobs are waiting to be run. Their expected run times are 9, 6, 3, 5, and x. In what order should they be run to minimize average response time? (Your answer will depend on x).

**Answer:** In order for the jobs to be run in the lowest average response time, the jobs should be run from the smallest to the largest run time, i.e. in 3, 5, 6, 9; however, since the last job(x)'s run time is unknown, the overall order of run time for the jobs depends on x. Once the value of last job's run time is known, it can be put in the order place, from smallest to the largest order.

8. The aging algorithm with a = 1/2 is being used to predict run times. The previous four runs, from oldest to most recent, are 40, 20, 40, and 15 msec. What is the prediction of the next time? Explain.

**Answer:** The next time can be predicted by aging formula by taking the weight of sum previous times(as the a is halved each run; run-times are decreasing geometrically) and divided by sum of the weights(to normalize the weights): 
>((40/2) + (20/4) + (40/8) + (15/16)) / ((1/2) + (1/4) + (1/8) + (1/16)) 
> = 33 seconds

9. In the dining philosophers problem, let the following protocol be used: An even-numbered philosopher always picks up his left fork before picking up his right fork; an odd-numbered philosopher always picks up his right fork before picking up his left fork. Will this protocol guarantee deadlock-free operation? Why or why not?

**Answer:** This protocol will not guarantee a deadlock-free operation, because there is a possibility that all the odd-numbered philosophers will pick up their right forks, and all the even-numbered philsophers will pick up their left forks, all at the same time. This situation would philsopher would deprive them of their respective left and right forks, as the even-numbered philsopher could be holding odd-numbered philosopher's right fork and vice versa, causing a deadlock.

10. The readers and writers problem can be formulated in several ways with regard to which category of processes can be started when. Carefully describe three different variations of the problem, each one favoring (or not favoring) some category of processes. For each variation, specify what happens when a reader or a writer becomes ready to access the database, and what happens when a process is finished.

**Answer:** The three variations of the problem can be:
> - Reader's favoring variation: Multiple readers are allowed to access the database simultaneously, but only one writer can access the database at a time. This will cause the readers to occupy the database, while the writers wait in a queue. When both readers and writers are in a queue, readers are given priority over the writers, making them wait to access the database, until all the readers are done.
> - Writer's favoring variation: Even though all the writers cannot access the database simultaneously, When both readers and writers are in a queue, writers are given priority over the readers, locking the database and making them wait, until all the writers are done, one after the other. 
> - Fair variation: Although multiple readers are still allowed to access the simultaneously and only one writer at a time, this variation gives readers and writers equal priority, letting first come to next access the database until their individual process is finished.