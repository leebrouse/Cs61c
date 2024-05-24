#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    if (n>=0&&n<=31)
    {
       unsigned mask=1<<n;
       unsigned bit=(x&mask)>>n; 
       return bit;
    }else{
        return -1;
    }
    
    
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,unsigned n,unsigned v) {
    // YOUR CODE HERE
    if (n>=0&&n<=31&&(v==0||v==1))
    {
       unsigned mask=1<<n;
       if (v==0)
       {
        *x&=~mask;
       }else{
        *x|=mask;
       }
       
    }
    
   
    
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,unsigned n) {
    // YOUR CODE HERE
    if (n>=0&&n<=31)
    {
       unsigned mask=1<<n;
       *x^=mask; 
    }
}

