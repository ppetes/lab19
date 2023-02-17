#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string x,vector<string> &names,vector<int> &score,vector<char> &grade){
ifstream file(x);
string text;
char format[] = "%[^:]:%d %d %d";
char name[100];
int a,b,c;
while(getline(file,text)){
    sscanf(text.c_str(),format,name,&a,&b,&c);
    names.push_back(name);
    score.push_back(a+b+c);
    grade.push_back(score2grade(a+b+c));
}
}

void getCommand(string &command,string &key){
    cout <<  "Please input your command: ";
   cin >> command;
   if(toUpperStr(command) == "GRADE" or toUpperStr(command) == "NAME"){
   cin.ignore();
   getline(cin,key);
   }
   


}

void searchName(vector<string> &name,vector<int> &score,vector<char> &grade,string key){
    int x = 0;
    cout << "---------------------------------\n";
    for( unsigned int i = 0;i < name.size();i++){
      
        if(key == toUpperStr(name[i])){
            cout << name[i] <<  "'s score = " << score[i] << endl;
            cout << name[i] <<  "'s grade = " << grade[i] << endl;
            x++;
        }
        else if(i == name.size()-1 && x == 0) cout << "Cannot found.\n";

    }
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> &name,vector<int> &score,vector<char> &grade,string key){
    int x = 0;
    cout << "---------------------------------\n";
    for( unsigned int i = 0;i < name.size();i++){
        
        if(*key.c_str() == grade[i]){
            cout << name[i] << " " << "(" << score[i] << ")"<< endl;
            x++;
        }
        else if(i == name.size()-1 && x == 0) cout << "Cannot found.";

    }
    cout << "---------------------------------\n";
}




int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}