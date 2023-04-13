// Shriyansh Singh
// CSULB ID: 028243304
// CECS 326-01 Lab 1: Threads
// Prof. Giacalone
// Due Date: February 17th, 2023, 11:59 PM

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

// Answers to the Questions in the README:
/**
 * 1. Explain what `pthread` is doing in this program. Be specific.
 *   Answer: `pthread` in this program is first initializing two threads, one parent thread and one child thread
 *   using `pthread_t`. Then the `pthread_create()` function is used to create the child thread(main/parent thread is 
 *   already created by default when int main() is called). The `pthread_create()` is also used to call the child() 
 *   function, using a void pointer and reference to the child thread. Lastly, the `pthread_cancel()` function is used to
 *   "cancel," or kill the child thread, when the user presses the enter key.
 * 
 * 2. Explain why the sleeping thread can print its periodic messages while the main thread is waiting for keyboard input.
 *   Answer: Threads are tiny-version of an execution(like a process) that can run independently and concurrently of each other. 
 *   A sleeping thread is made to pause/delay its execution for a certain amount of time, and while other threads can continue 
 *   to run and execute. Therefore, a sleeping thread can print its periodic messages after its completes its waiting period,
 *   simultaneously while the main thread is waiting for keyboard input.
*/

/**
 * @brief Secondary thread(child thread) - function that runs in an infinite loop
 * until the user presses the enter key.
 * @param ignored 
 * @return void* 
 */
static void *child(void *ignored) {
   // Variable to hold a boolean value
   bool loop_status = true;
   while (loop_status) {
      // Delaying the message below the sleep() by 3 seconds
      sleep(3);
      // Printing out the message after the 3-second delay
      printf("Child(thread) is done sleeping 3 seconds...\n");
   }
   return NULL;
}

/**
 * @brief Main(parent thread) - creates a child thread and waits for the user 
 * to press the enter key. After the enter key is pressed, the child thread is killed. 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
   // Initializing the child thread
   pthread_t child_thread; 
   // Variable to hold the return value of the pthread_create() function
   int code;

   // Creating the child thread, pointing to the child() function
   code = pthread_create(&child_thread, NULL, child, NULL);

   // Conditional statement to check if the user has pressed the enter key
   if (getchar() == '\n') { //Whenever an enter key is pressed, we get a new line character
      // If the user presses the enter key, the child thread is "cancelled"
      pthread_cancel(child_thread);
      printf("Child(thread) has been killed.\n");
   }
   
   // A conditional statement to check if the child thread was successfully created
   if(code){
      // Print an error message if the child thread was not successfully created
      fprintf(stderr, "pthread_create failed with code %d\n", code);
   }

   // Delaying the message below the sleep() by 5 seconds
   sleep(5);
   // Printing out the message after the 5-second delay
   printf("Parent(thread) is done sleeping 5 seconds.\n");

   // Ending the program
   return 0;
}
