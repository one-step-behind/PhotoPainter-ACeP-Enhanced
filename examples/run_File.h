#ifndef _RUN_FILE_H_
#define _RUN_FILE_H_

#include "DEV_Config.h"
#include <stdbool.h> // For bool type
#include <stdint.h>  // For uint32_t, size_t

#define fileNumber 100
#define fileLen 100

// Settings structure
typedef struct
{
    int mode;         // Display mode (0-3)
    int timeInterval; // Time interval in minutes
    int currentIndex; // Current image index
    int refreshCycles; // Refresh cycles the display had
} Settings_t;

// Cycle state structure for affine permutation (Mode 3 randomization)
typedef struct
{
    unsigned long crc;  // CRC32 of fileList.txt at cycle start
    unsigned int N;      // Total number of image files
    unsigned int i;      // Iteration counter (0 to N-1)
    unsigned int a;      // Multiplicative coefficient (coprime with N)
    unsigned int b;      // Additive offset (0 to N-1)
} CycleState;

char sdTest(void);
void sdInitTest(void);

void run_mount(void);
void run_unmount(void);

void file_cat(void);

void sdScanDir(void);

char isFileExist(const char *path);
void setFilePath(void);

void updatePathIndex(void);
void file_sort();

// CRC32 and affine permutation functions for Mode 3
unsigned long crc32_file(const char *path);
unsigned int findCoprime(unsigned int N);
unsigned int getAffinePermutationIndex(CycleState *state);
int getNextImageIndex(void);

// Cycle state file functions
char loadCycleState(CycleState *state);
void saveCycleState(const CycleState *state);
void createDefaultCycleState(CycleState *state, unsigned long fileListCrc, unsigned int fileCount);

// Settings file functions
char loadSettings(Settings_t *settings);
void saveSettings(Settings_t *settings);
void createDefaultSettings(void);

#endif
