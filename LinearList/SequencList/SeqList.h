//
//  SeqList.h
//  SequencList
//
//  Created by 张鹏 on 2018/7/24.
//  Copyright © 2018 DancewithPeng. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#include <stdio.h>


// 列表最大长度
#define ListSize 100


// 数据类型
typedef int DataType;


/**
 顺序表
 */
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;


#pragma mark - Utilities


/**
 打印顺序表元素

 @param L 顺序表
 */
void printList(SeqList L);


#pragma mark - Oprations


/**
 在顺序表中插入元素

 @param L 顺序表
 @param i 插入元素的位置
 @param x 需要插入的元素
 @return 如果成功返回0，失败则返回对应的错误码：1 表示 i 不合法；2 表示顺序表溢出
 */
int insertList(SeqList *L, int i, DataType x);


/**
 从顺序表中删除元素

 @param L 顺序表
 @param i 要删除元素的位置
 @param x 将要删除的元素，会保存到此变量
 @return 如果成功返回0，失败则返回对应的错误码：1 表示 i 不合法；
 */
int deleteList(SeqList *L, int i, DataType *x);


/**
 反转顺序表中的元素

 @param L 顺序表
 */
void reverseList(SeqList *L);


/**
 找出顺序表中最大值和最小值

 @param L 顺序表
 @param max 最大值
 @param min 最小值
 @param maxIndex 最大值下标
 @param minIndex 最小值下标
 */
void maxAndMin(SeqList *L, DataType *max, DataType *min, int *maxIndex, int *minIndex);


#endif /* SeqList_h */
