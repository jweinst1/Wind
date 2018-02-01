#ifndef INT_MAP_H
#define INT_MAP_H
// Header that contains specialized integer map structure
// Maps arrays or sequences of chars to an integer, or essentially a slot.
// Will be used in  process compiler.

// Controls the max length of recordable names
#define INT_MAP_NAME_LEN 51
// Controls the max size of the internal list
#define INT_MAP_LST_LEN 10

// Represents a failure value, if an add call is attempted on a full map.
#define INT_MAP_BAD (INT_MAP_LST_LEN + 1)

// Macro that initializes an IntMap
#define IntMap_INIT(varName) \
        IntMap varName; \
        varName.count = 0; \
        for(int i = 0; i< INT_MAP_LST_LEN; i++) { \
                varName.items[i].name[0] = '\0'; \
        }

//represents a node in the map.
// The position of the node or it's index is the int it maps to.
typedef struct
{
        char name[INT_MAP_NAME_LEN];
} IntMapNode;

// The actual map structure.
typedef struct
{
        IntMapNode items[INT_MAP_LST_LEN];
        int count;
} IntMap;

// Inserts new string into map
unsigned char IntMap_add(IntMap* imap, const char* string);





#endif
