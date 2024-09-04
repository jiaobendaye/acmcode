#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class File{
public:
    string name;
    File* parent;
    unordered_map<string, File*> subFiles;
    File(const string& _name) :name(_name), parent(nullptr){}

    void mkdir(const string& _name) {
        if(subFiles.find(_name) == subFiles.end()) {
            subFiles[_name] = new File(_name);
            subFiles[_name]->parent = this;
        }
    }

    File* cd(const string& _name) {
        if(_name == "..") return this->parent;

        if(subFiles.find(_name) != subFiles.end()) {
            return subFiles[_name];
        }
        return this;
    }

    string pwd() {
        string res = "/";
        File* cur = this;
        while(cur->parent) {
            res =  "/" +cur->name + res;
            cur = cur->parent;
        }

        return res;
    }
};

int main() {
    File* root = new File("");
    File* cur = root;
    string cmd;
    string res;
    while(getline(cin, cmd)) {
        if(cmd.find("mkdir ") == 0) {
            cur->mkdir(cmd.substr(6));
        } else if (cmd.find("cd ") == 0) {
            cur = cur->cd(cmd.substr(3));
        } else if(cmd == "pwd") {
            res = cur->pwd();
        }
    }
    cout << res << endl;
    return 0;
}