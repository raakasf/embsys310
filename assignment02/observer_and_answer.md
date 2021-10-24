# Answers to questions in assignment#2

1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
   a) What is the value of the “counter” from the “Locals” window?
   -> -2147483648
   b) What is the value of the “counter” in the “Registers” window?
   -> 0x80000000
   c) Please note down which flags are set in the APSR register. And explain why.
   -> 0x90000000
   -> Flags N and V are set signifying that the result of the instruction was negative and produced an overflow respectively

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
   a) What happens to the value of “counter” in the “Locals” window?
   -> 0
   b) Please note down which are set in the APSR register. And explain why.
   -> Flags Z and C are set signifying that the result of the instruction was zero and produced a carry respectively

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
   a) What is the value of “counter” in the “Locals” window after incrementing for each value?
   -> 2147483648
   b) Please note down which flags are set in the APSR register. And explain why.
   -> Flags N and V are set signifying that the result of the instruction was negative and produced an overflow respectively

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
   a) What is the value of “counter” in the “Locals” window after incrementing for each value?
   -> 0
   b) Please note down which are set in the APSR register. And explain why.
   -> Flags Z and C are set signifying that the result of the instruction was zero and produced a carry respectively

5. Move the “counter’ variable outside of main (at the top of the file):
   a) What is the scope of the variable “counter”?
   -> File
   b) Is it still visible in the “Locals” view?
   -> No
   c) In which window view can we track “counter” now?
   -> Statics Window
   d) What is the address of the “counter” variable in memory?
   -> 0x20000000

6. Change the source code to the following, then run the program in the simulator:

   ```c
      int counter = 0x0;
      int main() {
      int *p_int = (int *)0x20000000;
      ++(*p_int);
      ++(*p_int);
      ++(*p_int);
      counter ++;
      return 0;
      }
   ```

   a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
   -> 4
   b) Explain why the counter value has changed?
   -> The address assigned to `p_int` is where the value of variable counter resides. Incrementing \
    the value at the memory location increments the value of the counter.

7. Change the setting of IAR to run the same program on the evaluation board:
   Setup:
   1. Connect evaluation board to your computer through ST Link cable.
   2. Set the IAR to using STLink:
   3. Project -> Options -> Debugger -> Device: ST-Link
   4. Download setting is flash loader
   5. Make sure ST-Link Interface is set to SWD
   6. Run the same code described in the simulator.
      a) What is the address where “counter” is stored?
      -> 0x20000000
      b) Is the “counter” variable stored in RAM or ROM?
      -> The counter variable is stored in RAM
      c) What is the value of “counter” at the end of the program (halting at the return 0
      statement).
      -> 4
