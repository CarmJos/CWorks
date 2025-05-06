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

// 【生产者-消费者问题】
// 有3个生产者A、B、C和2个消费者D、E，共享一段容量为2的缓冲区。
// 随机选取A~E进行生产或消费，通过信号量解决进程同步及互斥问题，打印进程的活动情况。
// 例如：
// - 生产者B生产1个产品
// - 生产者C生产1个产品
// - 消费者E消耗1个产品
// - 生产者B生产1个产品
// - ...

#define DELAY 1000  // in ms
#define PRODUCERS 3
#define CONSUMERS 2

sem_t empty, full, mutex;
int buffer_count = 0;

void print_action(bool producer, char name) {
    printf(
        "[%s] %c %s 1 product (current=%d)\n",
        producer ? "Producer" : "Consumer",
        name,
        producer ? "+" : "-",
        buffer_count
    );
}

void* producer(void* arg) {
    char name = *(char*)arg;
    free(arg);
    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer_count++;
        print_action(true, name);

        sem_post(&mutex);
        sem_post(&full);
        usleep(DELAY * 1000);
    }
}

void* consumer(void* arg) {
    char name = *(char*)arg;
    free(arg);
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        buffer_count--;
        print_action(false, name);

        sem_post(&mutex);
        sem_post(&empty);
        usleep(DELAY * 1000);
    }
}

int main() {
    pthread_t producers[PRODUCERS], consumers[CONSUMERS];

    // 初始化信号量
    sem_init(&empty, 0, 2); // 缓冲区初始容量2
    sem_init(&full, 0, 0); // 初始产品数量0
    sem_init(&mutex, 0, 1); // 互斥锁

    // 创建生产者线程
    for (int i = 0; i < PRODUCERS; i++) {
        char* name = malloc(sizeof(char));
        *name = 'A' + i;
        pthread_create(&producers[i], NULL, producer, name);
    }

    // 创建消费者线程
    for (int i = 0; i < CONSUMERS; i++) {
        char* name = malloc(sizeof(char));
        *name = 'D' + i;
        pthread_create(&consumers[i], NULL, consumer, name);
    }

    while (1) { sleep(3600); }

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}
