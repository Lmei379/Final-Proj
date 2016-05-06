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

//reads in the sequence from the fna file into a vector
genome.open("sequence.txt"); // renamed the fna file into a txt doc and changed named into sequence
string header;
getline(genome,header);     //when outputting... output header << "|" start << "|" << end
//once head is outputted then just print the phage sequences
//newfile << header;
string sequen;
if (genome.is_open()){
    while(getline(genome,seq)){
        sequen += seq; // put the whole genome into one line, so it is easier to extract versus using the vector
        sequence.push_back(seq + "\n");}
    genome.close(); //closes the fna file
}
else { cout << "file not found" << endl;}
//cout << sequen << endl; debugging

ofstream newfile; //created a new file to put/write stuff in
newfile.open("phage sequences.txt"); //opens the new file

vector<string> phage; //will store the sequences that have "phage" in the gene file
for (int i=0; i<info.size(); i++){
    if (info[i].find("phage") != -1) //finds the lines with phage in it and use them to get the sequence
    {
        //extracts the start and end positions
        int pos = info[i].find(".."); // for getting the start position and can get the length for extracting
        //cout << endl;
        string start = info[i].substr(0,pos);
        int pos2=info[i].find('\t'); //for getting the end position
        string endpos = info[i].substr(pos+2,pos2-(pos+2)); //beginning after the .. (pos+2) and getting the length of end position without tab

        int staPos = atoi(start.c_str()); // convert string to int
        int edPos = atoi(endpos.c_str());
        int length = edPos - staPos+1; // use length to find the sub-sequence from the genome
        cout << "length: " << length << endl;

        int counter = 0; //to count every position in the sequence
        cout << "phage line: " << i+1 << endl;
        //cout << "seq size: " << sequence.size() << endl; //it was 7 because of the short sequence doc
        for (int l=0; l<sequence.size(); l++){
            for (int j =0; j<sequence[1].length(); j++){
                    if (counter == staPos){
                            cout << "staPos: " << staPos << endl;
                            //cout << "phage seq: " << sequence[l] << endl;
                            string geo = sequen.substr(staPos,length);
                            //cout << "phage seq: " << geo << endl;
                            //phage.push_back(geo);
                            newfile << "|" << staPos << "|" << edPos << endl;
                            newfile << geo << endl;
                            }
                    counter++;} }

       /* for (int l=0; l<sequen.length(); l++){
                if (counter == staPos) {
                    cout << "staPos: " << staPos << endl;
                    cout << "phage seq: " << sequence[l] << endl;
                    string geo = sequen.substr(staPos,length);
                }
                counter++;
            }*/

    }
}
newfile.close();
}
