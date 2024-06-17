# push_swap

## Because Swap_push isn’t as natural

### Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

### Instructions:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b. 
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1.
- rb (rotate b): Shift up all elements of stack b by 1.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
- rrr : rra and rrb at the same time.

### Use:
- step 1:
```
make
```
- step 2: in terminal run the executable with numbers you want to sort
```
./push_swap 2 1 3 6 5 8
```
- step 3: the output will look like this
```
sa
pb
pb
pb
sa
pa
pa
pa
```