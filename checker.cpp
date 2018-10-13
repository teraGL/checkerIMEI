#include <iostream>
#include <string>
#include <vector>

bool isRightIMEI(const std::string& imei)
{
    if (imei.length() != 15) {
        std::cerr << "\nIMEI must contain 15 digits." << std::endl;
        return false;
    }

    if (imei.find_first_not_of("0123456789") != std::string::npos) {
        std::cerr << "\nIMEI must contain only digits." << std::endl;
        return false;
    }

    // double every other digit
    std::vector<int> first14digits;
    for (size_t i = 0; i < imei.length() - 1; ++i) {
        (i % 2) ? first14digits.push_back((imei[i] - '0') + (imei[i] - '0'))
                : first14digits.push_back(imei[i] - '0');
    }

    // check if the sum is divisible by 10
    int sum_digits = 0;
    for (size_t i = 0; i < first14digits.size(); ++i) {
        if (i % 2 != 0) {
            sum_digits += (first14digits[i] / 10 > 0) ? 1 + first14digits[i] - 10
                                                      : first14digits[i];
        } else {
            sum_digits += first14digits[i];
        }
    }
    
    int checksum = (sum_digits == 0) : 0 ? 10 - sum_digits % 10;
    if (checksum != imei.back() - '0') {
        std::cerr << "The sum of the digits is not equal to the Last digit" << std::endl;
        return false;
    }
    return true;
}

int main()
{
    std::cout << "IMEI > ";
    std::string imei;
    std::getline(std::cin, imei);
    std::cout << (isRightIMEI(imei) ? "Success!" : "Invalid code, select another IMEI.") << std::endl;
}
