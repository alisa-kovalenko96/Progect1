#pragma once

//���������� ���������� �� �����
std::list<double>& fill_container_with_numbers(std::fstream& file);

//����������� ����������
void modify(std::list<double>& list);

//����������� ����� ����������
void modify(std::list<double>& list, std::list<double>::iterator first, std::list<double>::iterator last);

//������� ��� ����������� ����� transform
void modify_transform(std::list<double>& list);

//������� ��� ����������� ����� for_each
void modify_foreach(std::list<double>& list);

//������� ������������ ����������
double sum_container(std::list<double> list);

//���������� �������� ��������������� ����������
double avg_container(std::list<double> list);

//������� ��� ������������ ����������
void show_container(std::list<double> list);