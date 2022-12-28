#include "kursachh.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

	void shakerSort(int A[]) {
		for (int n = 100; n > 0; --n) {
			for (int i = 0; i < n - 1; ++i) {
				if (A[i] > A[i + 1])
					swap(A[i], A[i + 1]);
			}
			for (int i = n - 2; i > 0; --i) {
				if (A[i] < A[i - 1])
					swap(A[i], A[i - 1]);
			}
		}
	}

	void viewArray(int A[], int n = 100) {
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << "\n";
	}

	void twoArray(int A[]) {
		int B[50], C[50];
		for (int i = 0; i < 50; i++)
			B[i] = A[i];

		for (int i = 50; i < 100; i++)
			C[i - 50] = A[i];
		cout << "����������� ������";
		viewArray(A);
		cout << "\n";
		cout << "������ �������� ������������ �������\n";
		viewArray(B, 50);
		cout << "\n";
		cout << "������ �������� ������������ �������\n";
		viewArray(C, 50);
		cout << " \n";
		for (int i = 0; i < 50; i++) {
			if (B[i] % 2 != 0) {
				for (int j = 0; j < 50; j++) {
					if (C[j] % 2 == 0) {
						swap(B[i], C[j]);
						break;
					}
				}
			}
		}
		cout << "��������� �������\n";
		viewArray(B, 50);
		cout << "\n";
		cout << "��������� �������\n";
		viewArray(C, 50);
		cout << "\n";
		for (int i = 0; i < 50; i++)
			if (C[i] % 2)
				C[i]++;
		cout << "��������� �������\n";
		viewArray(C, 50);
		cout << "\n";
		int result = 0;
		for (int i = 0; i < 50; i++)
			if (B[i] > C[i])
				result++;
		cout << "���������� ���������� " << result << endl;
	}

	void menu() {
		cout << "1. ������������� ����� ������\n";
		cout << "2. ������������� �������� ������ ����������� (�� �������� � ��������)\n";
		cout << "3. ����� ������������ � ����������� ������� �������\n";
		cout << "4. ������� ������� �������� ������������� � ������������ �������� � ��������������� � ����������������� �������\n";
		cout << "5. ����� ���������� ��������� ������� ����� X\n";
		cout << "6. ����� ���������� ��������� ������� ����� X\n";
		cout << "7. ����� ����� � �������\n";
		cout << "8. �������� ������� �������� �������\n";
		cout << "9. �������������� �������\n";
		cout << "0. ����� �� ���������\n";
		cout << "������� ����� ��������: \n";
	}

	void handleForCase1(int Ar[]) {
		cout << "����� ������:\n";
		srand(time(0));
		for (int i = 0; i < 100; ++i)
			Ar[i] = -99 + rand() % 199;
		viewArray(Ar);
		cout << "\n";
	}

	void handleForCase2(int A[]) {
		auto start = chrono::steady_clock::now();
		shakerSort(A);
		auto end = chrono::steady_clock::now();
		duration<double> sec = end - start;
		viewArray(A);
		cout << "\n����� ����������� �� ����������:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " �����������\n\n";
	}

	void handleForCase3(int A[]) {
		shakerSort(A);
		int min, max;
		auto start = chrono::steady_clock::now();
		min = A[0];
		max = A[99];
		auto end = chrono::steady_clock::now();

		cout << "������������ �������: " << max << "\n����������� �������: " << min << "\n";
		cout << "���������������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n";

		min = A[0];
		max = A[0];
		start = chrono::steady_clock::now();
		for (int i = 0; i < 100; i++) {
			if (A[i] > max)
				max = A[i];
			if (A[i] < min)
				min = A[i];
		}
		end = chrono::steady_clock::now();

		cout << "�����������������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";
	}

	void handleForCase4(int A[]) {
		shakerSort(A);
		int max = A[99], min = A[0];
		double mid = round((max + min) / 2);
		cout << "������� ��������: " << mid << "\n";

		auto start = chrono::steady_clock::now();
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (A[i] == mid)
				count += 1;
		}
		auto end = chrono::steady_clock::now();

		cout << "������� " << count << " ������� �����. ��� ��������� �� ��������: ";

		for (int i = 0; i < 100; i++) {
			if (A[i] == mid)
				cout << i + 1 << " ";
		}
		cout << "\n����� ������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";
	}

	void handleForCase5(int A[]) {
		int x, count = 0;
		cout << "������� ����� X: ";
		cin >> x;

		shakerSort(A);
		for (int i = 0; i < x; i++) {
			if (A[i] < x)
				count += 1;
			else break;
		}
		cout << "���-�� ��������� ������� " << x << " = " << count << "\n\n";
	}

	void handleForCase6(int A[]) {
		int x, count = 0;
		cout << "������� ����� X: ";
		cin >> x;

		shakerSort(A);
		for (int i = 99; i >= 0; i--) {
			if (A[i] > x)
				count += 1;
			else break;
		}
		cout << "���-�� ��������� ������� " << x << " = " << count << "\n\n";
	}

	void handleForCase7(int A[]) {
		shakerSort(A);
		int left = -99, right = 99;
		int mid, key;

		cout << "������� ������� �����: ";
		cin >> key;
		auto start = chrono::steady_clock::now();
		while (left < right) {
			mid = (left + right) / 2;

			if (A[mid] > key)
				right = mid;
			else
				left = mid + 1;
		}
		right -= 1;
		auto end = chrono::steady_clock::now();

		if (A[right] == key)
			cout << "\n����� ����� � ������� ����\n";
		else
			cout << "\n������ ����� � ������� ���\n";

		cout << "����� ������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n";

		start = chrono::steady_clock::now();
		bool k = false;
		for (int i = 0; i < 100; i++) {
			if (A[i] == key) {
				k = true;
			}
		}

		end = chrono::steady_clock::now();
		cout << "����� ������ ���������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";
	}

	void handleForCase8(int A[]) {
		int x1, x2;
		cout << "������� 2 ��������, ������� �� ������ �������� �������: ";
		cin >> x1 >> x2;
		cout << "\n";

		auto start = chrono::steady_clock::now();
		swap(A[x1 - 1], A[x2 - 1]);
		auto end = chrono::steady_clock::now();

		viewArray(A);

		cout << "�������� ������: ";
		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";
	}

	void lab2() {
		setlocale(0, "");

		int input = 1;
		int A[100];

		srand(time(0));

		cout << "��� �������� ����������� ������:\n";

		for (int i = 0; i < 100; ++i)
			A[i] = -99 + rand() % 199;

		viewArray(A);
		cout << "\n";

		while (input) {
			menu();
			cin >> input;
			cout << "\n";
			switch (input) {
			case 1: {
				handleForCase1(A);
				break;
			}

			case 2: {
				handleForCase2(A);
				break;
			}

			case 3: {
				handleForCase3(A);
				break;
			}

			case 4: {
				handleForCase4(A);
				break;
			}

			case 5: {
				handleForCase5(A);
				break;
			}

			case 6: {
				handleForCase6(A);
				break;
			}

			case 7: {
				handleForCase7(A);
				break;
			}

			case 8: {
				handleForCase8(A);
				break;
			}

			case 9: {
				twoArray(A);
				break;
			}
			case 0: {
				exit;
				break;
			}

			default: {
				cout << "���-�� ����� ����� �� ���, ����� ������. \n\n";
			}
			}
		}
	}
