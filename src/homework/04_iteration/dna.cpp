#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string &dna){
    double content = 0.0;
    int len = 0;
    int i = 0;

    while(dna[i] != '\0'){
        if (dna[i] == 'G' || dna[i] == 'C'){
            content += 1;
        }
        i += 1;
        len += 1;
    }
    return content / len;
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna){
    string rev = "";

    for(int i = dna.length()-1; i>=0; i--){
        rev += dna[i];
    }
    return rev;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string dna){
    string b = get_reverse_string(dna);
    string complement = "";

    for(int i = 0; i<b.length(); i++){
        if(b[i] == 'A'){
            complement += 'T';
        }
        else if(b[i] == 'T'){
            complement += 'A';
        }
        else if(b[i] == 'G'){
            complement += 'C';
        }
        else if(b[i] == 'C'){
            complement += 'G';
        }
    }
    return complement;
}
