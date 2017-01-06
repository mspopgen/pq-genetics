# Population and Quantitative Genetic Tools

**pq-genetics** calculates population and quantitative genetic statistics from genomic data given as a file or piped via standard input. The focus is on speed and ease of use, especially with regard to the input format.

```bash
Usage:

  pqgen [--help] [--version] <command> [OPTIONS] [FILE]


Main commands:

  het	       Calculate heterozygosity.

  sfs	       Output the folded site frequency spectrum.

  theta        Calculate site frequency based statistics.
    

Input format:

  pqgen takes input in an extended bed format:

  	chrom    start    end    name    GT.1    GT.2  ...  GT.n

  where GT.1 to GT.n are the genotypes of each individual given in GT format.
  This can be generated from vcf format using bcftools:

       bcftools query -f "%CHROM\t<pos0>\t%POS\t<name>[\t%GT]\n" aln.vcf

  Giving for example:

       Contig0    <pos0>    1    <name>    0/0    0/0    0/1    0/0    0/1
       Contig0    <pos0>    2    <name>    0/0    0/0    0/0    0/0    0/0
       Contig0    <pos0>    3    <name>    0/1    0/1    0/0    0/0    0/1


Common options:

  -c <int>
     Column number (1-indexed) giving the chromosome.

  -d <char>
     Delimiter separating each column. Must be enclosed in single quotes, spaces
     must be escaped (e.g. -d '\ '). Tab delimited by default.

  -f <int>
     Column number (1-indexed) of the factor over which the stats should be calculated.
     By default, statistics are output per chromosome.

  -k <str>
     1-indexed column numbers indicating the columns over which the statistic
     should be calculated. Columns can be separated by commas, and ranges specified
     using dashes. For example, -k 2,5-7 would specify columns 2, 5, 6 and 7.

  -p <int>
     Column number (1-indexed) giving the 1-indexed reference position.
     
```
## Example

```bash
$ bcftools query -f "%CHROM\t<pos0>\t%POS\t<name>[\t%GT]\n" Contig012.vcf | pqgen theta

Contig0	0	1372378	Contig0	10	1367408	15844	0.004096	0.004072	-0.029052
Contig1	0	865787	Contig1	10	862828	12965	0.005312	0.005468	0.148427
Contig2	0	786857	Contig2	10	783622	15404	0.006949	0.007175	0.163521
```

Bonus commands:

  div          Calculate divergence based statistics. The input format is slightly different. For example: "Contig0    <pos0>    1    <name>    A    G"

  pnds         Count the number of silent and replacement substitutions and polymorphisms. The input format is slightly different. For example: "Contig0    <pos0>    1    <name>    AAA    AAG    AAA    AAA   AAG"




## Quick install

**pq-genetics** makes use of the library **librawk**. To install this dependency, go [here](https://github.com/mspopgen/librawk).

Once **librawk** is installed, download and unpack the latest version of **pq-genetics** (replacing *X*, *Y* and *Z* with the version number):
```bash
wget https://github.com/mspopgen/pq-genetics/archive/vX.Y.Z.tar.gz
tar -zxvf vX.Y.Z.tar.gz
```
Then change into the **pq-genetics** directory, compile the source and install it:
```bash
cd pq-genetics-X.Y.Z
make
make install
```
This will install the compiled code into ```~/.local/``` and put configuration files into ```~/.config/pqgen/```. To call the commands from any directory, add ```~/.local/bin``` to your ```PATH``` environmental variable.
