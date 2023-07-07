# push_swap
 The algorithm proceeds with sorting the indices of the push swap operations using the quicksort algorithm. This sorting operation ensures that the order of the operations is optimized for efficiency. After the indices are sorted, they are remapped from the range of 1 to the length of the stack.
 
The algorithm keeps track of the ascending order of the elements in stack A from the start. This is done by calculating all the ascending order sequences and skipping any numbers that have already been saved in a hashmap.

#A After first push to B
100 1 4 8 9 25 35 90 etc(100 at the top, all the rest in ascending order.)

The algorithm begins by moving elements from stack A to stack B using divide and conquer. Then, for elements in stack B that are in the lower half of the range
(example: if chunk is 50 then less than 25)
they are moved to the bottom of stack B else they stay at top in B.

#A After double divide and conquer Stack B: (if chunk is 10)
9 , 6, 7, 8, 10 /divisor/ 4, 3, 2, 1, 5
second rotation chunk (20):
9 , 6, 7, 8, 10 /divisor/ 4, 3, 2, 1, 5 is on middle 
19 18 17 16 15 /pushed now/ 9 , 6, 7, 8, 10 /divisor/ 4, 3, 2, 1, 5 /pushed now/ 14 13 12 11 10
keep like this.

By employing this double divide and conquer strategy and keep ascending numbers, the push swap algorithm efficiently reorganizes the stack and generates the necessary swap operations to sort it. This approach aims to minimize the number of operations required and improve the overall performance of the sorting process.

# REBUILD A
The algo will look for the exact len, search on BOTTOM OF A, TOP AND BOTTOM OF B looking for the fastest way to retrieve.
Since A(bottom) is ascending we just have to do RRA to move it on top.

PROJECT DONE
STEPS : STACK A = 100n == 440-560 movement;
STEPS : STACK A = 500n == 4500-4900 movements;

