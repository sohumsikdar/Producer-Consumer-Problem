# Producer consumer Problem in Kernel Space

<i>In the diff files there is a diff of kern_2D_memcpy & kern_process_delay. Kindly Ignore.</i>

<br>

## Testing the Modifications
    
<br>

Apply the Patches to the stock kernel<br>
Run the makefile given<br>
run the command <br>

    ./p and ./c in different terminals

Kill the both the processes and run

    sudo dmesg -c

```p``` is the producer which Enqueues in the queue and ```c``` is the consumer which dequeues from the queue.

<br>

## Modifying the Kernel 

### syscall_64.tbl
    
    Added the name of syscalls writer and reader and their syscall numbers

### sys.c

    Added semaphore headerfiles
    
    Added the definition of the syscalls writer and reader.
    
    Added Global Variables front, rear, semaphores, circQueue pointer, size of queue.
<br>

## writer

    This is used by the producer to enqueue elements into the queue. 

## reader

    This is used by the consumer to dequeue elements from the queue

## Use of Semaphores
    Semaphore s1 = N : Number of empty slots in buffer
    
    Semaphore s2 = 0 : Number of slots filled
    
    Semaphore s3 : Mutex, used to provide mutual exclusion

## Random Values in Producer

    refer to getRand() function defined in Producer.
    
    Read an 8 byte number into a character buffer from /dev/urandom

    Convert that character buffer to an unsigned long long using bitwise manipulation

<br>

 ## References
https://shivammitra.com/c/producer-consumer-problem-in-c/ <br>
https://www.programiz.com/dsa/circular-queue <br>
https://stackoverflow.com/questions/30720546/converting-8-byte-char-array-into-long









