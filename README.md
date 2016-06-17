# Population and Quantitative Genetic Tools

##### pq-theta
*Calculate site frequency based stats*

```bash
... | pq-theta nsam [OPTIONS]

Input:
chr    start    end    name    nref    nalt

Output:
chr    region.start    region.end    name    nsam    nsites    seg.sites    thetaW    thetaPi    tajD

OPTIONS

  -b <bool>
    takes values 0 or 1, indicating whether theta values should be 
    give per base pair or summed over the entire region. [1]
  
  -f <int>
    column number (1-indexed) of the factor over which 
    the stats should be calculated. The default is to output 
    stats per chromosome, but the fourth name column could 
    be used instead to calculate over some group of features. [1]

```

##### pq-dna2codon
*Convert nucleotide sequences into codons*

```bash
... | pq-dna2codon

Input:
chr    start    end    name    score    +|-    nuc.1    nuc.2 ... nuc.n

Output:
chr    codon.start    codon.end    name    score    +|-    codon.1    codon.2 ... codon.n    
```

Example input:
```bash
chr1      676151  676152  transcript1       0.65   +       A       A
chr1      676152  676153  transcript1       0.65   +       T       T
chr1      676153  676154  transcript1       0.65   +       G       G
chr1      676154  676155  transcript1       0.65   +       T       T
chr1      676155  676156  transcript1       0.65   +       C       C
chr1      676156  676157  transcript1       0.65   +       G       G
chr1      676157  676158  transcript1       0.65   +       A       A
chr1      676158  676159  transcript1       0.65   +       C       C
chr1      676159  676160  transcript1       0.65   +       G       A
```
Example output:
```bash
chr1      676151  676154  transcript1       0.65   +       ATG     ATG
chr1      676154  676157  transcript1       0.65   +       TCG     TCG
chr1      676157  676160  transcript1       0.65   +       ACG     ACA
```
