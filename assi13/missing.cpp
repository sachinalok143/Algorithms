#include <stdio.h>
#include <stdlib.h>

#define n 1000000

extern void registerme ( const char * );
extern int readbit ( int, int );
extern void checksolution ( int );

int findmissing ( )
{
   int *IDX, *BIT, x, R, bitpos, n0, n1, i, j;

   /* Invariance: One element in the interval [x, x+R] is missing.
      Initially, nothing is known about x, and the search interval
      is the entire of [0, n]. */
   x = 0; R = n;

   /* IDX[] stores the indices of elements in A[] that lie in the search
      interval [x, x+R] */
   IDX = (int *)malloc(n * sizeof(int));

   /* Initially no elements of A[] are eliminated */
   for (i=0; i<n; ++i) IDX[i] = i;

   /* The array BIT[] is used to store the bits returned by readbit() */
   BIT = (int *)malloc(n * sizeof(int));

   /* x is revealed bit by bit starting from the most significant end. */

   bitpos = 0;
   while (n >= (1 << bitpos)) ++bitpos;

   /* Repeat from most significant to least significant bit positions */
   while (--bitpos >= 0) {

      /* Count of integers in [x, x+R] with bitpos-th position storing bit 0 */
      n0 = (1 << bitpos);

      /* Count of integers in [x, x+R] with bitpos-th position storing bit 1 */
      n1 = R - (1 << bitpos) + 1;

      if (n1 < 0) continue;  /* Switch to next bit position */

      for (i=0; i<R; ++i) {
         /* Query the bitpos-th bits of the remaining elements */
         BIT[i] = readbit(IDX[i],bitpos);

         /* Depending upon the returned bit, decrement one of the counts */
         if (BIT[i] == 0) --n0; else --n1;
      }

      if ((n0 == 1) && (n1 == 0)) {

         /* All elements in [x, x+R] with bit 1 at the bitpos-th position are
            present. One with bit 0 at the bitpos-th position is missing. */

         /* x must have bit 0 at the bitpos-th position, so do not change x */

         /* Relocate the indices of the elements with bit 0 at the bitpos-th
            position to the beginning of IDX[]. */
         for (i=j=0; i<R; ++i) {
            if (BIT[i] == 0) IDX[j++] = IDX[i];
         }

         /* Update R by the new count of remaining elements */
         R = j;

      } else if ((n0 == 0) && (n1 == 1)) {

         /* All elements in [x, x+R] with bit 0 at the bitpos-th position are
            present. One with bit 1 at the bitpos-th position is missing. */

         /* x must have bit 1 at the bitpos-th position, so update x */
         x ^= (1 << bitpos);

         /* Relocate the indices of the elements with bit 1 at the bitpos-th
            position to the beginning of IDX[]. */
         for (i=j=0; i<R; ++i) {
            if (BIT[i] == 1) IDX[j++] = IDX[i];
         }

         /* Update R by the new count of remaining elements */
         R = j;

      } else {
         /* This case should not occur */
         printf("*** Bug in program...: n0 = %d, n1 = %d\n", n0, n1);
      }
   }

   free(IDX); free(BIT);

   return x;
}

int main ()
{
   int x;

   registerme("99FB1331");
   x = findmissing();
   printf("\n--- x = %d\n\n", x);
   checksolution(x);
   exit(0);
}
