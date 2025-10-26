#include <iostream>

using namespace std;

class Solution {
private:
    void inicia(int valores[]){
        for(int i = 0; i<26; i++){
            valores[i] = 1;
        }
    }

public:
    bool checkIfPangram(string sentence) {
        int valores[26];
        inicia(valores);
        
        for(size_t i = 0; i<sentence.size(); i++){
            valores[sentence[i]-'a'] = 0;
        }

        for(int i = 0; i<26; i++){
            if(valores[i] != 0){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution sol;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    cout << sol.checkIfPangram(sentence);
}