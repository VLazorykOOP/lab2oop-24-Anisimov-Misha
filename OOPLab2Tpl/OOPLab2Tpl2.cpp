#include <iostream>
#include <string>
#include <bitset>

// Функція для доповнення рядків пробілами до 32 символів
std::string padTo32Chars(const std::string& input) {
    std::string paddedInput = input;
    while (paddedInput.length() < 32) {
        paddedInput += ' ';
    }
    return paddedInput;
}

// Функція для шифрування тексту
std::string encryptText(const std::string& input) {
    std::string encryptedText;

    for (char c : input) {
        // Отримуємо номер рядка (2 біти)
        int row = (encryptedText.length() / 32) % 4;

        // Отримуємо позицію символу в рядку (5 біт)
        int position = encryptedText.length() % 32;

        // Отримуємо ASCII-код символу (8 біт)
        int asciiCode = static_cast<int>(c);

        // Розраховуємо біт парності
        int parityBit = std::bitset<8>(asciiCode).count() % 2;

        // Формуємо двобайтове представлення символу
        short int encryptedChar = (row << 14) | (position << 9) | (asciiCode << 1) | parityBit;

        // Додаємо два байти до зашифрованого тексту
        encryptedText += static_cast<char>(encryptedChar >> 8);
        encryptedText += static_cast<char>(encryptedChar & 0xFF);
    }

    return encryptedText;
}

int main() {
    // Задані рядки тексту
    std::string text1 = "Hello";
    std::string text2 = "World!";
    std::string text3 = "This is a";
    std::string text4 = "Test";

    // Доповнюємо рядки пробілами до 32 символів
    text1 = padTo32Chars(text1);
    text2 = padTo32Chars(text2);
    text3 = padTo32Chars(text3);
    text4 = padTo32Chars(text4);

    // З'єднуємо рядки для шифрування
    std::string combinedText = text1 + text2 + text3 + text4;

    // Шифруємо текст
    std::string encryptedText = encryptText(combinedText);

    // Виводимо зашифрований текст
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    system("pause");
    return 0;
}

