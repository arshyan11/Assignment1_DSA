# Assignment1_DSA
Problem1:
Approach:
We are using the Circular LinkList in this problem so that we can traverse though the nodes again and again until the remaining time of all processes(Nodes) becomes zero.Each process is represented as a node in this linked list, containing attributes such as execution_time, remaining_time, and process_id, enabling efficient traversal and modification. The scheduler is initialized with a quantum time, time_cpu_per_process, which determines how long each process can execute during a single cycle. Processes are added to the circular linked list through the addprocess method; if the list is empty, the new process points to itself, and otherwise, it is appended at the end while maintaining the circular structure. The core of the algorithm is in the runSchedular method, where the scheduler iterates through the list, allowing each process to execute for a fixed time slice. Upon completion, a process is removed from the list, and its remaining time is updated accordingly. This design ensures fair distribution of CPU time among all processes while keeping the system responsive. The scheduler outputs the status of each process after every cycle, providing a clear overview of the processes running, their remaining execution times, and their completion status, making it a robust solution for managing process scheduling in a time-sharing environment.


Assumptions:
Firstly, it is assumed that all processes are available for scheduling at the beginning, meaning they arrive simultaneously, allowing the scheduler to manage them without delay. Secondly, the execution time provided for each process is a deterministic value, meaning there are no variations or interruptions in processing time once a process begins execution. Thirdly, it is assumed that context switching, which occurs when switching from one process to another, is negligible and does not affect the overall execution time or system performance. Additionally, it is presumed that all processes require non-negative execution times, ensuring that the algorithm functions correctly without handling erroneous input. Finally, the algorithm is designed to manage processes in a preemptive manner, allowing higher-priority processes to be introduced seamlessly into the scheduling queue if necessary, thus maintaining system responsiveness.
 


Challenges:
Firstly, managing pointers during the addition and removal of processes can lead to segmentation faults or memory leaks if not handled carefully, making debugging difficult, especially when maintaining the circular structure. Secondly, accurately updating the remaining time for each process requires meticulous tracking of each process's state across cycles, complicating the scheduling logic. Efficient memory management is also critical, as creating and deleting nodes dynamically can result in memory fragmentation. Finally, ensuring that all processes are treated fairly and scheduled appropriately necessitates careful consideration of edge cases, such as handling empty lists, single-process scenarios, or processes that require exactly the time quantum for completion.



Github Link:
https://github.com/arshyan11/Assignment1_DSA


Output:
![image](https://github.com/user-attachments/assets/90c95c7d-ff63-4296-a889-965716031ee0)






Problem#2:
Approach:
The primary approach to handling a 1024-bit prime number in this implementation involves utilizing a linked list to efficiently store and manage the large number, which is divided into 64-bit segments. The Bignumber class encapsulates the logic for inserting each 64-bit segment into the linked list, enabling dynamic memory allocation and better manipulation of the number. The algorithm also implements a primality test, first checking for single-digit prime numbers and then evaluating the overall primality of the entire 1024-bit number by concatenating the segments stored in the linked list. The use of the isPrime method employs standard techniques for primality testing, ensuring that the algorithm efficiently handles both small and large numbers. Additionally, exception handling is incorporated to manage potential conversion errors when processing the complete number, making the code robust and user-friendly. This structured approach facilitates the effective handling of large prime numbers while ensuring accuracy and efficiency.


Assumptions:
Firstly, it assumes that the input string is exactly 1024 bits in length, consisting solely of valid numerical characters. This simplifies the insertion and manipulation of data within the linked list. The design assumes that the memory allocation for each 64-bit segment is efficient, as the linked list dynamically grows based on the input value. Additionally, it presumes that the user will provide a valid prime number to verify primality, allowing the program to focus on the correctness of the algorithms without extensive input validation. The implementation also assumes that the primality test for the entire number will yield a reliable result, given that it uses a well-established method. Lastly, the program presumes the operating environment can handle large integers, ensuring that the conversions between strings and numerical types will not lead to overflow errors, particularly for the long long type.


Challenges:
One primary challenge is efficiently managing memory allocation and deallocation for the linked list nodes, particularly for a large number like 1024 bits. Proper handling of dynamic memory is crucial to prevent memory leaks and ensure smooth execution. Another challenge is accurately checking the primality of a number represented as a string of characters. The current implementation simplifies this by checking each digit individually, which is not representative of the actual primality of the entire 1024-bit number. Furthermore, handling the conversion from a string to a numeric type (like long long) introduces potential overflow issues since the number may exceed the range of standard data types. There is also the challenge of ensuring that the string parsing and linked list traversal are efficient, as performance may degrade with larger inputs. Finally, validating that the input number is indeed a prime number requires careful consideration of the algorithm used, necessitating thorough testing for accuracy and efficiency.

Github Link:
https://github.com/arshyan11/Assignment1_DSA

Output:
![image](https://github.com/user-attachments/assets/deaaf076-ee73-4831-9f88-a4c9d389b491)



