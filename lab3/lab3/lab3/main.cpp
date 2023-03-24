#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void zad1() {
    fs::path current_path = fs::current_path();
    std::cout << "Aktualna sciezka: " << current_path.string() << std::endl;

    fs::create_directory("backup");
    fs::create_directory("Kopie");

    std::cout << "Zawartosc aktualnego folderu:" << std::endl;
    for (const auto& entry : fs::directory_iterator(current_path))
    {
        std::cout << entry.path().string() << std::endl;
    }
}

void zad2() {
    fs::path directory_path = fs::current_path(); 
    std::string file_extension = ".cpp"; 
    std::string output_file_name = "output.txt";

    std::ofstream output_file(output_file_name); 

    if (output_file.is_open()) 
    {
        for (auto& file : fs::directory_iterator(directory_path)) 
        {
            if (file.path().extension() == file_extension) 
            {
                output_file << file.path().filename() << " " << fs::file_size(file) << " bytes" << std::endl;
                std::cout << file.path().filename() << " " << fs::file_size(file) << " bytes" << std::endl; // zapisz nazwê i rozmiar pliku w pliku wyjœciowym
            }
        }

        output_file.close(); 
        

    }
}

void zad3() {
    fs::path source_path = "source";
    fs::path backup_path = "backup";
    fs::path destination_path = "destination";
    
    for (const auto& entry : fs::directory_iterator(source_path)) {
        fs::copy(entry.path(), destination_path / entry.path().filename());
    }

    for (const auto& entry : fs::directory_iterator(source_path)) {
        fs::remove(entry.path());
    }

    fs::create_directory(backup_path);

    for (const auto& entry : fs::directory_iterator(destination_path)) {
        fs::rename(entry.path(), backup_path / entry.path().filename());
    }
        /*
        if (!fs::exists("backuplink"))
        fs::create_directory_symlink(backup_path, "backuplink");
        */
}

int main() {
    std::cout << "ZAD1" << std::endl;
    zad1();
    std::cout << "ZAD1 Completed" << std::endl;
    std::cout << "ZAD2" << std::endl;
    zad2();
    std::cout << "ZAD2 Completed" << std::endl;
    zad3();
    std::cout << "ZAD3 Completed" << std::endl;
    return 0;
}