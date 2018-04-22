## Airline Reservations System

A small airline has just purchased a computer for its new automated reservations system. The president has asked you to program the new system. You are to write a program to assign seats on each flight of the airline's only plane, which has a maximum capacity of 30 seats. 

Your program the at and menu should the following title displaybeginning:
Flight Seating System 
Type 1 for "First Class." 
Type 2 for "Economy."


After this initial display, your program should ask the 30 potential passengers about their seat choices. The first class section consists of seats 1 through 05 and the economy section consists of seats 06 through 30.

If the person enters 1, then your program should assign a random seat in the first class section. If the person enters 2, then your program should assign a seat in the economy section. Your program should then print a boarding pass indicating the person's seat number and whether it's in the first class or economy section of the plane.

Use a one-dimensional array to represent the seating chart of the plane. Initialize all the elements of the array to 0 to indicate that all seats are empty. As each seat is assigned, set the corresponding element of the array to 1 to indicate that the seat is no longer available.

Your program should, of course, never assign a seat that has already been assigned. When the first class section is full, your program should ask the person if it's acceptable to be placed in the economy section (and vice versa). If yes, then make the appropriate seat assignment.

Input Validation: if the person enters any value other than 1 or 2, the program should not exit at this point,instead it should keep running from where it left off.