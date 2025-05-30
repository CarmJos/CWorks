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


#include "file_system.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

Disk disk_create(const int rows, const int cols) {
    Disk disk = {0}; // 初始化所有字段为0
    disk.rows = rows;
    disk.cols = cols;
    disk.count = 0;
    disk.strategy = FIRST_IN;

    disk.storage = (char**)malloc(rows * sizeof(char*));
    if (disk.storage == NULL) return disk;
    for (int i = 0; i < rows; i++) {
        disk.storage[i] = (char*)calloc(cols, sizeof(char));
    }

    disk.files = (FileMeta*)malloc(MAX_FILE_COUNT * sizeof(FileMeta));

    return disk;
}

void disk_write(Disk* disk, int row_start, int col_start, const char* content, const size_t size) {
    if (disk == NULL || disk->storage == NULL || content == NULL) {
        return; // 未初始化的磁盘
    }

    const int total_pos = row_start * disk->cols + col_start;
    const int total_size = disk->rows * disk->cols;

    for (int i = 0; i < size && total_pos + i < total_size; i++) {
        int curr_row = (total_pos + i) / disk->cols;
        int curr_col = (total_pos + i) % disk->cols;
        disk->storage[curr_row][curr_col] = content[i];
    }
}

Position allocate_first(char** storage, const int rows, const int cols, const size_t required) {
    const int total_size = rows * cols;
    Position pos = {-1, -1};

    for (int i = 0; i < total_size; i++) {
        int row = i / cols;
        int col = i % cols;

        int available = 0;
        for (int j = i; j < total_size && available < required; j++) {
            if (storage[j / cols][j % cols] != '\0') {
                break;
            }
            available++;
        }
        if (available >= required) {
            pos.row = row;
            pos.col = col;
            return pos;
        }
    }
    return pos;
}

Position allocate_best(char** storage, const int rows, const int cols, const size_t required) {
    const int total_size = rows * cols;

    Position pos = {-1, -1};
    int best_size = rows * cols + 1;

    int i = 0;
    while (i < total_size) {
        int row = i / cols;
        int col = i % cols;

        if (storage[row][col] == '\0') {
            int available = 0;
            for (int j = i; j < total_size; j++) {
                if (storage[j / cols][j % cols] != '\0' || j + 1 == total_size) {
                    i = j;
                    break;
                }
                available++;
            }

            if (available >= required && available < best_size) {
                best_size = available;
                pos.row = row;
                pos.col = col;
            }
        }

        i++;
    }
    return pos;
}

Position allocate_worst(char** storage, const int rows, const int cols, const size_t required) {
    const int total_size = rows * cols;
    Position pos = {-1, -1};
    int worst_size = 0;

    int i = 0;
    while (i < total_size) {
        int row = i / cols;
        int col = i % cols;

        if (storage[row][col] == '\0') {
            int available = 0;
            for (int j = i; j < total_size; j++) {
                if (storage[j / cols][j % cols] != '\0' || j + 1 == total_size) {
                    i = j;
                    break;
                }
                available++;
            }

            if (available >= required && available > worst_size) {
                worst_size = available;
                pos.row = row;
                pos.col = col;
            }
        }

        i++;
    }
    return pos;
}

Position disk_allocate(const Disk* disk, const size_t required) {
    if (disk == NULL || disk->storage == NULL || required <= 0) {
        return (Position){-1, -1}; // 未初始化的磁盘或无效大小
    }
    switch (disk->strategy) {
    case FIRST_IN:
        return allocate_first(disk->storage, disk->rows, disk->cols, required);
    case BEST_IN:
        return allocate_best(disk->storage, disk->rows, disk->cols, required);
    case WORST_IN:
        return allocate_worst(disk->storage, disk->rows, disk->cols, required);
    default:
        return (Position){-1, -1};
    }
}

FileMeta* file_find(const Disk* disk, const char* filename) {
    if (disk == NULL || filename == NULL) return NULL;

    for (int i = 0; i < disk->count; i++) {
        if (strcmp(disk->files[i].name, filename) == 0) {
            return &disk->files[i];
        }
    }

    return NULL;
}

FileMeta* file_write(Disk* disk, const char* filename, const char* content) {
    if (disk == NULL || disk->storage == NULL || filename == NULL || content == NULL) {
        return NULL; // 未初始化的磁盘
    }
    if (disk->count >= MAX_FILE_COUNT) return NULL; // 文件数量超出限制

    // 计算所需空间
    size_t content_len = strlen(content);
    int total_space = disk->rows * disk->cols;

    if (content_len > total_space) { // 检查文件大小是否超过总空间
        return NULL; // 文件太大，超过磁盘总容量
    }

    FileMeta* exists = file_find(disk, filename); // 检查文件是否已存在
    if (exists) { // 如果文件已存在，先删除旧文件
        file_delete(disk, filename);
    }

    // 分配空间
    Position pos = disk_allocate(disk, content_len);
    if (pos.row == -1 || pos.col == -1) return NULL; // 没有足够的连续空间

    // 创建新的文件元数据
    FileMeta new_file;
    strncpy(new_file.name, filename, MAX_FILE_NAME_LENGTH - 1);
    new_file.name[MAX_FILE_NAME_LENGTH - 1] = '\0';
    new_file.position = pos;
    new_file.size = content_len;

    // 写入内容
    disk_write(disk, pos.row, pos.col, content, content_len);

    // 添加到文件列表
    disk->files[disk->count] = new_file;
    disk->count++;

    return &disk->files[disk->count - 1];
}

File file_read(const Disk* disk, const char* filename) {
    File result = {NULL, NULL};
    if (disk == NULL || disk->storage == NULL || filename == NULL) {
        return result;
    }

    FileMeta* meta = file_find((Disk*)disk, filename);
    if (meta == NULL) {
        return result;
    }

    // 分配内存并读取内容
    result.meta = meta;
    result.content = (char*)malloc(meta->size + 1); // +1 for null terminator
    if (result.content == NULL) {
        return result;
    }

    // 从存储中读取内容
    int total_pos = meta->position.row * disk->cols + meta->position.col;
    for (int i = 0; i < meta->size; i++) {
        int curr_row = (total_pos + i) / disk->cols;
        int curr_col = (total_pos + i) % disk->cols;
        result.content[i] = disk->storage[curr_row][curr_col];
    }
    result.content[meta->size] = '\0'; // 添加字符串结束符

    return result;
}

bool file_delete(Disk* disk, const char* filename) {
    if (disk == NULL || disk->storage == NULL || filename == NULL) {
        return false;
    }

    FileMeta* meta = file_find(disk, filename);
    if (meta == NULL) {
        return false;
    }

    // 清除存储空间
    int total_pos = meta->position.row * disk->cols + meta->position.col;
    for (int i = 0; i < meta->size; i++) {
        int curr_row = (total_pos + i) / disk->cols;
        int curr_col = (total_pos + i) % disk->cols;
        disk->storage[curr_row][curr_col] = '\0';
    }

    // 从文件列表中移除
    int index = meta - disk->files;
    for (int i = index; i < disk->count - 1; i++) {
        disk->files[i] = disk->files[i + 1];
    }
    disk->count--;

    return true;
}

void disk_defragment(Disk* disk) {
    if (disk == NULL || disk->storage == NULL) {
        return;
    }

    // 临时存储所有文件内容
    char** temp_contents = malloc(disk->count * sizeof(char*));
    if (temp_contents == NULL) return;

    // 保存所有文件内容
    for (int i = 0; i < disk->count; i++) {
        const FileMeta* meta = &disk->files[i];
        temp_contents[i] = (char*)malloc(meta->size);

        if (temp_contents[i] == NULL) {
            // 清理已分配的内存
            for (int j = 0; j < i; j++) {
                free(temp_contents[j]);
            }
            free(temp_contents);
            return;
        }

        // 复制文件内容
        int total_pos = meta->position.row * disk->cols + meta->position.col;
        for (int j = 0; j < meta->size; j++) {
            int curr_row = (total_pos + j) / disk->cols;
            int curr_col = (total_pos + j) % disk->cols;
            temp_contents[i][j] = disk->storage[curr_row][curr_col];
        }
    }

    // 清空所有存储空间
    for (int i = 0; i < disk->rows; i++) {
        memset(disk->storage[i], 0, disk->cols);
    }

    // 从头开始重新写入所有文件
    int current_pos = 0;

    for (int i = 0; i < disk->count; i++) {
        FileMeta* meta = &disk->files[i];

        // 更新文件位置
        meta->position.row = current_pos / disk->cols;
        meta->position.col = current_pos % disk->cols;

        // 重新写入文件内容
        disk_write(disk, meta->position.row, meta->position.col, temp_contents[i], meta->size);

        // 更新下一个文件的起始位置
        current_pos += meta->size;
    }

    // 清理临时存储
    for (int i = 0; i < disk->count; i++) {
        free(temp_contents[i]);
    }
    free(temp_contents);
}
