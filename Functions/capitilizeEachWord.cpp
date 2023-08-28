#include <iostream>
#include <string.h>

using namespace std;

string toUpper(string sentence)
{
    string newSentence = sentence;
    newSentence[0] = toupper(sentence[0]);

    for (int i = 0; i < sentence.length(); i++)
    {

        if (sentence[i] == ' ')
        {
            newSentence[i] = sentence[i];
            newSentence[i + 1] = toupper(sentence[i + 1]);
            i++;
        }
        else
        {
            newSentence[i] = sentence[i];
        }
    }

    return newSentence;
}

int main()
{
    string sentence;

    getline(cin, sentence);

    cout << "\nUpdated: " << toUpper(sentence);
}