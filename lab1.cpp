#include "kursachh.h"
#include <iostream>
using namespace std;

void lab1() {
 
        setlocale(0, "");
        cout << "~~~~~ 1 ������� ~~~~~ \n";
        cout << "� ������ ����������: \n";
        cout << "int �������� " << sizeof(int) << " ����� \n";
        cout << "short int �������� " << sizeof(short int) << " ����� \n";
        cout << "long int �������� " << sizeof(long int) << " ����� \n";
        cout << "float �������� " << sizeof(float) << " ����� \n";
        cout << "double �������� " << sizeof(double) << " ���� \n";
        cout << "long double �������� " << sizeof(long double) << " ���� \n";
        cout << "char �������� " << sizeof(char) << " ���� \n";
        cout << "bool �������� " << sizeof(bool) << " ���� \n";
        cout << "\n";


        cout << "~~~~~ 2 ������� ~~~~~ \n";
        int imput;
        cout << "������� ����� ����� ����� \n";
        cin >> imput;
        int idz = imput;
        cout << "�������� ������������� ���������� �����: \n ";
        int a = sizeof(imput) * 8;
        int mask = 1 << (a - 1);
        for (int i = 0; i < a; i++) {
            if (i == 1 || i % 8 == 0) {
                putchar(' ');
            }
            putchar(imput & mask ? '1' : '0');
            imput <<= 1;
        }
        //������ ���
        cout << "\n";
        cout << "������� �� ����� ���������� ����� ����� �������� ���������� �����: \n";
        int z;
        cin >> z;
        idz <<= z;

            for (int i = 0; i < a; i++) {
                if (i == 1 || i % 8 == 0) {
                    putchar(' ');
                }
                putchar(idz & mask ? '1' : '0');
                idz <<= 1;
                //��������� ���
            }
        cout << "\n";
        union {
            float value;
            int b;
        };
        cout << "\n";
        cout << "~~~~~ 3 ������� ~~~~~\n";
        cout << "������� ����� �������� ���� float \n";
        cin >> value;
        cout << "�������� ������������� ���������� �����: \n";
        for (int i = 0; i < a; i++) {
            if (i == 1 || i % 8 == 0) {
                putchar(' ');

            }
            putchar(b & mask ? '1' : '0');
            b <<= 1;

        }
        cout << "\n |����������|--------��������-------|" << endl;
        cout << "\n";

        cout << "~~~~~ 4 ������� ~~~~~\n";
        cout << "������� �������� ���� double \n";


        union {
            double num;
            int num3[2];
        };

        cin >> num;

        int a2 = 32;
        int mask2 = 1 << (a2 - 1);

        for (int i = 0; i < a2; i++) {
            if (i == 1 || i % 8 == 0 || i == 12)
                cout << " ";
            cout << (num3[1] & mask2 ? '1' : '0');
            num3[1] <<= 1;
        }

        for (int i = 0; i < a2; i++) {
            if (i % 8 == 0)
                cout << " ";
            cout << (num3[0] & mask2 ? '1' : '0');
            num3[0] <<= 1;
        }

        cout << "\n   | ���������� |-------------------------��������-------------------------| \n";
}