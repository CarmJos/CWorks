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

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define DISK_SIZE 200
#define TRACK_LENGTH 9

// 编程实现下述磁盘调度算法，并求出每种算法的平均寻道长度，并给出调度顺序；
// 要求在主界面中灵活选择调度算法，要求实现以下磁盘调度算法：
// 1.先来先服务FCFS
// 2.最短寻道时间优先SSTF
// 3.扫描算法SCAN（默认方向由小至大）
// 4.循环扫描算法CSCAN（默认方向由小至大）
// 用户输入当前磁头位置及后续的磁道请求顺序（9个），依次按行输出各算法的执行情况，例如：
// 磁头位置：100
// 请求磁道：55 58 39 18 90 160 150 38 184
// FCFS：55 58 39 18 90 160 150 38 184 | 55.3
// SSTF：90 58 55 39 38 18 150 160 184 | 27.5
// SCAN：150 160 184 90 58 55 39 38 18 | 27.8
// CSCAN：150 160 184 18 38 39 55 58 90 | 35.8

int abs_diff(const int a, const int b) {
    return abs(a - b);
}

// 先来先服务（First-Come, First-Served, FCFS）是最简单的磁盘调度算法，按照请求到达的顺序依次处理，公平但效率低下。
void fcfs(int head, const int requests[], const int size) {
    int cost = 0;
    printf("FCFS: ");
    for (int i = 0; i < size; i++) {
        cost += abs_diff(head, requests[i]);
        head = requests[i];
        printf("%d ", requests[i]);
    }
    printf("| cost=%d, avg=%.1f\n", cost, (float)cost / (float)size);
}

// SSTF（Shortest Seek Time First）调度每次选择与当前磁头位置距离最近的请求，以最小化寻道时间。
void sstf(int head, const int requests[], const int size) {
    int cost = 0;
    int remaining[size];
    int remaining_count = size;

    // Copy requests to remaining array
    for (int i = 0; i < size; i++) {
        remaining[i] = requests[i];
    }

    printf("SSTF: ");
    for (int i = 0; i < size; i++) {
        int min_diff = 99999; // Initialize with a large value
        int closest_index = -1;

        // Find the closest request
        for (int j = 0; j < remaining_count; j++) {
            int diff = abs_diff(head, remaining[j]);
            if (diff < min_diff) {
                min_diff = diff;
                closest_index = j;
            }
        }

        cost += min_diff;
        head = remaining[closest_index];
        printf("%d ", head);

        // Remove the serviced request from remaining array
        for (int k = closest_index; k < remaining_count - 1; k++) {
            remaining[k] = remaining[k + 1];
        }
        remaining_count--;
    }

    printf("| cost=%d, avg=%.1f\n", cost, (float)cost / (float)size);
}

// SCAN 算法将磁臂从一端移动至另一端，在沿途处理所有请求，然后反向继续处理，如电梯般来回移动。
void scan(int head, const int requests[], const int size, const int disk_size) {
    int cost = 0;
    int schedule[size + 2]; // Add 2 for the extreme ends
    int sorted_requests[size];

    // Copy requests to sorted array and sort it
    for (int i = 0; i < size; i++) {
        sorted_requests[i] = requests[i];
    }

    // Sort the requests (ascending order)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    int index = 0;
    while (index < size && sorted_requests[index] < head) {
        index++;
    }

    int schedule_index = 0;
    printf("SCAN: ");

    // Move from head to the end of the disk
    for (int i = index; i < size; i++) {
        cost += abs_diff(head, sorted_requests[i]);
        head = sorted_requests[i];
        schedule[schedule_index++] = head;
    }

    // Move to the other end (0) and service remaining requests
    cost += abs_diff(head, 0);
    head = 0;
    schedule[schedule_index++] = head;

    for (int i = index - 1; i >= 0; i--) {
        cost += abs_diff(head, sorted_requests[i]);
        head = sorted_requests[i];
        schedule[schedule_index++] = head;
    }

    // Print the schedule
    for (int i = 0; i < size; i++) {
        printf("%d ", schedule[i]);
    }

    printf("| cost=%d, avg=%.1f\n", cost, (float)cost / (float)size);
}

// C-SCAN（Circular SCAN）与 SCAN 类似，但在到达一端后不反向，而是直接返回起始端再开始新一轮扫描。
void cscan(int head, const int requests[], const int size, const int disk_size) {
    int cost = 0;
    int schedule[size + 1]; // Add 1 for the end of the disk
    int sorted_requests[size];

    // Copy requests to sorted array and sort it
    for (int i = 0; i < size; i++) {
        sorted_requests[i] = requests[i];
    }

    // Sort the requests (ascending order)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    int index = 0;
    while (index < size && sorted_requests[index] < head) {
        index++;
    }

    int schedule_index = 0;
    printf("CSCAN: ");

    // Move from head to the end of the disk
    for (int i = index; i < size; i++) {
        cost += abs_diff(head, sorted_requests[i]);
        head = sorted_requests[i];
        schedule[schedule_index++] = head;
    }

    // Move to the beginning of the disk (0) without servicing requests
    cost += abs_diff(head, disk_size - 1);
    head = 0;
    schedule[schedule_index++] = head;

    // Service remaining requests from the beginning
    for (int i = 0; i < index; i++) {
        cost += abs_diff(head, sorted_requests[i]);
        head = sorted_requests[i];
        schedule[schedule_index++] = head;
    }

    // Print the schedule
    for (int i = 0; i < size; i++) {
        printf("%d ", schedule[i]);
    }

    printf("| cost=%d, avg=%.1f\n", cost, (float)cost / (float)size);
}

int main() {
    int head, algorithm;
    int n = TRACK_LENGTH;

    printf("disk start:");
    scanf("%d", &head);

    int requests[n];
    printf("Requests tracks (%d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    while (1) {
        printf("\n");
        printf("Choose algorithm (1=FCFS,2=SSTF,3=SCAN,4=CSCAN): ");
        scanf("%d", &algorithm);
        switch (algorithm) {
        case 1:
            fcfs(head, requests, n);
            break;
        case 2:
            sstf(head, requests, n);
            break;
        case 3:
            scan(head, requests, n, DISK_SIZE);
            break;
        case 4:
            cscan(head, requests, n, DISK_SIZE);
            break;
        case 0:
            exit(0);
        }
    }
}
