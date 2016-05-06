#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <cstring>
#include <cstdlib> // implemented to use atoi

using namespace std;

int main (){
string line;
string seq;
ifstream genes; //read file with the genes
ifstream genome; //read file with the sequence
vector <string> sequence; //vector connected to genome
vector <string> info; //vector connected to genes

//reads in the info from the ptt file into a vector
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
string header;
getline(genome,header);     //when outputting... output header << "|" start << "|" << end
if (genome.is_open()){
    while(getline(genome,seq)){
        sequence.push_back(seq + "\n");}
    genome.close(); //closes the fna file
}
else { cout << "file not found" << endl;}

for (int i=0; i<sequence.size(); i++){ //for debugging
    cout << "line: " << sequence[i] << endl;
    cout << "postion: " << sequence[i][0] << endl;
}

vector<string> phage; //will store the sequences that have "phage" in the gene file
for (int i=0; i<info.size(); i++){
    if (info[i].find("phage") != -1) //finds the lines with phage in it and use them to get the sequence
    {
        //cout << info[i] << endl; //for debugging

        //extracts the start and end positions
        int pos = info[i].find(".."); // for getting the start position and can get the length for extracting
        cout << endl;
        string start = info[i].substr(0,pos);
        int pos2=info[i].find('\t'); //for getting the end position
        string endpos = info[i].substr(pos+2,pos2-(pos+2)); //beginning after the .. (pos+2) and getting the length of end position without tab

        //cout << start << "\t" << endpos << endl; //for debugging

        int staPos = atoi(start.c_str()); // convert string to int
        int edPos = atoi(endpos.c_str());
        int length = edPos - staPos+1; // use length to find the sub-sequence from the genome

        //this is the problem affected run-time
        //so because the vector takes in every line, it is going by per paragraph, which you have to check each line by (use if statements)
        //the start and end positions and then in that area find the sequence with the start and stop
        /*for (int o=0; o<sequence.size(); o++){
            if ()
            string geo = sequence[o].substr(staPos,length); //the sub-sequence that connects to the gene with phage in it
            cout << "phage seq: " << geo << endl; //for debugging
            phage.push_back(geo);}*/ //add the sub-sequences to a new vector, so it can be written into a file
    }
}
//write_file(phage);
}

/*void write_file (vector<string> arr){ //don't make a function just put it in main ...
    ofstream newfile; //created a new file to put/write stuff in
    newfile.open("phage sequences.txt"); //opens the new file
    newfile << header << "|" start << "|" << end
    for (int x=0; x<arr.size(); x++){
        newfile << arr[x] << endl; //enters the sub-sequences from vector into file
        //I hope this is what you mean when you want the sequences to be written out into a file NOPE
        //look at the note on top, - header the first
    }
}*/
