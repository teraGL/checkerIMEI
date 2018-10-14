#include <iostream>
#include <string>

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

    // Calculate the Luhn checksum of the IMEI digits
    int checksum = 0;
    for (size_t i = 0; i < imei.length() - 1; ++i) {
        if (i % 2) {
            int doubled_digit = 2 * (imei[i] - '0');
            checksum += (doubled_digit > 9) ? 1 + doubled_digit - 10 : doubled_digit;
        } else {
            checksum += imei[i] - '0';
        }
    }

    // make checksum divisible by 10 and check with last digit
    int final_digit = (10 - checksum % 10) % 10;
    if (final_digit != imei.back() - '0') {
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
