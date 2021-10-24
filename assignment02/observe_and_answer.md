1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
   a) What is the value of the “counter” from the “Locals” window?
        -> -2'147'483'648
   b) What is the value of the “counter” in the “Registers” window?
        -> 
   c) Please note down which flags are set in the APSR register. And explain why.

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
   a) What happens to the value of “counter” in the “Locals” window?
   b) Please note down which are set in the APSR register. And explain why.

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
   a) What is the value of “counter” in the “Locals” window after incrementing for each value?
   b) Please note down which flags are set in the APSR register. And explain why.

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
   a) What is the value of “counter” in the “Locals” window after incrementing for each value?
   b) Please note down which are set in the APSR register. And explain why.

5. Move the “counter’ variable outside of main (at the top of the file):
   a) What is the scope of the variable “counter”?
   b) Is it still visible in the “Locals” view?
   c) In which window view can we track “counter” now?
   d) What is the address of the “counter” variable in memory?

6. Change the source code to the following, then run the program in the simulator:
   int counter = 0x0;
   int main() {
   int _p_int = (int _)0x20000000; ++(*p_int);
   ++(*p_int);
   ++(\*p_int);
   counter ++;
   return 0;
   }
   a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
   b) Explain why the counter value has changed?

7. Change the setting of IAR to run the same program on the evaluation board:
   Setup:
   1. Connect evaluation board to your computer through ST Link cable.
   2. Set the IAR to using STLink:
   3. Project -> Options -> Debugger -> Device: ST-Link
   4. Download setting is flash loader
   5. Make sure ST-Link Interface is set to SWD
   6. Run the same code described in the simulator.
      a) What is the address where “counter” is stored?
      b) Is the “counter” variable stored in RAM or ROM?
      c) What is the value of “counter” at the end of the program (halting at the return 0
      statement).
