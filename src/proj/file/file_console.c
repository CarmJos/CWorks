#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "commands.c"
#include "file_system.c"

Disk disk;

bool disk_uninitialized() {
    if (disk.storage == NULL) {
        printf("Disk not initialized. Please run 'init <tracks> <sectors>' first.\n");
        return false;
    }
    return true;
}

bool cmd_disk_init(char** args, unsigned char length) {
    if (length != 2) return false;

    int tracks, sectors;
    if (sscanf(args[1], "%d", &tracks) != 1 || sscanf(args[2], "%d", &sectors) != 1) {
        printf("Invalid arguments. Please provide valid integers for tracks and sectors.\n");
        return true;
    }
    if (tracks <= 0 || sectors <= 0) {
        printf("Tracks and sectors must be positive integers.\n");
        return true;
    }

    disk = disk_create(tracks, sectors);
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
    const char* filename = args[1];
    char content[MAX_FILE_SIZE] = {0};

    for (unsigned char i = 2; i < length; i++) {
        strncat(content, args[i], MAX_FILE_SIZE - strlen(content) - 1);
        if (i < length - 1) {
            strncat(content, " ", MAX_FILE_SIZE - strlen(content) - 1);
        }
    }

    file_write(&disk, filename, content);
    return true;
}

bool cmd_delete(char** args, const unsigned char length) {
    if (length < 1) return false;
    if (disk_uninitialized()) return true;
    const char* filename = args[1];
    if (!file_delete(&disk, filename)) {
        printf("File '%s' not found.\n", filename);
    }
    else {
        printf("Successfully deleted file '%s'.\n", filename);
    }
}

bool cmd_cat(char** args, const unsigned char length) {
    if (length < 1) return false;
    if (disk_uninitialized()) return true;
    const char* filename = args[1];
    File* file = file_read(&disk, filename);
    if (file == NULL) {
        printf("File '%s' not found.\n", filename);
    }
    else {
        printf("Contents of '%s':\n%s\n", filename, file->content);
    }
    return true;
}

bool cmd_ls(char** args, unsigned char length) {
    if (disk_uninitialized()) return true;
    FileList file_list = files(&disk);
    if (file_list.length == 0) {
        printf("No files found on the disk.\n");
        return true;
    }
    printf("\n");
    printf("total: %d\n", file_list.length);
    for (int i = 0; i < file_list.length; i++) {
        printf("|- %d\t %s \n", file_list.files[i].size, file_list.files[i].name);
    }
    return true;
}

int main() {
    register_command(
        cmd_disk_init, "init", "<tracks> <sectors>",
        "Initialize disk with given size."
    );
    register_command(
        cmd_disk_defragment, "defragment", "",
        "Run defragment once on disk."
    );
    register_command(
        cmd_write, "write", "<file> [new_content...]",
        "Write contents to file."
    );
    register_command(
        cmd_delete, "del", "<file>",
        "Delete file from the disk."
    );
    register_command(
        cmd_cat, "cat", "<file>",
        "Show file contents."
    );
    register_command(
        cmd_ls, "ls", "",
        "List all files in current disk."
    );

    console_run("DISK", "disk > ");
    return 0;
}
