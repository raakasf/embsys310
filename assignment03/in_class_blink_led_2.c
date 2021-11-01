int counter = 0;

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

#define ODR14 (1<<14)

int main() {
  while(counter < 25) {
    counter++;
  }
  
  //Enabled the cloud to Port B (GPIO)
  RCC_AHB2ENR = RCC_AHB2ENR | 0x2;
  //*((unsigned int*)0x4002104C) = 0x2;
  
  // Setup the GPIO port to become an output
  //*((unsigned int*)0x48000400) = 0x10000000;
  GPIOB_MODER &= 0xDFFFFFFF;
  
  while(1) {
      //Set the output to 1 - LED ON (or 0 - LED OFF)
      GPIOB_ODR = ODR14;   
      counter = 0;
      while(counter < 100000) {
        counter++;
      }
      
      GPIOB_ODR &= GPIOB_ODR & ~ODR14;
      counter = 0;
      while(counter < 100000) {
        counter++;
      }
  }
    
  return 0;
}
