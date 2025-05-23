// DIFFIE-HELLMAN ALGORITHM

#include <stdio.h>
#include <conio.h>

long int power(int a, int b, int mod)
{
  long long int t;
  if(b == 1)
  	return a;
  t = power(a, b/2, mod);
  if(b % 2 == 0)
  {
  	return (t*t) % mod;
  }
  else
  {
	return (((t*t) % mod)*a) % mod;
  } 
}


long long int calculateKey(int a, int x, int p)
{
  return power(a, x, p);
}
 
int main()
{
  int p, g, x, a, y, b;  // p - prime number, g - primitive root of p, x - A's private integer, y - B's private integer
 
  printf("Enter the value of p and g : ");
  scanf("%d%d",&p, &g);    
 
  printf("\nEnter the value of x for the sender : ");
  scanf("%d", &x);  
  
  a = power(g, x, p);    

  printf("\nEnter the value of y for the receiver : ");
  scanf("%d", &y);  
  
  b = power(g, y, p);
  
  printf("\nSecret key generated by Sender is : %lld\n", power(b, x, p));
  printf("\nSecret key generated by Receiver is : %lld\n", power(a, y, p));
  return 0;
}
