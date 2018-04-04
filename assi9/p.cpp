void maxpack1 ( int *w, int *c, int n, int B )
{
   int C, cost, i, j, k, weight;
   int **T, **CNT;
   double max, cperw;

   printf("\n+++ Method 1\n");
   /* In this method, we need a bound on the cost. Locate the object with
      the maximum cost/weight ratio. Fill the knapsack with objects of this
      type. */
   max = (double)c[0] / (double)w[0]; j = 0;
   for (i=1; i<n; ++i) {
      cperw = (double)c[i] / (double)w[i];
      if (cperw > max) {
         max = cperw; j = i;
      }
   }
   C = 0.5 + (double)c[j] * (double)B / (double)w[j];
   T = (int **)malloc(n * sizeof(int *));
   CNT = (int **)malloc(n * sizeof(int *));
   for (i=0; i<n; ++i) {
      T[i] = (int *)malloc((C+1) * sizeof(int));
      CNT[i] = (int *)malloc((C+1) * sizeof(int));
      for (j=0; j<=C; ++j) {
         T[i][j] = INFINITY;
         CNT[i][j] = 0;
      }
   }
   j = 0; cost = 0;
   while ((cost <= C) && (j * w[0] <= B)) {
      T[0][cost] = j * w[0];
      CNT[0][cost] = j;
      ++j; cost += c[0];
   }
   for (i=1; i<n; ++i) {
      for (j=0; j<=C; ++j) {
         cost = j; weight = T[i-1][j]; k = 0;
         while ((weight <= B) && (cost <= C)) {
            if (weight < T[i][cost]) {
               T[i][cost] = weight;
               CNT[i][cost] = k;
            }
            weight += w[i]; cost += c[i]; ++k;
         }
      }
   }
   cost = C;
   while (T[n-1][cost] == INFINITY) --cost;
   printf("    Maximum cost = %d\n    Weight = %d\n", cost, T[n-1][cost]);
   printf("    Counts  : "); printcounts(c,CNT,cost,n-1);
   printf("\n");
}














x  