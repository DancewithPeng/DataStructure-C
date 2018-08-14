//
//  main.c
//  SequencList
//
//  Created by 张鹏 on 2018/7/24.
//  Copyright © 2018 DancewithPeng. All rights reserved.
//

#include <stdio.h>
#include "SeqList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    SeqList list = {0, 0};
    printList(list);
    
    int i;
    for (i=0; i<101; i++) {
        int errCode = insertList(&list, i, i+1);
        if (errCode) {
            printf("%d\n", errCode);
            break;
        }
    }
    
    printList(list);
    
//    for (i=0; i<10; i++) {
//        DataType temp = 0;
//        int errCode = deleteList(&list, i, &temp);
//        if (errCode) {
//            printf("delete error: %d\n", errCode);
//        } else {
//            printf("deleted element: %d\n", temp);
//            printList(list);
//        }
//    }
    
    reverseList(&list);
    printList(list);
    
    SeqList list2 = {{1, 8, 6, 1, 2, 6, 9, 2, 7, 3, 0}, 11};
    
    printList(list2);
    
    DataType max = 0;
    DataType min = 0;
    int maxIndex = -1;
    int minIndex = -1;
    
    maxAndMin(&list2, &max, &min, &maxIndex, &minIndex);
    
    printf("%d, %d, %d, %d \n", max, maxIndex, min, minIndex);
    
    return 0;
}
