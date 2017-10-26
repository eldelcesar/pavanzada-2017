typedef struct number{
  int key;
  int freq;
} Number;

int* topKFrequentNumbers(int*, int, int, int*, int*);
Number initNumber(int, int);
Number* rankNumbers(int, int*, int*);
int cmpNumbers (const void * a, const void * b);
int* sortArray(int*, int);
