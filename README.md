# CIS17B-S25-33477-Assignment5

## Description
This project is a smart packaging system that demonstrates the use of C++ templates, function specializations, class template specializations, and non-type template parameters.

## Features
- Generic `Package<T>` class
- Full specialization for `std::string` (book titles)
- Partial specialization for pointers (fragile items)
- `Box<T, Size>` template class using `std::array`
- `shipItem<T>()` with a `double` specialization for temperature-controlled items

## Build Instructions
To compile the code:
```bash
g++ -std=c++17 -o main main.cpp
