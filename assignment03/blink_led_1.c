int counter = 0;

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x014)))

#define ODR5 (1<<5)

int main() {
  while(counter < 25) {
    counter++;
  }
  
  //Enabled the cloud to Port A (GPIO)
  RCC_AHB2ENR = RCC_AHB2ENR | 0x1;
  
  // Setup the GPIO port to become an output
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
