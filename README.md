# Asignment 4 - I'm manging just fine, thank you
Design Due: Friday, March 26th  
Final Due: Friday April 9th

# Goals
1. Gain comfort in working with pointers
2. Understand the tasks that malloc and free and doing for you
3. Build a simple, but functional memry manager

# Analysis
Now that you have built your linked list of cards, it's time to take it one step further. You boss (grump that he is) doesn't trust malloc and free to handle memory management, and insists that you can do better.

He wants you to write ```void* my_malloc(unsigned int size)``` and ```void my_free(void *ptr)``` to replace the built-in versions of malloc and free. He has provided you a chunk of memory to manage and you don't have to worry about growing that chunk if you run out of space.

Finally, you must write ```void dump_heap()``` that will print out the location and size of each block and whether that block is used or free. (Hint: Do this early, it will help with the rest of the project.)

# Design
Due: Friday, March 26th

Usually, you would have to come up with the design on your own. However, this time a few things have been decided for you:
1. You will use an implicit free list.
2. Your memory must be double word aligned.
3. You must include BOTH a header and a footer.
    * Hint: Start with a version with just a header.
4. You should perform immediate coalescing.
    * Hint: Do this last, or don't for a minor point reduction
    
Things to submit to GitHub:
1. Any more design questions that you might have in ***questions.txt***.
2. A set of milestones in ***milestone.txt*** that decribes how you will break up the problem.


# Testing
I will provide you, at a later date, with a .o file or two that you can compile ```heapmgr.c``` against. These files are inteded to help you figure out if things are functioning correctly, since testing this can be very difficult.

# Final Submission
Due: Friday, April 9th

Submit to GitHub:
1. Your code (without derivable files)
2. A ```Makefile``` with targets ```heapmgr.o``` and ```clean``` as well as ```testheap``` that will run a test program to test your code (this may just use the .o file I have provided you).
3. A file, ***heapdump.txt*** that contains a dump of your heap after running your test program.
