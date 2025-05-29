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


char* str_ndup(const char* s, size_t n) {
    if (s == NULL) return NULL;
    size_t len = 0;
    while (len < n && s[len] != '\0') len++; // 计算实际长度
    char* dup = malloc(len + 1);
    if (dup) {
        memcpy(dup, s, len);
        dup[len] = '\0';
    }
    return dup;
}

Disk disk_create(const int rows, const int cols) {
    Disk disk;
    disk.rows = rows;
    disk.cols = cols;
    disk.free_blocks = rows * cols;
    disk.storage = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        disk.storage[i] = malloc(cols * BLOCK_SIZE);
        memset(disk.storage[i], 0, cols * BLOCK_SIZE); // 初始化为0
    }
    return disk;
}

void disk_defragment(Disk* disk) {}

void disk_export(const Disk* disk, const char* filepath) {
    if (disk == NULL || disk->storage == NULL || filepath == NULL) {
        return; // Invalid disk or filepath
    }
    FILE* file = fopen(filepath, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return; // Failed to open file
    }
    for (int i = 0; i < disk->rows; i++) {
        for (int j = 0; j < disk->cols; j++) {
            fprintf(file, "%c ", disk->storage[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void disk_import(const Disk* disk, const char* filepath) {
    // 从指定txt文件导入数据到 Disk的 matrix_space
    if (disk == NULL || disk->storage == NULL || filepath == NULL) {
        return; // Invalid disk or filepath
    }
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return; // Failed to open file
    }
    for (int i = 0; i < disk->rows; i++) {
        for (int j = 0; j < disk->cols; j++) {
            fscanf(file, "%c ", &disk->storage[i][j]);
        }
    }
    fclose(file);
}


FileMeta* file_find(const Disk* disk, const char* filename) {
    if (disk == NULL || disk->storage == NULL || filename == NULL) {
        return NULL; // Uninitialized disks.
    }

    for (int x = 0; x < disk->rows; x++) {
        for (int y = 0; y < disk->cols; y++) {
            FileMeta* meta = (FileMeta*)(disk->storage[x] + y * BLOCK_SIZE);
            if (meta->name[0] != 0 && strcmp(meta->name, filename) == 0) {
                return meta;
            }
        }
    }
    return NULL; // Not found
}

void disk_write(Disk* disk, short row_start, short col_start, const char* content) {
    if (disk == NULL || disk->storage == NULL || content == NULL) {
        return; // Uninitialized disks.
    }
    if (row_start < 0 || row_start >= disk->rows
        || col_start < 0 || col_start >= disk->cols) {
        return; // Invalid position
    }

    char* block = disk->storage[row_start] + col_start * BLOCK_SIZE;
    strncpy(block, content, BLOCK_SIZE - 1); // Write content to the block
    block[BLOCK_SIZE - 1] = '\0'; // Ensure null-termination
}

Position _disk_allocate(Disk* disk, int size) {
    if (disk == NULL || disk->storage == NULL || size <= 0) {
        return (Position){-1, -1}; // Uninitialized disks or invalid size.
    }

    // 依照 disk 的存储策略，寻找合适的空闲位置。
}


FileMeta* file_write(Disk* disk, const char* filename, const char* content) {
    if (disk == NULL || disk->storage == NULL || filename == NULL || content == NULL) {
        return NULL; // Uninitialized disks.
    }
    if (disk->size >= MAX_FILE_SIZE) return NULL; // ERROR

    // 检查文件是否已存在
    FileMeta* exists = file_find(disk, filename);
    if (exists) {
        // 如果文件已存在
        
    }
}

File file_read(const Disk* disk, const char* filename) {}

bool file_delete(Disk* disk, const char* filename) {}
