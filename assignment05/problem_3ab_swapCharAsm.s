swapCharsAsm
    LDR R2, [R0]    // Load contents of R0 in R2 (1st char)
    LDR R3, [R1]    // Load contents of R1 in R3 (1nd char)
    STRB R3, [R0]   // Store entire byte of R3 into address of R0 - STR was messing it up
    STRB R2, [R1]   // Store entire byte of R2 int into address of R1
    BX LR           // Go back to what is in LR (calling function)

    END