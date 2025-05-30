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


#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#define MAX_FILE_NAME_LENGTH 10
#define MAX_FILE_COUNT 32

#include <stdbool.h>
#include <stdio.h>

typedef enum {
    FIRST_IN, BEST_IN, WORST_IN
} Strategy;

typedef struct {
    int row, col;
} Position;

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    Position position;
    size_t size;
} FileMeta;

typedef struct {
    char **storage; // Storage matrix(rows, cols).
    int rows, cols;

    FileMeta *files;
    int size; // Stored file size.

    Strategy strategy; // Storage strategy.
} Disk;

typedef struct {
    FileMeta *meta;
    char *content;
} File;

/**
 *  Initialize a disk with the specified number of tracks and sectors
 * @param rows Matrix storage in x-dimension
 * @param cols Matrix storage in y-dimension
 */
Disk disk_create(int rows, int cols);

/**
 * Defragment the disk by merging adjacent free sectors
 *
 * @param disk The disk to defragment
 */
void disk_defragment(Disk *disk);

/**
 * Write contents (could be empty) to specific file in disk.
 * @param disk The disk to write files
 * @param filename The file name
 * @param content File contents
 * @return Written file pointer
 */
FileMeta *file_write(Disk *disk, const char *filename, const char *content);

/**
 * Find fine with specific name in disk
 * @param disk The disk
 * @param filename The file name to find
 * @return FileMeta, {@link NULL} if file not exists.
 */
FileMeta *file_find(const Disk *disk, const char *filename);

/**
 * Check if file exists in disk
 * @param disk The disk
 * @param filename The file name
 * @return true if file exists.
 */
inline bool file_exists(Disk *disk, const char *filename) {
    return file_find(disk, filename) != NULL;
}

/**
 * Read specific file from  the disk
 * @param disk  The disk
 * @param filename The file name
 * @return File pointer, {@link NULL} if file not exists.
 */
File file_read(const Disk *disk, const char *filename);

/**
 * Delete specific file from the disk.
 * @param disk   The disk
 * @param filename  The file name
 * @return Result, false if file not exists.
 */
bool file_delete(Disk *disk, const char *filename);


#endif
