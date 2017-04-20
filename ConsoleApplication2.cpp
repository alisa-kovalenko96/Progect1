/* ��������� ����� ����������, 9 ������
������ 3�. ������� �� ������� ����� ������������ �� �����. */

#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <time.h>
#include <limits.h>
#include "list_utils.h"
#include "file_utils.h"
#include "help_utils.h"

std::string file_name = "";
std::fstream* file;

//������� ��� ����������� �������� ����
void print_menu(std::list<double> list)
{
	system("cls");
	std::cout << "1. ���������� ���������� ����� �������" << std::endl;
	std::cout << "2. ���������� ���������� �� �����" << std::endl;
	std::cout << "3. �������������� ����������" << std::endl;
	std::cout << "4. �����" << std::endl;
	std::cout << "5. ������� ��������������" << std::endl;
	std::cout << "6. ����� �� �����" << std::endl;
	std::cout << "0. �����" << std::endl;
	if (list.size() == 0) { std::cout << "���� �� ��������. ��������� �������� ����������." << std::endl; }
}

//������� �������� ���� � ��������� ������
int main_menu(std::list<double> list) {
	std::string choice = "";
	int choice_number = -1;
	while ((choice_number < 0) || (choice_number > 7))
	{
		print_menu(list);
		getChoice(0, 7, choice_number);
	}
	return choice_number;
}

//�������� �� ������������ ����������
void sum_container_action(std::list<double> list) {
	system("cls");
	if (list.size() == 0) {
		std::cout << "��������� ����." << std::endl;
	}
	else {
		show_container(list);
		std::cout << "����� ����� � ���������� = " << sum_container(list) << std::endl;
	}
	system("pause");
}

//�������� �� ���������� �������� ���������������
void avg_container_action(std::list<double> list) {
	system("cls");
	if (list.size() == 0) {
		std::cout << "��������� ����." << std::endl;
	}
	else {
		show_container(list);
		std::cout << "������� �������������� ����� � ���������� = " << avg_container(list) << std::endl;
	}
	system("pause");
}

//�������� ��� ������������ ����������
void show_container_action(std::list<double> list) {
	system("cls");
	if (list.size() == 0) {
		std::cout << "��������� ����!" << std::endl;
	}
	else {
		show_container(list);
	}
	system("pause");
}

//�������� �� ���������� �����
void fill_file_action() {
	system("cls");
	std::cout << "�������� ���� �� ������� ����:" << std::endl;
	std::cout << "1. ��������� ����� ����� ����." << std::endl;
	std::cout << "2. ��������� ����� ����� generate." << std::endl;
	std::cout << "0. �����." << std::endl;
	int choice_number = -1;
	while ((choice_number < 0) || (choice_number > 2)) {
		getChoice(0, 2, choice_number);
	}
	switch (choice_number) {
	case 1: {
		system("cls");
		int size = -1, max = -1;
		if (get_fill_params(file_name, size, max)) {
			if (file != NULL) {
				file->close();
			}
			file = &fill_file_with_numbers(size, max, file_name);
		}
		break;
	}
	case 2: {
		system("cls");
		int size = -1, max = -1;
		if (get_fill_params(file_name, size, max)) {
			if (file != NULL) {
				file->close();
			}
			file = &fill_file_with_numbers_generate(size, max, file_name);
		}
		break;
	}
	default: break;
	}
	file->close();
	file_name = "";
}

//�������� �� ���������� ����������
void fill_container_action(std::list<double>& list) {
	if (file_name == "") {
		std::cout << "������� ��� ����� (������ ������ - ������.):" << std::endl;
		std::getline(std::cin, file_name);
		if (file_name == "") {
			return;
		}
		file = new std::fstream(file_name, std::fstream::in | std::fstream::out);
	}
	if (list.size() != 0) { list.clear(); }
	list = fill_container_with_numbers(*file);
	file->close();
	file_name = "";
}

//�������� �� ����������� ����������
void modify_container_action(std::list<double> list) {
	system("cls");
	std::cout << "�������� ���� �� ������� ����:" << std::endl;
	std::cout << "1. ����������� ����� modify(list)." << std::endl;
	std::cout << "2. ����������� ����� modify(first, last)." << std::endl;
	std::cout << "3. ����������� ����� modify_transform(list)." << std::endl;
	std::cout << "4. ����������� ����� modify_for_each(list)." << std::endl;
	std::cout << "0. �����." << std::endl;
	int choice_number = -1;
	while ((choice_number < 0) || (choice_number > 4)) {
		getChoice(0, 4, choice_number);
	}
	std::cout << "��������� �� �����������:" << std::endl;
	show_container(list);
	std::cout << "��������� ����� �����������:" << std::endl;
	std::list<double> modified_list(list);
	try {
		switch (choice_number) {
		case 1: {
			modify(modified_list);
			break;
		}
		case 2: {
			int size = modified_list.size();
			int begin = -1;
			while ((begin < 1) || (begin > size)) {
				std::cout << "������� ������� ������ ��������� �� 1 �� " + std::to_string(size) << std::endl;
				getChoice(1, size, begin);
			}

			int end = -1;
			while ((end < begin) || (end > size)) {
				std::cout << "������� ������� ����� ��������� �� " + std::to_string(begin) + " �� " + std::to_string(size) << std::endl;
				getChoice(begin, size, end);
			}
			std::list<double>::iterator first, last, it = modified_list.begin();
			int i = 1;
			while (i <= end) {
				if (i == begin) { first = it; }
				if (i == end) { last = ++it; }
				++i;
				if (it != modified_list.end()) { ++it; }
			}
			modify(modified_list, first, last);
			break;
		}
		case 3: {
			modify_transform(modified_list);
			break;
		}
		case 4: {
			modify_foreach(modified_list);
			break;
		}
		default: {break; }
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	show_container(modified_list);
	system("pause");
}

//���������� ������� ����
void create_menu_actions(int choice, std::list<double>& list) {
	switch (choice) {
	case 1: {
		fill_file_action();
		break;
	}
	case 2: {
		fill_container_action(list);
		break;
	}
	case 3: {
		if (list.size() != 0) modify_container_action(list);
		break;
	}
	case 4: {
		if (list.size() != 0) sum_container_action(list);
		break;
	}
	case 5: {
		if (list.size() != 0) avg_container_action(list);
		break;
	}
	case 6: {
		if (list.size() != 0) show_container_action(list);
		break;
	}
	default: {break; }
	}
}

int main()
{
	std::list<double> list;
	setlocale(LC_ALL, "russian");
	int choice_number = -1;
	while (choice_number != 0) {
		choice_number = main_menu(list);
		create_menu_actions(choice_number, list);
	}
	if (file != NULL) {
		file->close();
	}
	return 0;
}

