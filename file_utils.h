#pragma once

//������� ���������� ����� ������� � �������������� �����
std::fstream& fill_file_with_numbers(int n, int m, std::string filename);

//���������� ����� ������� � �������������� generate
std::fstream& fill_file_with_numbers_generate(int n, int m, std::string filename);

//������� ��� ��������� ���������� ��� ���������� �����
bool get_fill_params(std::string& file_name, int& size, int& max);