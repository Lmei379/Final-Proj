#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <cstring>
#include <cstdlib> // implemented to use atoi

using namespace std;

int main (){
string line,temp ="";
string seq;
ifstream genes; //read file with the genes
ifstream genome; //read file with the sequence
vector <string> sequence; //vector connected from genome
vector <string> info; //vector connected to genes

//reads in the info from the ptt fie into a vector
genes.open("genetics file.txt"); //renamed the ptt file into a txt document and changed the name
if (genes.is_open()){
    while(getline(genes,line)){
        info.push_back(line + "\n");}
    genes.close(); //closes the ptt file
}
else { cout << "file not found" << endl;}

/*for (int i=0; i<info.size(); i++){ //for debugging
    cout << "line: " << info[i];
}*/

//reads in the sequence from the fna file into a vector
genome.open("seq short.txt"); // renamed the fna file into a txt doc and changed named into sequence
if (genome.is_open()){
    while(getline(genome,seq)){
        sequence.push_back(seq + "\n");}
    genome.close(); //closes the fna file
}
else { cout << "file not found" << endl;}


vector<string> phage; //will store the sequence that have "phage" in the gene file
for (int i=0; i<info.size(); i++){
    if (info[i].find("phage") != -1) //finds the lines with phage in it and use them to get the sequence
    {
        cout << info[i] << endl; //for debugging
        //question, do you want the genes with just the word phage in it
        //because there are some words like bacteriophage which have phage in it

        //extracts the start and end positions
        /*int pos = info[i].find("..");
        string start = info[i].substr(0,...); // lost on how to extract the start and end positions...
        string endpos = info[i].substr(pos+1, );

        int staPos = atoi(start); // convert string to int
        int edPos = atoi(endpos);
        int length = edPos - staPos; // use length to find the sub-sequence from the genome*/

        /*for (int o=0; o<sequence.size(); o++){
            string geo = sequence[o].substr(staPos,length); //the sub-sequence that connects to the gene with phage in it
            phage.push_back(geo);
        }*/
    }
}

}

void write_file (vector<string> arr){
    ofstream newfile; //created a new file to put/write stuff in
    newfile.open("phage sequences.txt"); //opens the new file
    for (int x=0; x<arr.size(); x++){
        newfile << ">" << arr[x] << endl; //enters the sub-sequences from vector into file
        //I hope this is what you mean when you want the sequences to be written out into a file
    }
}
