#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <libgen.h>
#include "extension.h"

// create directory if it does not exist
void check_and_create_dir(char *dir, int dry_run)
{
    if (dry_run)
    {
        printf("Would create directory: %s\n", dir);
        return;
    }
    struct stat st = {0};
    if (stat(dir, &st) == -1)
    {
        mkdir(dir, 0700);
    }
}

// move file to directory
void move_file(char *old_dir, char *new_dir, char *file_name, int dry_run)
{
    char old_path[1024];
    char new_path[1024];

    snprintf(old_path, sizeof(old_path), "%s/%s", old_dir, file_name);
    snprintf(new_path, sizeof(new_path), "%s/%s", new_dir, file_name);

    if (dry_run)
    {
        printf("Would Move: \"%s\" -> \"%s\"\n", old_path, new_path);
        return;
    }
    // Rename for moving
    if (rename(old_path, new_path) != 0)
    {
        perror("Error moving file");
    }
}

int main(int argc, char *argv[])
{
    clock_t start, end; // Variables for timing
    double cpu_time_used;
    start = clock(); // Start the timer

    // Extract the executable name
    char executable_name[1024];
    snprintf(executable_name, sizeof(executable_name), "%s.exe", basename(argv[0]));

    int dry_run = 1; // Flag to indicate dry run mode
    printf("Do you want to perform a dry run? (yes/no): ");
    char answer[10];
    if (scanf("%9s", answer) == 1)
    {
        // Only perform actual file moving if the user explicitly types "no" or "n"
        if (strcmp(answer, "no") == 0 || strcmp(answer, "n") == 1)
        {
            dry_run = 0;
        }
    }
    getchar(); // consume the newline character after scanf
    // Runs in the folder that its at.
    DIR *folder = opendir(".");
    char *current_path = getcwd(NULL, 0);
    if (folder == NULL)
    {
        perror("Unable to open directory");
        return 1;
    }
    struct dirent *entry;
    char full_path[1024];
    while ((entry = readdir(folder)) != NULL)
    {
        // Skip if the file is the executable itself
        if (strcmp(entry->d_name, basename(argv[0])) == 0 || strcmp(entry->d_name, executable_name) == 0)
        {
            continue;
        }
        // constructs the full path, and stores it on the full_path var
        snprintf(full_path, sizeof(full_path), "%s/%s", current_path, entry->d_name);
        // Use stat to get file info
        struct stat file_info;
        // The stat function returns 0 on success,
        // meaning it successfully retrieved the information and stored it in fileInfo.
        if (stat(full_path, &file_info) == 0)
        {
            if (S_ISREG(file_info.st_mode))
            { // Check if it's a regular file
                char *dot = strrchr(entry->d_name, '.');
                if (dot && dot != entry->d_name)
                { // Check if filename contains an extension
                    char new_dir_path[1024];
                    const char *group_dir = get_group_directory(dot);
                    if (group_dir)
                    {
                        snprintf(new_dir_path, sizeof(new_dir_path), "%s/%s", current_path, group_dir);
                    }
                    else
                    {
                        snprintf(new_dir_path, sizeof(new_dir_path), "%s/%s", current_path, dot + 1); // Use extension as directory name
                    }
                    check_and_create_dir(new_dir_path, dry_run);
                    move_file(current_path, new_dir_path, entry->d_name, dry_run);
                }
            }
        }
    }
    end = clock(); // End the timer
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds. Press any key to exit...", cpu_time_used);
    getchar();
    return 0;
}