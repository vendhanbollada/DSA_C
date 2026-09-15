//			DequeArray.h

void addFront (int *arr, int item, int *pfront, int *prear, int maxsize);
void addRear (int *arr, int item, int *pfront, int *prear, int maxsize);
int delFront(int *arr, int *pfront, int *prear);
 int delRear (int *arr, int *pfront, int *prear); 
void display(int *arr, int maxsize);
int count(int *arr, int maxsize);
int frontEle (int *arr, int front);
int rearEle (int *arr, int rear);

