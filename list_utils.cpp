#include "stdafx.h"
#include "list_utils.h"
#include "help_utils.h"

void print_to_file(std::ofstream& file, std::list<double> list) {
	for (std::list<double>::iterator it = list.begin(); it != list.end(); ++it) {
		file << *it << std::endl;
	}
}

//заполнение контейнера из файла
std::list<double>& fill_container_with_numbers(std::fstream& file) {
    std::list<double>* list = new std::list<double>();
    file.clear();
    file.seekg(0);
    if (bool b = file.is_open())
    {
        std::string line;
        int num;
        while (!file.eof())
        {
            std::getline(file, line);
            try {
                num = std::stoi(line);
                list->push_back(double(num));
            }
            catch (std::exception e) {}
        }
		if (list->size() == 0) {
			print_message("Cписок пуст.");
		}
    }
	else
	{
		print_message("Файл не найден.");
	}

    return *list;
}

//функция по получению max
double get_max(std::list<double>::iterator first, std::list<double>::iterator last) {
    double max = *first;
    for (std::list<double>::iterator it = first; it != last; ++it) {
        if (*it > max) {
			max = *it;
        }
    }
    return max;
}

//модификация контейнера
void modify(std::list<double>& list) {
    double last_max = get_max(list.begin(), list.end());
    for (std::list<double>::iterator it = list.begin(); it != list.end(); ++it) {
        *it = *it - last_max;
    }
}

//модификация части контейнера
void modify(std::list<double>& list, std::list<double>::iterator first, std::list<double>::iterator last) {
    double last_max = get_max(first, last);
    for (std::list<double>::iterator it = first; it != last; ++it) {
        *it = *it - last_max;
    }
}

//структура для модификации элементов через transform
struct transform_functor {
    transform_functor(double last_max) : last_max1(last_max) {}
    double operator()(double x1) { return x1 - last_max1; }

private:
    double last_max1;
};

//функция для модификации через transform
void modify_transform(std::list<double>& list) {
    double last_max = get_max(list.begin(), list.end());
    std::transform(list.begin(), list.end(), list.begin(), transform_functor(last_max));
}

//структура для модификации через for_each
struct foreach_functor {
    foreach_functor(double last_max) : last_max1(last_max) {}
    void operator()(double &x1) { x1 = x1 - last_max1; }

private:
    double last_max1;
};

//функция для модификации через for_each
void modify_foreach(std::list<double>& list) {
    double last_max = get_max(list.begin(), list.end());
    std::for_each(list.begin(), list.end(), foreach_functor(last_max));
}

//функция суммирования контейнера
double sum_container(std::list<double> list) {
    double sum = 0;
    std::list<double>::iterator it = list.begin();
    while (it != list.end()) {
        sum += *it;
        ++it;
    }
    return sum;
}

//вычисление среднего арифметического контейнера
double avg_container(std::list<double> list) {
    double avg = 0;
    if (list.size() != 0) {
        avg = sum_container(list) / list.size();
    }
    return avg;
}

//функция для демонстрация контейнера
void show_container(std::list<double> list) {
    std::list<double>::iterator it = list.begin();
    while (it != list.end()) {
        if (it != list.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
        ++it;
    }
    std::cout << std::endl;
}