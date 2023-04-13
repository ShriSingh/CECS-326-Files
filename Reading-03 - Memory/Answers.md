#### Shriyansh Singh
#### CSULB ID: 028243304
#### Prof. Giacalone
#### Due Date and Time: April 7th, 2023, 11:59 PM

------------------------------------------------------------------------------------------------------------------------------
### CECS 326 Reading Assignment 4: Memory Management
#### 20 points

#### Assignment Description
Answer the following questions from the Chapter 3 reading from your text book. Be complete with your answers. You may work on these questions with one or two other partners, but *all* students must submit the document individually in their own repositories along with each student's name documented with the submission.

------------------------------------------------------------------------------------------------------------------------------

1. Consider a swapping system in which memory consists of the following hole sizes in memory order: 10MB, 4MB, 20MB, 18MB, 7MB, 9MB, 12MB, and 15MB. Which hole is taken for successive segment requests of:
    - 12MB
    - 10MB
    - 9MB 
    for first fit? 

    Repeat the question for best fit, worst fit, and next fit.

    **Answer**: Here are the holes sizes taken for the segment requests based on the given algorithms,
      - First Fit: 20MB for 12MB request, 10MB for 10MB reqeust, 18MB for 9MB request -> Based on whichever memory hole first enountered is big enough for the segment request
      - Best Fit: 12MB for 12MB request, 10MB for 10MB request, 9MB for 9MB request -> Based on whichever memory hole can perfectly fit the segment request
      - Worst Fit: 20MB for 12MB request, 18MB for 10MB request, 15MB for 9MB request -> Based on whichever memory hole is the largest available for the segment request
      - Next Fit: 20MB for 12MB request, 18MB for 10MB request, 9MB for 9MB request -> Based on whichever memory hole is next to the last hole used for the segment request

2. What is the difference between a physical address and a virtual address?
   
    **Answer:** A physical address is the actual numbered location in a memory cell in the chips of the RAM(Random Access Memory). A virtual address is a memory address that mapped(using a MMU, or a Memory Management Unit) either from ROM(hard drive or an SSD) or directly(in the absence of virtual memory) to physical memory like RAM to refer an actual, physical address/memory location.
   
3. Using the page table of Fig. 3-9 of MOS4e, give the physical address corresponding to each of the following virtual addresses:
   - 20
   - 4100
   - 8300

    **Answer:** The physical addresses for the given virtual addresses are as follows,
      - 20: 0K-4K(0-4195) -> 8K-12K(8192-12287); Physical address = (given value - starting value of virtual frame) + starting value of physical frame => (20 - 0) + 8192 = 8212
      - 4100: 4K-8k(4196-8191) -> 4K-8K(4096-8191); Physical address = (given value - starting value of virtual frame) + starting value of physical frame => (4100 - 4196) + 4096 = 4100
      - 8300: 8k-12K(8192-12287) -> 24K-28K(24576-28671); Physical address = (given value - starting value of virtual frame) + starting value of physical frame => (8300 - 8192) + 24576 = 25684

4. Copy on write is an interesting idea used on server systems. Does it make any sense on a smartphone? Why?

    **Answer:** The idea of "Copy on Write" is to optimize various aspects of computer programming, including paging systems and memory management. The method improves performance by sharing data that are mapped to various processes with READ ONLY protection. But whenever a process tries to modify the data, private copies are created and given to the process' respective page table.
    
    Server systems use this method to efficiently provide mulitple processes, users, requests with their required data, programs, and resource without increasing system overhead and exhausting memory. In smartphones, this idea can be implemented to a smaller scale in certain situations, such as handling resources for multiple programs and applications that are asking for the same data and/or media files.

5. If FIFO page replacement is used with four page frames and eight pages, how many page faults will occur with the reference string **0172327103** if the four frames are initially empty? Repeat this problem for LRU.

    **Answer:** If there are eight pages and the four page frames are initially empty, the number of page faults, depending on the alogrithms are as follows:
      - FIFO(First In First Out): Which removes the least recent page(stays at the lower section of the page frame) with the most recent one(stays at the upper section of the page frame) -> 6 page faults
      - LRU(Least Recently Used): Which replaces the page that has not been used for the longest time -> 7 page faults

6. In the WSClock algorithm of Fig. 3-20(c) on pg. 220 of **MOS4e**, the hand points to a page with R=0. If tau(400), will this page be removed? What about if tau(1000)?

    **Answer:** First we calculate the age of the page, which is new age - old age => 2204 - 1213 = 991.
    Next we compare the age of the page to the tau values. Since, 991 greater than(>) 400, the page will be not removed if tau(400). But 991 is less than(<) 1000, therefore the page will be removed if tau(1000).

7. Virtual memory provides a mechanism for isolating one process from another. What memory management difficulties would be involved in allowing two operating systems to run concurrently? How might these difficulties be addressed?

    **Answer:** Allowing two operating systems to run concurrently can lead to memory management issues such as memory corruption(where memory intended for one OS can be contaminate by another), memory leaks(improper management of memory leading to overconsumption of memory leading to inferior performance), and memory fragmentation(when blocks of memory cannot be assigned to any process because of their small or unusable size, leading to slowdown in processing). These issues can be addressed by using MMUs(Memory Management Units), hypervisers, and virtual machines.

8.  When segmentation and paging are both being used, as in *MULTICS*, first the segment descriptor must be looked up, then the page descriptor. Does the TLB also work this way, with two levels of lookup?

    **Answer:** No, TLB, or Translation Lookaside Buffer, is a small, fast memory cache that stores the most recently used virtual-to-physical page mappings. It is used to reduce the number of memory references that are required to translate virtual addresses to physical addresses. TLB is a single level lookup, and does not require the segment descriptor to be looked up.

9.  A student in a compiler design course proposes to the professor a project of writing a compiler that will produce a list of page references that can be used to implement the optimal page replacement algorithm. Is this possible? Why or why not? Is there anything that could be done to improve paging efficiency at run time?

    **Answer:** No, it is not possible to write a compiler that will produce a list of page references that can be used to implement the optimal page replacement algorithm. This is because the optimal page replacement algorithm is a non-preemptive algorithm that requires the entire list of page references to be known before it can be implemented. However, there are other algorithms that can be used to improve paging efficiency at run time, such as the LRU(Least Recently Used) algorithm.