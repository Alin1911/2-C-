#ifndef __FILE_H__
#define __FILE_H__

typedef struct d_list {

struct Directory *dir;
struct d_list *next;

} d_list;

typedef struct f_list {

struct File *file;
struct f_list *next;

} f_list;


typedef struct Directory {

// The name of the directory
char *name;

// TODO: The list of files of the current directory
d_list *directoryy;

// TODO: The list of directories of the current directory
f_list *filee;

// The parent directory of the current directory (NULL for the root directory)
struct Directory *parentDir;

} Directory;

// DO NOT MODIFY THIS STRUCTURE
typedef struct File {

// The name of the file
char *name;

// The size of the file
int size;

// The content of the file
char *data;

// The directory in which the file is located
Directory *dir;

} File;


#endif /* __FILE_H__ */
