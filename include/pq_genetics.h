#ifndef pq_genetics_h__
#define pq_genetics_h__

extern void pq_complement(char *codon);
extern void pq_dna_upper(char *codon);
extern void pq_reverse(char *codon);
extern unsigned int pq_alldna(const char *dna);

extern struct rwkHashTable CODON_TO_NSYN;
extern struct rwkHashTable CODON_TO_AMINO;

extern void file2charHash(char *fname, int hsize);
extern void file2doubleHash(char *fname, int hsize);

#endif
