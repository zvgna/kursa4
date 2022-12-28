#include "kursachh.h"
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

string text;
//�������� ������ ��������
void DeleteSpace() {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' && text[i + 1] == ' ')
            while (text[i + 1] == ' ')
                text.erase((i + 1), 1);
    }
}
//�������� ������ ������
void Unsign() {
    for (int i = 0; i <= text.size(); i++) {
        if ((text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == ':' || text[i] == '!' || text[i] == '?') && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?'))
            if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.' && text[i + 3] == ' ')
                i += 3;
            else {
                while (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?')
                    text.erase((i + 1), 1);
            }
    }
}
//��������� ��������
void Registr() {
    for (int i = 1; i < text.size(); i++) {
        if (text[i] == ' ')
            i += 2;
        text[i] = tolower(text[i]);
    }
}
//���.������� �� ����� �� �� ������������������, ������ �� ���� ���� �������� ����� ���� � (���) ����.
void Posled(string txt) {
    string destr;
    cout << "\n4. ������� ������������������, ������� ������ ������� �� ������� �����: ";
    cin >> destr;
    for (int i = 0, k = 0; i < txt.size(); i++)
    {
        if (text[i] == destr[0]) {
            k = 1;
            for (int j = 1; j < destr.size(); j++)
                if (destr[j] != txt[i + j]) {
                    k = 0;
                    break;
                }
            if (k == 1) {
                while (txt[i] != destr[destr.size() - 1])
                    txt.erase((i), 1);
                txt.erase((i), 1);
                i--;
            }
        }
    }
    cout << "\n��������� ���������: " << txt << "\n\n";
}
//�������� �����
void Search() {
    string key;
    int k;
    int count = 0;

    cin >> key;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == key[0]) {
            k = 1;
            for (int j = 1; j < key.size(); j++) {
                if (text[i + j] != key[j]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1)
                count++;
        }
    }
    if (count == 0) {
        cout << "�� ������� ������ �� �������";
    }
    else {
        cout << "������� " << count << " ������������";
    }
}

void lab4()
{
    setlocale(0, "");

    {
        int input;
    Menu: {
        cout << "������� ����� ������������������ ��� ����� �������\n" <<
            "1. �������� ����� ������������������\n" <<
            "2. ����� ������� ������������������\n";
        cin >> input;
        }
    if (input == 1) {
        cin.ignore();
        getline(cin, text);
    }
    else if (input == 2) {
        ifstream in("C:\\Users\\user\\Documents\\!prog\\lab - 4\\text.txt");

        if (in.is_open())
            getline(in, text);
        in.close();
    }
    else
        goto Menu;
    cout << "1. �������� ������: " << text << "\n";
    }

    {
        DeleteSpace();
        Unsign();
        Registr();

        cout << "2. ����������������� ������: " << text << "\n";
    }

    {
        cout << "3. C����� � �������� �������: ";
        int a = 0;
        text += " ";

        for (int i = text.length(); i >= 0; i--) {
            if (text[i] == ' ') {
                for (int k = i + 1; k <= (i + a); k++) {
                    cout << text[k];
                }
                a = 0;
            }
            a++;
        }
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') break;
            cout << text[i];
        }
    }

    {
        Posled(text);
    }

    {
        cout << "5. ������� ���������, ������� �� ������ ����� � ����������������� ������: ";
        Search();
    }
}