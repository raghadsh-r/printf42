*This project has been created as part of the 42 curriculum by ralshraw*

# Description
This project helps you print to the terminal more easily instead of write functions.
You can print pointers, decimals, hexadecimals, strings, etc.
It's even good for making simple games like xo or Rock paper scissors.
- > i don't handle write failures.

# Instructions
- You can run it just by this command: `make`
- Compile your main file and run it with: `cc main.c printf.a`
- to see output `./a.out`
- If you want to delete `.o` files: `make clean`
- You must have a C compiler and Valgrind if you want to check for memory leaks (I don't have leaks, I don't allocate on the heap).
- If you face any problems or issues, you can check the terminal help.
- To know more about the original printf function, use the terminal command: `man printf`.
- I solved only two bonuses.

# Resources
It's an easy project so there are no extensive resources, but here are some references:
- > https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- > https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html

### AI Used
I didn't use AI (even how to print pointers took a whole day to search and test).
- > for one of the bonuses that I didn't solve, I asked AI about it just to know it's benefits.

# Algorithm
I didn't follow any specific algorithm, but here is how it works:
Simply, a for-loop checks if a character is `%`, looks at what comes after it, and prints , otherwise it prints the byte normally.