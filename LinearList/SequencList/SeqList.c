//
//  SeqList.c
//  SequencList
//
//  Created by 张鹏 on 2018/7/24.
//  Copyright © 2018 DancewithPeng. All rights reserved.
//

#include "SeqList.h"


// 打印顺序表
void printList(SeqList L) {
    int i;
    for (i=0; i<L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


// 顺序表插入元素
int insertList(SeqList *L, int i, DataType x) {
    
    if (i<0 || i>L->length) {
        return 1;   // 错误码，1，表示i不符合要求
    }
    
    if (L->length >= ListSize) {
        return 2;   // 错误码，2，表示顺序表溢出
    }
    
    // 移动其他元素
    int j;
    for (j=L->length-1; j>i; j--) {
        L->data[j] = L->data[j-1];
    }
    
    L->data[i] = x;
    L->length++;
    
    return 0;   // 操作成功返回0
}


// 删除顺序表元素
int deleteList(SeqList *L, int i, DataType *x) {
    
    if (i<0 || i>=L->length) {
        return 1; // 错误码，1，表示i不符合要求
    }
    
    // 保存将要删除的元素
    DataType t = L->data[i];
    
    int j;
    for (j = i; j < L->length-1; j++) {
        L->data[j] = L->data[j+1];
    }
    
    // 更新顺序表长度
    L->length--;
    
    *x = t;
    
    return 0;
}


// 反转顺序表
void reverseList(SeqList *L) {
    
    int i;
    for (i=0; i<L->length/2; i++) {
        int j = (L->length-1) - i;
        DataType temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}


// 找最大和最小值
void maxAndMin(SeqList *L, DataType *max, DataType *min, int *maxIndex, int *minIndex) {
    if (L->length <= 0) {
        return;
    }
    
    *max = L->data[0];
    *maxIndex = 0;
    *min = L->data[0];
    *minIndex = 0;
    
    int i;
    for (i=0; i<L->length; i++) {
        if (L->data[i] > *max) {
            *max = L->data[i];
            *maxIndex = i;
            continue;
        }
        
        if (L->data[i] < *min) {
            *min = L->data[i];
            *minIndex = i;
            continue;
        }
    }
}
