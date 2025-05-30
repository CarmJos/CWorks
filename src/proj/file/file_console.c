#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "commands.c"
#include "file_system.c"

Disk disk;

void sort(FileMeta* files, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (files[j].size < files[j + 1].size) {
                FileMeta temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

bool disk_uninitialized() {
    if (disk.storage == NULL) {
        printf("Disk not initialized. Please run 'init <rows> <cols>' first.\n");
        return true;
    }
    return false;
}

bool cmd_disk_init(char** args, unsigned char length) {
    if (length != 2) return false;

    int tracks, sectors;
    if (sscanf(args[0], "%d", &tracks) != 1 || sscanf(args[1], "%d", &sectors) != 1) {
        printf("Invalid arguments. Please provide valid integers for rows and cols.\n");
        return true;
    }
    if (tracks <= 0 || sectors <= 0) {
        printf("rows and cols must be positive integers.\n");
        return true;
    }

    disk = disk_create(tracks, sectors);
    printf("Disk initialized with %d rows and %d cols.\n", tracks, sectors);
    return true;
}

bool cmd_disk_defragment(char** args, unsigned char length) {
    if (disk_uninitialized()) return true;
    disk_defragment(&disk);
    return true;
}

bool cmd_write(char** args, unsigned char length) {
    if (length < 2) return false;
    if (disk_uninitialized()) return true;
    const char* filename = args[0];
    char content[100] = {0};

    for (unsigned char i = 1; i < length; i++) {
        strncat(content, args[i], 100 - strlen(content) - 1);
        if (i < length - 1) {
            strncat(content, " ", 100 - strlen(content) - 1);
        }
    }

    File exists = file_read(&disk, filename);
    if (exists.meta != NULL) {
        printf("\nFile '%s' already exists with the following content:\n", filename);
        printf("-------------------------------------------------\n");
        printf("%s\n", exists.content);
        printf("-------------------------------------------------\n");
        printf("Overwriting existing file '%s', sure? (y/n)\n", filename);

        // 等待输入 Y 或 y 或 N 或 n，默认为 Y
        char confirm[3];
        fgets(confirm, sizeof(confirm), stdin);
        if (confirm[0] != 'Y' && confirm[0] != 'y') {
            printf("Write operation cancelled.\n");
            return true;
        }
        printf("Overwriting file '%s' with new content.\n", filename);
    }


    FileMeta* wrote = file_write(&disk, filename, content);
    if (wrote != NULL) {
        printf(
            "Wrote file '%s' at position [%d,%d] with size %llu.\n",
            filename, wrote->position.col + 1, wrote->position.row + 1, wrote->size
        );
    }
    else {
        printf("Failed to write file '%s'. No enough space, required %llu.\n", filename, strlen(content));
    }

    return true;
}

bool cmd_delete(char** args, const unsigned char length) {
    if (length < 1) return false;
    if (disk_uninitialized()) return true;
    const char* filename = args[0];
    if (!file_delete(&disk, filename)) {
        printf("File '%s' not found.\n", filename);
    }
    else {
        printf("Successfully deleted file '%s'.\n", filename);
    }
    return true;
}

bool cmd_cat(char** args, const unsigned char length) {
    if (length < 1) return false;
    if (disk_uninitialized()) return true;
    const char* filename = args[0];
    File file = file_read(&disk, filename);
    if (file.content == NULL) {
        printf("File '%s' not found.\n", filename);
    }
    else {
        printf("Contents of '%s':\n%s\n", filename, file.content);
    }
    return true;
}

bool cmd_ls(char** args, unsigned char length) {
    if (disk_uninitialized()) return true;
    if (disk.count == 0) {
        printf("No files found on the disk.\n");
        return true;
    }
    printf("\n[ DATA >--------------------------\n");
    printf(" \t");
    for (int j = 0; j < disk.cols; j++) {
        printf("[%d]\t", j + 1);
    }
    printf("\n");
    for (int i = 0; i < disk.rows; i++) {
        printf("[%d]\t", i + 1);
        for (int j = 0; j < disk.cols; j++) {
            // 如果对应位置是空，则输出 -。
            if (disk.storage[i][j] == 0) {
                printf(" -\t");
            }
            else {
                printf(" %c\t", disk.storage[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n----------------------------------\n");
    printf("strategy=%d , total: %d\n", disk.strategy, disk.count);
    printf("# \t@pos \t@size \t@name \n");


    sort(disk.files, disk.count);
    for (int i = 0; i < disk.count; i++) {
        FileMeta meta = disk.files[i];
        printf(
            "|- \t[%d,%d] \t%llu \t%s \n",
            meta.position.col + 1, meta.position.row + 1,
            meta.size, disk.files[i].name
        );
    }
    return true;
}

bool cmd_disk_strategy(char** args, unsigned char length) {
    if (length != 1) return false;
    if (disk_uninitialized()) return true;

    int strategy;
    if (sscanf(args[0], "%d", &strategy) != 1 || strategy < 0 || strategy > 2) {
        printf("Invalid strategy. Use 0 for first-fit, 1 for best-fit, or 2 for worst-fit.\n");
        return true;
    }

    disk.strategy = (Strategy)strategy;
    printf("Disk strategy changed to %d.\n", strategy);
    return true;
}

int main() {
    register_command(
        cmd_disk_init, "init", "<rows> <cols>",
        "Initialize disk with given size."
    );
    register_command(
        cmd_disk_defragment, "defragment", "",
        "Run defragment once on disk."
    );
    register_command(
        cmd_disk_strategy, "mode", "<strategy, 0=first, 1=best, 2=worst>",
        "Change disk space allocate strategy."
    );
    register_command(
        cmd_write, "w", "<file> [new_content...]",
        "Write contents to file."
    );
    register_command(
        cmd_delete, "rm", "<file>",
        "Delete file from the disk."
    );
    register_command(
        cmd_cat, "cat", "<file>",
        "Read and show file contents."
    );
    register_command(
        cmd_ls, "ls", "",
        "List all files in current disk."
    );

    disk = disk_create(10, 10); // 预先初始化

    console_run("DISK SIMULATION", "console > ");
    return 0;
}
