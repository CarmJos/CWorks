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
#include <intrin.h>

// 【处理器调度算法模拟】
// 编程实现下述处理器调度算法，求出每种算法的平均等待时间，并给出各进程调度顺序：
//1.先来先服务算法
//2.时间片轮转算法（默认时间片为3）
//3.最短进程优先算法

typedef struct {
    char name[20]; //进程名称
    int arrive; //到达时间
    int serve; //服务时间
} Process;

void fcfs(Process processes[], int size) {
    int time = 0;
    int wait_time = 0;

    Process order[size]; // 用于记录调度顺序

    for (int i = 0; i < size; i++) {
        if (time < processes[i].arrive) {
            time = processes[i].arrive; // 等待进程到达
        }
        wait_time += time - processes[i].arrive; // 计算等待时间
        time += processes[i].serve; // 更新当前时间
        order[i] = processes[i]; // 记录调度顺序
    }

    printf("# FCFS Schedule \t| avg=%.2f \t| ", (float) wait_time / size);
    for (int i = 0; i < size; i++) {
        printf("%s ", order[i].name); // 输出调度顺序
    }
    printf("\n");
}

void round_robin(Process processes[], int size, int time_slice) {
    int time = 0;
    int wait_time = 0;
    int remaining[size];
    int last_completion[size];  // 记录每个进程上次完成时间
    char results[200] = "";

    for (int i = 0; i < size; i++) {
        remaining[i] = processes[i].serve;
        last_completion[i] = processes[i].arrive;  // 初始化为到达时间
    }

    while (1) {
        bool done = true;
        for (int i = 0; i < size; i++) {
            if (remaining[i] > 0) {
                done = false;

                if (processes[i].arrive <= time) {
                    wait_time += time - last_completion[i];

                    int exec_time = (remaining[i] > time_slice) ? time_slice : remaining[i];
                    time += exec_time;
                    remaining[i] -= exec_time;
                    last_completion[i] = time;  // 更新上次完成时间

                    if (results[0] == '\0') {
                        snprintf(results, sizeof(results), "%s", processes[i].name);
                    } else {
                        snprintf(results + strlen(results), sizeof(results) - strlen(results), " %s",
                                 processes[i].name);
                    }

                } else {
                    time = processes[i].arrive;
                }
            }
        }
        if (done) break;
    }

    printf("# Round Robin Schedule \t| avg=%.2f \t| %s", (float) wait_time / size, results);
    printf("\n");
}

void sjf(Process processes[], int size) {
    int time = 0;
    int wait_time = 0;
    bool completed[size];

    for (int i = 0; i < size; i++) {
        completed[i] = false; // 初始化所有进程为未完成
    }

    Process order[size]; // 用于记录调度顺序

    for (int count = 0; count < size; count++) {
        int min_index = -1;
        int min_serve = 9999;

        for (int i = 0; i < size; i++) {
            if (!completed[i] && processes[i].arrive <= time && processes[i].serve < min_serve) {
                min_serve = processes[i].serve;
                min_index = i; // 找到最短服务时间的进程
            }
        }

        if (min_index == -1) {
            time++; // 如果没有可执行的进程，时间前进
            count--;
            continue;
        }

        wait_time += time - processes[min_index].arrive; // 计算等待时间
        time += processes[min_index].serve; // 更新当前时间
        completed[min_index] = true; // 标记进程为完成
        order[count] = processes[min_index]; // 记录调度顺序
    }

    printf("# SJF Schedule    \t| avg=%.2f \t| ", (float) wait_time / size);
    for (int i = 0; i < size; i++) {
        printf("%s ", order[i].name); // 输出调度顺序
    }
    printf("\n");
}

int main() {
    Process processes[5] = {
            {"001", 0, 3},
            {"002", 2, 6},
            {"003", 4, 4},
            {"004", 6, 5},
            {"005", 8, 2}
    };

    // 先来先服务算法
    fcfs(processes, 5);

    // 时间片轮转算法
    round_robin(processes, 5, 3);

    // 最短进程优先算法
    sjf(processes, 5);

    return 0;
}
