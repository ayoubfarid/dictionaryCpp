#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string,string> dictionary;
    ifstream  myfile;
    myfile.open("urbandict-word-defs.csv");
    string line;
    vector<string> v;
    while( myfile ) {
        //vider le vecteur
        v.clear();
        //recuperer une ligne
        getline (myfile, line);

        stringstream ss(line);
        //parcourir et extracter la cle et la definition
        for (int i = 0; i < 5; ++i) {
                string substr;
                //soustracter les chaines de caractere separer par une virgule d apres la ligne recuperer
                getline(ss, substr, ',');
                v.push_back(substr);
            }
        //extracter la definition
        string def;
        getline(ss, def);
        v.push_back(def);
        //inserer la cle et la definition dans la map
        dictionary.insert(make_pair(v[1], v[5]) );
    }

    string motChercher;
    //tester le dictionnaire donnner des mots si vous vouler
    do {
        cout<<"Donner le mot que ous recherche ";
        cin>>motChercher;
        cout<<"Mot Chercgher : "<<motChercher<<endl;
        cout<<"Definition : "<<dictionary[motChercher]<<endl;

    }while(motChercher!="fin");//pour quitter tapez fin
    return 0;
}
