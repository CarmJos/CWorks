// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2025. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdbool.h>
#include <stdio.h>

#define FRAME_SIZE 4

/**
*  编程实现下述页面置换算法，求出每种算法的缺页中断率，并给出主存内页面变化及页面淘汰情况：
*   1.先进先出算法FIFO
*   2.最近最少用置换算法LRU
*/

// 页面访问次序为7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1，进程分配的页框数为4，
// 输出两个算法的页面置换情况及缺页中断率

void print_frames(const int curr[], int length, int requesting, int dropped);
void fifo(int frame_size, const int seq[], int length);
void lru(int frame_size, const int seq[], int length);

void main() {
    int length;
    int seq[length];


    printf("Sequence length:");
    scanf("%d", &length);

    printf("Sequence:");
    for (int i = 0; i < length; i++) {
        scanf("%d", &seq[i]);
    }

    // FIFO
    fifo(FRAME_SIZE, seq, length);
    // LRU
    lru(FRAME_SIZE, seq, length);
}


void print_frames(const int curr[], const int length, const int requesting, const int dropped) {
    printf("REQUESTING %d | ", requesting);
    printf("FRAMES [ ");
    for (int i = 0; i < length; i++) {
        if (curr[i] >= 0) {
            printf("%d ", curr[i]);
        }
        else {
            printf("X ");
        }
    }
    printf("] DROPPED: ");
    if (dropped >= 0) {
        printf("%d\n", dropped);
    }
    else {
        printf("--\n");
    }
}


void fifo(const int frame_size, const int seq[], const int length) {
    int frames[frame_size];
    int fifo_ptr = 0;
    int page_faults = 0;

    for (int i = 0; i < frame_size; i++)
        frames[i] = -1;

    printf("[ FIFO >-------------------------------\n");
    for (int i = 0; i < length; i++) {
        int page = seq[i];
        bool found = false;
        int replaced_page = -1;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        // 缺页处理
        if (!found) {
            page_faults++;
            if (frames[fifo_ptr] != -1)
                replaced_page = frames[fifo_ptr];
            frames[fifo_ptr] = page;
            fifo_ptr = (fifo_ptr + 1) % frame_size;
        }
        print_frames(frames, frame_size, page, replaced_page);
    }
    printf("[ FIFO > loss: %.2f%%\n\n", (float)page_faults / (float)length * 100);
}

void lru(const int frame_size, const int seq[], const int length) {
    int frames[frame_size]; // 内存页框
    int last_used[frame_size]; // 最后使用时间戳
    int current_time = 0; // 模拟时钟
    int page_faults = 0; // 缺页次数

    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
        last_used[i] = -1; // 初始化时间戳
    }

    printf("[ LRU  >-------------------------------\n");
    for (int i = 0; i < length; i++) {
        int page = seq[i];
        bool found = false;
        int replaced_page = -1;

        // 检查页面是否已在内存
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                found = true;
                last_used[j] = current_time; // 更新使用时间
                break;
            }
        }

        if (!found) {
            page_faults++;
            int replace_idx = -1;
            int min_time = current_time + 1;

            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) { // 有空闲页框
                    replace_idx = j;
                    break;
                }
                if (last_used[j] < min_time) {
                    min_time = last_used[j];
                    replace_idx = j;
                }
            }

            replaced_page = frames[replace_idx]; // 记录被淘汰页
            frames[replace_idx] = page; // 插入新页
            last_used[replace_idx] = current_time;
        }
        current_time++; // 时间递增
        print_frames(frames, frame_size, page, replaced_page);
    }
    printf("[ LRU > loss : %.2f%%\n\n", (float)page_faults / (float)length * 100);
}
