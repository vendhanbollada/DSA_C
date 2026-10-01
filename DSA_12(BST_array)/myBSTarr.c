#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include "BST_Arrays.h"


int get_right_child(char *, int , int){
    if(key > tree[index]){
        index = 2*index + 1;
    }
    else if(key > tree[index]){
        index = 2*index + 1;
    }
    else{
        return -1;
    }
}