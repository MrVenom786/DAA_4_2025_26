#include <bits/stdc++.h>
using namespace std;

long operations =0;
int maxDepth =0;

void complexRec(int n) {


   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}
int main(){
   vector<int> testSizes = {12, 24, 48, 96, 192, 384, 768, 1536};
   for (int size : testSizes) {
       operations = 0;
       maxDepth = 0;
       complexRec(size);
       cout << "Input Size: " << size << ", Operations: " << operations << ",  Recursion Depth: " << maxDepth << endl;
   }
    return 0;
}