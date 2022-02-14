#include <iostream>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = filesystem;
auto getNameFile = [](fs::path& _path,const string extension){
    vector<string> found;
    for (auto& p: fs::recursive_directory_iterator(_path)){
        if (is_regular_file(p.path())) {
            if (!p.path().extension().compare(extension)) {
                found.push_back (p.path().filename().string());
            }
        }
    }
    if (found.empty()){
        cout << "file not\n";
    }else {
        return found;
    }
};
int main(){
    fs::path p("D:\\steam");
    for (auto& i : getNameFile(p, ".txt")){
        cout << i << endl;
    }
    return 0;
}