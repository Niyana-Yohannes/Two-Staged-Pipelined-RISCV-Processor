/* $Id: Sieve.c $ */

/* Sieve of Eratosthenes algorithm 
 * Ref: http://www.math.utah.edu/~alfeld/Eratosthenes.html
 * This implementation by David Ireland <www.di-mgt.com.au>
 * $Date: 2012/12/14 11:02Z $
 * $Author: dai $
 */

#include <stdio.h>

#define NLIMIT		10		/* maximum number to scan */
#define	KLIMIT		4		/* should be sqrt(NLIMIT)+1 */

/* Usage: Sieve n
 * where n = largest integer to test for prime
 * (default = 1000)
   Ref: http://www.utm.edu/research/primes
 */

unsigned short   mark[NLIMIT];				/* array to mark sieve values */

void
sieve()
{
    int i, m, k;

    /* Mark the composites */
    /* Special case */

    for (i = 0; i < NLIMIT; i++)
	    mark[i] = 0;

    mark[1] = -1;

    /* Set k=1. Loop until k >= sqrt(n) */
    for (k = 1; k <= KLIMIT; k = m)
    {
        /* Find first non-composite in list > k */
        for (m = k + 1; m < NLIMIT; m++)
            if (!mark[m])
                break;

        /* Mark the numbers 2m, 3m, 4m, ... */
        for (i = m * 2; i < NLIMIT; i += m)
            mark[i] = -1;
    }
}

int
main()
{
    //  int i;

	sieve();
    // /* Now display results - all unmarked numbers are prime */
    //  for (i = 1; i < NLIMIT; i++)
    //  {
    //      if (!mark[i])
    //          printf("%d ", i);
    //  }
    //  printf("\n");


    return 0;
}
