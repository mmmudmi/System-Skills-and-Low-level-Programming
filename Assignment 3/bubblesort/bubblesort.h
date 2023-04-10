#define MAX_NAME_LENGTH 30

typedef struct EntryStruct {
    int data;
    char *name;
} Entry;

void sort(Entry *in, int nL, void *comparator);
int compare(Entry a, Entry b);
