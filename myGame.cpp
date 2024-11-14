#include <iostream>
#include <cstdlib> // Бібліотека яка має функцію очищення консолі
#include <windows.h> // Бібліотека для додаткових символів
#include <conio.h> // Бібліотека для моментального зчитування нажатих клавіш
#include <string> // Для типу данних "Рядок"

#define height 20 // Задання висоти поля
#define width 30 // Задання ширени поля

using namespace std;

// Функція для заповнення масиву одним символом
void fillArray(char array[height][width], char symbol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = symbol;
        }
    }
}

void fillMap(char array[height][width], char tree, char worse, char river, char bridge, char house, char nps, char axe, char pickaxe, char boulder, char crystal) {
    for (int j = 1; j < 7; j++) {

        array[2][j] = tree;
        array[6][j] = tree;

    }

    array[3][1] = tree; array[3][2] = tree; array[3][6] = tree;  array[3][7] = tree;
    array[4][1] = tree;
    array[5][1] = tree; array[5][2] = tree; array[5][6] = tree;  array[5][7] = tree;

    for (int j = 0; j < 6; j++) {

        array[12][j] = worse;
        array[13][j] = worse;
        array[19][j] = worse;

    }

    array[13][5] = worse; array[13][6] = worse;
    array[14][5] = worse; array[14][6] = worse;
    array[16][5] = worse; array[16][6] = worse;
    array[17][4] = worse; array[17][5] = worse; array[17][6] = worse;
    array[18][3] = worse; array[18][4] = worse; array[18][5] = worse;
    array[15][5] = boulder; array[15][1] = crystal;

    for (int i = 0; i < 6; i++) {
        for (int j = 12; j < 14; j++) {
            array[i][j] = river;
            array[i + 5][j + 1] = river;
            array[i + 10][j + 2] = river;
            array[i + 15][j + 3] = river;
        }
    }

    array[8][13] = bridge; array[8][14] = bridge;

    array[3][18] = house; array[2][20] = house; array[2][23] = house; array[5][22] = house; array[4][24] = house;

    array[6][22] = nps;

    array[4][2] = axe;
}

// Функція для виведення масиву в консоль
void printArray(char array[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << array[i][j] << "";
        }
        cout << endl;
    }
}

// Функція для заповнення масиву інвентаря
void fillInventory(string inventory[3][14], char TopLeftCorner, char TopRightCorner, char BottomLeftCorner, char BottomRightCorner, char TopSeparator, char BottomSeparator, char HorizontalLine, char VerticalLine, char axe, char pickaxe, char tree, bool axeInInventory, bool pickaxeInInventory, int numberTrees) {

    inventory[0][0] = TopLeftCorner; inventory[0][1] = HorizontalLine; inventory[0][2] = HorizontalLine; inventory[0][3] = HorizontalLine; inventory[0][4] = TopSeparator; inventory[0][5] = HorizontalLine; inventory[0][6] = HorizontalLine; inventory[0][7] = HorizontalLine; inventory[0][8] = TopSeparator; inventory[0][9] = HorizontalLine; inventory[0][10] = HorizontalLine; inventory[0][11] = HorizontalLine; inventory[0][12] = HorizontalLine; inventory[0][13] = TopRightCorner;
    inventory[1][0] = VerticalLine;  inventory[1][1] = " "; inventory[1][3] = " "; inventory[1][4] = VerticalLine;  inventory[1][5] = " "; inventory[1][7] = " "; inventory[1][8] = VerticalLine;  inventory[1][9] = tree; inventory[1][10] = "=";  inventory[1][12] = ""; inventory[1][13] = VerticalLine;
    inventory[2][0] = BottomLeftCorner; inventory[2][1] = HorizontalLine; inventory[2][2] = HorizontalLine; inventory[2][3] = HorizontalLine; inventory[2][4] = BottomSeparator; inventory[2][5] = HorizontalLine; inventory[2][6] = HorizontalLine; inventory[2][7] = HorizontalLine; inventory[2][8] = BottomSeparator; inventory[2][9] = HorizontalLine; inventory[2][10] = HorizontalLine; inventory[2][11] = HorizontalLine; inventory[2][12] = HorizontalLine, inventory[2][13] = BottomRightCorner;

    if (axeInInventory == true) {

        inventory[1][2] = axe;

    }
    else {
        inventory[1][2] = " ";
    }
    if (pickaxeInInventory == true) {

        inventory[1][6] = pickaxe;

    }
    else {
        inventory[1][6] = " ";
    }

    inventory[1][11] = to_string(numberTrees);

    if (numberTrees > 9) {

        inventory[1][12] = "";

    }
    else {

        inventory[1][12] = " ";

    }

}

// Функція для виведення масиву інвентаря
void printInventory(string inventory[3][14]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 14; j++) {
            cout << inventory[i][j] << "";
        }
        cout << endl;
    }
}

void end() {

    cout << "*Teleportation Crystal*";
    cin.get();
    system("cls");
    cout << endl << "-----------------------------------------------------------------" << endl << "      Win Game: The Character Is Happily Back in His World" << endl << "-----------------------------------------------------------------" << endl;
    cin.get();
}

int main()
{
    SetConsoleOutputCP(CP_ACP); // Команда підключення символьного стандарта ANSI

    bool axeInInventory = false; // Наявність сокири
    bool pickaxeInInventory = false; // Наявність кайла
    int numberTrees = 0; // Присвоєння кількості дерева значення 0

    char array[height][width];
    string inventory[3][14];
    fillArray(array, char(219)); // Викликаємо функцію для заповнення масиву символом '*'
    fillInventory(inventory, char(201), char(187), char(200), char(188), char(203), char(202), char(205), char(186), char(213), char(209), char(89), axeInInventory, pickaxeInInventory, numberTrees);

    int i = 5;       // Вказуємо рядок в якому буде гравець
    int j = 10;       // Вказуємо стовпець в якому буде гравець
    char body = char(1); // Символ позначення гравця 


    fillMap(array, char(89), char(30), char(176), char(219), char(127), char(2), char(213), char(209), char(37), char(4));


    array[i][j] = body; // Розміщуємо гравця на полі (масиві), за заданими координатами
    printArray(array);  // Викликаємо функцію для виведення масиву - малювання поля
    cout << endl;
    printInventory(inventory);  // Викликаємо функцію для виведення масиву інвентаря

    bool exitGame = false;  // Створюємо змінну для виходу з гри
    char direction;       // Створюємо змінну для поточної команди (напрямку руху)



    while (exitGame == false) { // while цикл для перевірки на завершення гри
        direction = _getch();   // Користувач вводить команду з клавіатури

        array[i][j] = char(219); // Затираємо поточну позицію гравця на полі

        // Змінюємо координати гравця (позицію на полі) відповідно до введеної команди
        if (direction == 'w') {
            if (i > 0) {
                if (array[i - 1][j] == char(219)) {

                    i--; // рух вгору

                }
                else if (array[i - 1][j] == char(2)) {

                    if (numberTrees < 10) {

                        cout << "Albert (Mayor of the village):\n Hello traveler!I'd love to talk to you, but our village needs firewood, as it's already getting colder.\n If you were my game to carry a pile of firewood(10 pcs) I would be very happy, I will not remain in debt!" << endl;
                        cin.get();

                    }
                    else {

                        cout << "Albert (Mayor of the village):\n Hello, traveler! I see you've brought a pile of firewood.\n Thank you very much! Now our village will remain warm.\n As I promised you, your reward.\n \n *You got a pickaxe*" << endl;
                        pickaxeInInventory = true;
                        numberTrees = numberTrees - 10;
                        cin.get();

                    }
                }
                else if (array[i - 1][j] == char(89)) {
                    if (axeInInventory == true) {

                        array[i - 1][j] = char(219);
                        numberTrees++;

                    }
                }
                else if (array[i - 1][j] == char(4)) {

                    array[i - 1][j] = char(219);
                    end();
                    exitGame = true;
                    return 0;

                }
            }
        }
        else if (direction == 's') {
            if (i < height - 1) {
                if (array[i + 1][j] == char(219)) {
                    i++; // рух вниз
                }
                else if (array[i + 1][j] == char(89)) {
                    if (axeInInventory == true) {

                        array[i + 1][j] = char(219);
                        numberTrees++;

                    }
                }
                else if (array[i + 1][j] == char(4)) {

                    array[i + 1][j] = char(219);
                    end();
                    exitGame = true;
                    return 0;

                }
            }
        }
        else if (direction == 'a') {
            if (j > 0) {
                if (array[i][j - 1] == char(219)) {

                    j--; // рух вліво

                }
                else if (array[i][j - 1] == char(213)) {

                    axeInInventory = true;
                    array[i][j - 1] = char(219);

                }
                else if (array[i][j - 1] == char(89)) {
                    if (axeInInventory == true) {

                        array[i][j - 1] = char(219);
                        numberTrees++;

                    }
                }
                else if (array[i][j - 1] == char(37)) {
                    if (pickaxeInInventory == true) {
                        array[i][j - 1] = char(219);
                    }
                    else {

                        cout << "*The cave is blocked, you need a tool to clear it*";
                        cin.get();

                    }
                }
                else if (array[i][j - 1] == char(4)) {

                    array[i][j - 1] = char(219);
                    end();
                    exitGame = true;
                    return 0;

                }
            }
        }
        else if (direction == 'd') {
            if (j < width - 1) {
                if (array[i][j + 1] == char(219)) {

                    j++; // рух вправо

                }
                else if (array[i][j + 1] == char(89)) {
                    if (axeInInventory == true) {

                        array[i][j + 1] = char(219);
                        numberTrees++;

                    }
                }
                else if (array[i][j + 1] == char(4)) {

                    array[i][j + 1] = char(219);
                    end();
                    exitGame = true;
                    return 0;

                }
            }
        }
        else if (direction == 27) { // Перевірка чи користувач нажав клавішу Esc

            system("cls");
            exitGame = true; // Виходимо з гри
            cout << endl << "------------------------------------" << endl << "          Game over" << endl << "------------------------------------" << endl;
            return 0;
        }
        else {
            cout << "Unknown Command" << endl;
            continue; // Переходимо до наступної ітерації циклу 
        }

        // TODO: в цьому місці можна дописати перевірку на зіткнення з межами поля. (тут ми оновили координати гравця, але ще не застосували)
        // Якщо координати гравця опинились в тому місці де вони не мають бути - маємо повернути координати на попередню дозволену позицію.

        array[i][j] = char(1);  // Розміщуємо гравця на новій позиції  

        system("cls");      // Викликаємо функцію очищення вікна консолі
        printArray(array);  // Виводимо поле на екран 

        cout << endl;

        fillInventory(inventory, char(201), char(187), char(200), char(188), char(203), char(202), char(205), char(186), char(213), char(209), char(89), axeInInventory, pickaxeInInventory, numberTrees); // повторне заповнення масиву на випадок підбору предмета
        printInventory(inventory);  // Викликаємо функцію для виведення масиву інвентаря

    }
    return 0;
}
