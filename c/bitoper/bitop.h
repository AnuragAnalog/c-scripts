/********* FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};

int menu();

unsigned set2bit(FILE *fp1, char *file1);
void print_bits(unsigned seta);
int bit2set(unsigned setc);

unsigned setbit(unsigned x, int p);
unsigned getbit(unsigned x, int p);
unsigned clearbit(unsigned x, int p);
enum boolean isbitset(unsigned x, int p);
unsigned union_bit(unsigned x, unsigned x1);
unsigned inter_bit(unsigned x, unsigned x1);
enum boolean membership_bit(unsigned x, int num);
unsigned diff_bit(unsigned x, unsigned x1);

/********* DEFINED CONSTANTS ********/
#define   MAX        32
