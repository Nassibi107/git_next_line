# git_next_line


# Memrory layout

 1) Text or code Segment

>> when your code convert to machine languge your 'OS' takes snapchot for it and puts it in CODE SEGMENT
>> Text segment contians machine code of the compiled program.
>> the text segment is sharable so taht only a single copy (snapchot) needs to be in memory for frequently executed prgrams,
such as text editors. (note pad etx...).
>> the text segment is often read-only, to prevent a program from accidentlly modifying its instructions.

 2) intialized Data segment

>> usually called simply the Data segment.
>> Stores all globas and static variables that are initialized by the programmer.

 3) intialized Data segment
 
>> usually called the "bss" (block started by symbol) segment .
>> contains all global varaiale and static variable that are do not have explicit initialization in source code.
>> data in this segment is initialized by the kernel to arithmetic 0 => (poiters = NULL,char = '\0' ,int = double = long = 0)

 4) heap
>> free memory for developer .
>> Heap is the segment where Dynamic mermory alloction usually take palce.
>> heao area is managed by malloc ,calloc , , realloc and free .

 5) stack
>> the stack holds local (automatic) variables, temporary information , functions parameters , return address.
>> Typically the stack grows downwaard, meaning that items deeper in the call chain are numerically lower addresses and,
the heap. (FIFO)
>>  when the stack pointer met the heap pointer, free memory was exhausted (stack overflow error).

https://biriukov.dev/docs/fd-pipe-session-terminal/1-file-descriptor-and-open-file-description/
