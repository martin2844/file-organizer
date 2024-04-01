#include "extension.h"
#include <string.h>
#include <strings.h>

const char *get_group_directory(const char *extension)
{
    // Image files
    if (strcasecmp(extension, ".png") == 0 || strcasecmp(extension, ".jpg") == 0 ||
        strcasecmp(extension, ".jpeg") == 0 || strcasecmp(extension, ".gif") == 0)
    {
        return "images";
    }
    // Spreadsheet files
    else if (strcasecmp(extension, ".xls") == 0 || strcasecmp(extension, ".xlsx") == 0)
    {
        return "spreadsheets";
    }
    // Slide presentation files
    else if (strcasecmp(extension, ".ppt") == 0 || strcasecmp(extension, ".pptx") == 0)
    {
        return "slides";
    }
    // Archive files
    else if (strcasecmp(extension, ".zip") == 0 || strcasecmp(extension, ".rar") == 0 ||
             strcasecmp(extension, ".7z") == 0 || strcasecmp(extension, ".tar") == 0 ||
             strcasecmp(extension, ".gz") == 0)
    {
        return "archives";
    }
    // Document files
    else if (strcasecmp(extension, ".pdf") == 0 || strcasecmp(extension, ".doc") == 0 ||
             strcasecmp(extension, ".docx") == 0 || strcasecmp(extension, ".txt") == 0)
    {
        return "documents";
    }
    // Video files
    else if (strcasecmp(extension, ".mp4") == 0 || strcasecmp(extension, ".mkv") == 0 ||
             strcasecmp(extension, ".avi") == 0 || strcasecmp(extension, ".mov") == 0)
    {
        return "videos";
    }
    // Audio files
    else if (strcasecmp(extension, ".mp3") == 0 || strcasecmp(extension, ".wav") == 0 ||
             strcasecmp(extension, ".aac") == 0)
    {
        return "audio";
    }
    // If no predefined group is found
    else
    {
        return NULL;
    }
}