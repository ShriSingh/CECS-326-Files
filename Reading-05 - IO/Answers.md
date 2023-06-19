#### Shriyansh Singh
#### CSULB ID: 028243304
#### Prof. Giacalone
#### Due Date and Time: April 28th, 2023, 11:59 PM

------------------------------------------------------------------------------------------------------------------------------
### CECS 326 Reading Assignment: Input and Output
#### 20 points

#### Assignment Description
Answer the following questions from the Chapter 6 reading from your text book. Be complete with your answers. You may work on these questions with one or two other partners, but *all* students must submit the document individually in their own repositories along with each student's name documented with the submission.

------------------------------------------------------------------------------------------------------------------------------

1. A DMA controller has five channels. The controller is capable of requesting a 32-bit word every 40 nsec. A response takes equally long. How fast does the bus have to be to avoid being a bottleneck?

    **Answer:** The required speed of the bus to avoid being a bottleneck is calculated as follows:
    Requested data = 32 bits
    Total time taken = Request time + Response time = 2 * 40 = 80 nsec
    Speed of the bus = Requested data / Total time taken
    Speed of the bus = 32 bits / 80 nsec =  4 * 10^8 bits/sec or 50 mbps, when the DMA controller is using a round-robin algorithm(each of the channel in the controller are utilized in a cyclic manner) or 
    (4 * 10^8) * 5 = 2 * 10^9 bits/sec or 250 mbps, when the DMA controller is not using a round-robin algorithm, where the number of  channels present can effect the data transfer rate.

2. Explain how an OS can facilitate installation of a new device without any need for recompiling the OS.

    **Answer:** An Operating system can simplify the installation of a new device by having installing the I/O software of that device. The I/O software contains device drivers and device-independent I/O software. The device drivers are low-lovel interface that interact with the I/O device hardware, while providing a base for the I/O software to set itself up. The device-independent I/O software provides a medium for the operating system to interact with the device driver. 

3. Why are output files for the printer normally spooled on disk before being printed?
    
    **Answer:** Spooling is a type of multi-programming for I/O devices, for the data to be executed is held onto, while other processes are being worked upon. The output files for the printer are spooled on disk before printed for the following reasons:
    -  Prevents deadlocking the system when the printer might executing other running print jobs
    -  Keeps the order of the print jobs intact and in sequence
    -  Preserves data of incoming print jobs when the printer is busy or unavailable
    -  Improves the printing performance, as reading out data from disk would be faster than the reading out data from computer's memory

4. What are the advantages and disadvantages of optical disks versus magnetic disks?

    **Answer:** The advantages and disadvantages of optical disks versus magnetic disks are as follows:
    - Advantages of magnetic disks:
      - Greater storage capacity
      - Faster read and write speeds
      - Reliable form of storage(especially, secondary storage)
    - Disadvantages of magnetic disks:
      - Prone to damage from magnetic fields and suspectible to magnetic intereference
      - More expensive to produce than optical disks
      - Shorter life span than optical disks
    - Advantages of optical disks:
      - Easier portability and better stability of data
      - Low cost of production and manfacturing
      - Less suspectible to data corruption
    - Disadvantages of optical disks:
      - Prone to damage from scratches and dust
      - Smaller storage capacity than magnetic disks
      - Slower read and write speeds than magnetic disks

5. A computer manufacturer decides to redesign the partition table of a Pentium hard disk to provide more than four partitions. What are some consequences of this change?

    **Answer:** The consequences of redesigning the partition table are as follows:
    - Chances of potential compatibility issues with the existing operating system
    - Increased complexity of the partition table, requiring even more complex software and hardware to manage the partitions
    - Decreased data storage capacity for each partition 
    - Can lead to fragmentation and slower performance
    - Efficient use of storage space if each partition is used for different types of files

6. After receiving a **SIGINT** character, the display driver discards all output currently queued for that display. Why?

    **Answer:** Usage of the **SIGINT** character is considered tricky because it is used to immediately kill a runaway program, which can lead to incomplete or corrupted output. Therefore, the display driver might discard all output queued up to provide a clean slate for the user to work on.

7. Many versions of UNIX use an unsigned 32-bit integer to keep track of the time as the number of seconds since the origin of time. When will these systems wrap around (year and month)? Do you expect this to actually happen?

    **Answer:** The clocks in UNIX systems with an unsigned 32-bit integers will wrap around after 2^32 seconds from the origin UNIX time(1st Jan 1970). This is equivalent to 2^32 / (60 * 60 * 24 * 365), or about 136 years, around the year 2136. However, by that time most systems will have moved to 64-bit integers, so it is unlikely the wrap around will actually happen.

8. Disk requests come in to the disk driver for cylinders 10, 22, 20, 2, 40, 6, and 38, in that order. A seek takes *6 msec* per cylinder.
    How much seek time is needed for:
        a. First-come, first served
        b. Closest cylinder next
        c. Elevator algorithm (initially moving upward)
    In all cases, the arm is initially at cylinder 20.

    **Answer:** The seek time based on the disk arm scheduling alogrithms are as follows:
    - First-come, first served:  
      - Path: Initial(20)->10->22->20->2->40->6->38
      - Total arm motion: (20 - 10) + (22 - 10) + (22 - 20) + (20 - 2) + (40 - 2) + (40 - 6) + (38 - 6) = 10 + 12 + 2 + 18 + 38 + 34 + 32 = 146 cylinders
      - Total Seek Time: 146 * 6 = 876 msecs
    - Closest Cylinder Next: 
      - Path: Initial(20)->22->10->6->2->38->40
      - Total arm motion: (22 - 20) + (22 - 10) + (10 - 6) + (6 - 2) + (38 - 2) + (40 - 38) = 2 + 12 + 4 + 4 + 36 + 2 = 60 cylinders
      - Total Seek Time: 60 * 6 = 360 msecs
    - Elevator algorithm(Initially moving upward):
      - Path: Initial(20)->22->38->40->10->6->2
      - Total arm motion: (22 - 20) + (38 - 22) + (40 - 38) + (40 - 10) + (10 - 6) + (6 - 2) = 2 + 16 + 2 + 30 + 4 + 4 = 58 cylinders
      - Total Seek Time: 58 * 6 = 348 msecs


9. Describe two advantages and two disadvantages of thin client computing.

    **Answer:** The two advantages and disadvantages of thin client computing are as follows:
    - Advantages:
      - Lower hardware costs: Thin clients computers are cheaper than traditional desktop computers, as don't need high-end, powerful powerful processors and large storage capacity.
      - Ease of use and maintenance: Thin clients are easier to use and maintain, as they are centrally managed by a server. 
    - Disadvantages:
      -  Dependence on network: Thin clients need a network infrastructure to the servers; disruption in network connection can prevent the thin clients from performing as intended.
      -  Single-point of failure: Thin clients are dependent on the servers for their functioning; if the servers go down or infect by malicious software, all the thin clients connected by the server will affected.

10. A notebook computer is set up to take maximum advantage of power saving features including shutting down the display and the hard disk after periods of inactivity. A user sometimes runs UNIX programs in text mode, and at other times uses the X Window System. She is surprised to find that battery life is significantly better when she uses text-only programs. Why?
    
    **Answer:** The X Window system is a graphical user interface(GUI) used to manage the display for the UNIX systems. Using the X Windows system ultilizes not only the CPU and memory, but also graphics card to refresh the display screen. This translates to greater power consumption compared to text-mode, as CPU, memory, and graphics card work harder to display the content other than the text. Therefore, the battery life is significantly better in text-mode.