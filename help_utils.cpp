#include "stdafx.h"
#include "help_utils.h"

//������� ��� ������ ���������
void print_message(std::string msg)
{
    std::cout << msg << std::endl;
    system("pause");
}

//������� ��������� ������ �� ��������� ����� min � max
void getChoice(int min, int max, int& choice_number) {
    std::string choice = "";
    try {
        std::getline(std::cin, choice);
        choice_number = std::stoi(choice);
        if ((choice_number < min) || (choice_number > max))
        {
            print_message("�� ������ ������ ����� �� " + std::to_string(min) + " �� " + std::to_string(max) + "!");
        }
    }
    catch (std::invalid_argument e)
    {
        print_message("�� ������ ������ �����!");
    }
    catch (std::out_of_range e)
    {
        print_message("����� �� ������� ����!");
    }
}