struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;

hashtable_t *ht_create( int  );
int ht_hash( hashtable_t *, char * );
entry_t *ht_newpair( char *, char * );
void ht_set( hashtable_t *, char *, char * );
char *ht_get( hashtable_t *, char * );
int main( int , char ** );
