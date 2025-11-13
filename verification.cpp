#include <regex>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "verification.h"

// Fonction pour vérifier la validité d'une adresse e-mail
bool isValidEmail(const std::string& email) {
    // Regex simple pour valider une structure de base : texte@texte.extension
    // \w+ : un ou plusieurs caractères alphanumériques (lettres, chiffres, underscore)
    // [\. ] : un point littéral
    // {2,4} : l'extension doit avoir entre 2 et 4 caractères
    const std::regex pattern(R"(\w+@\w+\.\w{2,4})");

    // std::regex_match vérifie si toute la chaîne correspond au pattern
    return std::regex_match(email, pattern);
};
bool isValidName(const std::string& name){
     std::regex regex_special_char(R"(^[^a-zA-Z0-9])");

     return(!std::regex_search(name, regex_special_char));
};
bool isValidNumber(const std::string& number){


    
    // Le motif gère les variations de format :
    // ^ - Début de la chaîne
    // (\+7|8) - Optionnellement +7 ou 8
    /* ? - Rendre le préfixe optionnel*/
    // ( - Début du groupe pour la suite du numéro
    // \s* - Zéro ou plusieurs espaces
    // \(?\d{3}\)? - Indicatif régional de 3 chiffres, optionnellement entre parenthèses
    // [\s-]* - Zéro ou plusieurs espaces ou tirets
    // \d{3} - 3 chiffres
    // [\s-]* - Zéro ou plusieurs espaces ou tirets
    // \d{2} - 2 chiffres
    // [\s-]* - Zéro ou plusieurs espaces ou tirets
    // \d{2} - 2 chiffres
    // | - Ou (pour d'autres formats)
    // (\+7|8)?\s*\d{10} - Optionnellement +7 ou 8, suivis de 10 chiffres sans formatage
    // $ - Fin de la chaîne
    
    std::regex russianPhoneRegex(R"(^(\+7|8)?[\s-]*\(?\d{3}\)?[\s-]*\d{3}[\s-]*\d{2}[\s-]*\d{2}$|^(\+7|8)?\s*\d{10}$)");
    return std::regex_match(number, russianPhoneRegex);

};


//for the date, the function is little too big

//1- verify the bissextil year
bool isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool checkDate(const std::string& dateStr) {
    int day, month, year;
    char separator1, separator2;
    std::stringstream ss(dateStr);

    // 1. Parsing the string
    // Attempt to read day, separator, month, separator, year
    ss >> day >> separator1 >> month >> separator2 >> year;

    // Check if parsing succeeded and if separators are correct
    // ss.peek() != EOF ensures no extra characters are at the end of the string
    if (ss.fail() || separator1 != '-' || separator2 != '-' || ss.peek() != EOF) {
        std::cerr << "Format error. Expected format is dd-mm-yyyy." << std::endl;
        return false;
    }

    // 2. Validation of the date (manual logic)
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Invalid date (year, month, or day initial bounds)." << std::endl;
        return false;
    }

    // Using a std::vector for flexibility (alternative to a C-style array)
    std::vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(year)) {
        daysInMonth[2] = 29; // February
    }

    if (day > daysInMonth[month]) {
        std::cerr << "Invalid date (day invalid for the month/year)." << std::endl;
        return false;
    }

    // 3. Comparison with the current date
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    // std::tm fields: tm_year (years since 1900), tm_mon (0-11), tm_mday (1-31)
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    
    // Today's date at runtime: 13-11-2025

    // Comparison logic: year > month > day
    if (year < currentYear) {
        return true; // Certainly in the past
    } else if (year > currentYear) {
        return false; // Certainly in the future
    } else { // Same year
        if (month < currentMonth) {
            return true; // Month in the past
        } else if (month > currentMonth) {
            return false; // Month in the future
        } else { // Same year, same month
            if (day < currentDay) {
                return true; // Day in the past
            } else {
                return false; // Date >= current date
            }
        }
    }
}

/*

// verify the validity of the date
bool isValidDate(int d, int m, int y) {
    // Vérifie la validité de l'année
    if (y < 1 || y > 9999) { // Limite d'année arbitraire
        return false;
    }
    // Vérifie la validité du mois
    if (m < 1 || m > 12) {
        return false;
    }
    // Vérifie la validité du jour
    if (d < 1 || d > 31) {
        return false;
    }
    // Vérifie le nombre de jours dans le mois
    if (m == 2) {
        if (isLeap(y)) {
            return (d <= 29);
        } else {
            return (d <= 28);
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return (d <= 30);
    }
    return true;
}
// Fonction principale
// Fonction pour vérifier si la date en string est valide et différente d'aujourd'hui
bool checkDate(const std::string& dateString) {
    // 1. Vérifier le format jj-mm-aaaa
    if (dateString.length() != 10 || dateString[2] != '-' || dateString[5] != '-') {
        return false;
    }

    // 2. Extraire les parties de la date
    std::stringstream ss(dateString);
    int d, m, y;
    char dash;
    ss >> d >> dash >> m >> dash >> y;

    if (ss.fail()) { // Vérifie si le parsing a échoué
        return false;
    }

    // 3. Valider la date avec la fonction précédente
    if (!isValidDate(d, m, y)) {
        return false;
    }

    // 4. Obtenir la date du jour actuelle
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&current_time);

    // 5. Comparer les dates
    // Note : L'heure ne sera pas comparée, seulement la date
    // Si vous voulez une comparaison exacte, il faudrait aussi comparer l'heure
    // mais la demande est juste de vérifier si la date est différente du jour actuel.
    if ((local_time->tm_year + 1900 == y) &&
        (local_time->tm_mon + 1 == m) &&
        (local_time->tm_mday == d)) {
        return false; // La date est la même que le jour actuel
    }

    return true; // La date est valide et différente d'aujourd'hui
}

*/