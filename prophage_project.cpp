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
ifstream genes; //read file with the genes description and start & stop positions
ifstream genome; //read file with the sequence
vector <string> info; //vector that will store in the gene descriptions and positions

ofstream newfile; //created a new file to put/write stuff in later
newfile.open("phage sequences.txt"); //opens the new file

//reads in the info from the ptt file into a vector
genes.open("genetics file.txt"); //renamed the ptt file into a txt document and changed the name
if (genes.is_open()){
    while(getline(genes,line)){
        info.push_back(line + "\n");}
    genes.close(); //closes the ptt file
}
else { cout << "file not found" << endl;}

//reads in the sequence from the fna file into a string
genome.open("sequence.txt"); // renamed the fna file into a txt doc and changed named into sequence
string header; //gets the header in the fna file
getline(genome,header);     //when outputting... output header << "|" start << "|" << end
newfile << header << endl; //writes the header to the "phage sequences" file
string sequen; //string for storing the whole genome sequence
if (genome.is_open()){
    while(getline(genome,seq)){
        sequen += seq;} // inputs the whole genome into one line, so it is easier to extract versus using a vector
    genome.close(); //closes the fna file
}
else { cout << "file not found" << endl;}

for (int i=0; i<info.size(); i++){
    if (info[i].find("phage") != -1) //finds the lines (in "info" vector) with "phage" in it and get the positions
    {
        //extracts the start and end positions
        int pos = info[i].find(".."); // for getting the start position and can get the length for extracting
        string start = info[i].substr(0,pos);
        int pos2=info[i].find('\t'); //for getting the end position
        string endpos = info[i].substr(pos+2,pos2-(pos+2)); //beginning after the .. (pos+2) and getting the length of end position without tab

        int staPos = atoi(start.c_str()); // convert string to int
        int edPos = atoi(endpos.c_str());
        int length = edPos - staPos+1; // get the length to find the sub-sequences from the genome

        int counter = 0; //to count every position in the genome sequence
        for (int l=0; l<sequen.length(); l++){ //use to find the sub-sequences connected to phage and write them to the "phage sequences" file
                if (counter == staPos) { //use the counter to find the start position of sub-sequence
                    string geo = sequen.substr(staPos,length); //extracts the sub-sequence and puts it into a string (geo)
                    newfile << "|" << staPos << "|" << edPos << endl;
                    newfile << geo << endl;} //writes geo into the new file (phage sequences)
                counter++;}
    }
}
newfile.close();
}
