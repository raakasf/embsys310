int counter = 0;

// Table 1 in RM0351
#define RCC_BASE 0x40021000
// 6.4.17 in RM0351
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
// Table 1 in RM0351
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x014)))
// Mode 5 -> OD5 = set 5th bit
#define ODR5 (1<<5)

int main() {
  //Enabled the cloud to Port A (GPIO)
  RCC_AHB2ENR = RCC_AHB2ENR | 0x1;
  
  // Setup the GPIO port to become an output
  // Look at 8.5.13 in RM0351, bit 11 need to be reset
  // and bit 10 needs to be set. Leave everything else alone
  // i.e. bit[11:08]->0111=7 also everything else F.
  GPIOA_MODER &= 0xFFFFF7FF;
  
  while(1) {
      //Set the output to 1 - LED ON (or 0 - LED OFF)
      GPIOA_ODR |= ODR5;   
      counter = 0;
      while(counter < 100000) {
        counter++;
      }
      
      GPIOA_ODR &= ~ODR5;
      counter = 0;
      while(counter < 100000) {
        counter++;
      }
  }
    
  return 0;
}
