#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"

Date createDate(int month, int day, int year) {
    Date d;

    d.month = month;
    d.day = day;
    d.year = year;

    return d;
}

Product createProduct(int prodID, String prodName, int prodQty, Date expiry, Date manufacture) {
    Product p;

    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.prodQty = prodQty;
    p.expiry = expiry;
    p.manufacture = manufacture;

    return p;
}

void displayDate(Date d) {
    String month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    printf("%02d %s %4d", d.day, month[d.month-1], d.year);
}

void displayProduct(Product p) {
    printf("%03d | %-25s | %-5d | ", p.prodID, p.prodName, p.prodQty);
    displayDate(p.expiry);
    printf(" | ");
    displayDate(p.manufacture);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return -1; // Invalid month
    }
}

int dateDifference(Date d1, Date d2) {
    int days1 = d1.day + (d1.month - 1) * daysInMonth(d1.month, d1.year) + d1.year * 365;
    int days2 = d2.day + (d2.month - 1) * daysInMonth(d2.month, d2.year) + d2.year * 365;

    return days2 - days1;
}

void createAndPopulate(ProductList *prod) {

    Product prods[15];

    prods[0] = createProduct(1, "Sago't Gulaman", 30, createDate(1, 20, 2025), createDate(1, 20, 2022));
    prods[1] = createProduct(2, "Guinumis", 24, createDate(5, 12, 2024), createDate(7, 15, 2023));
    prods[2] = createProduct(3, "Calamansi Juice", 60, createDate(10, 1, 2024), createDate(5, 12, 2023));
    prods[3] = createProduct(4, "Mango Juice", 15, createDate(12, 25, 2024), createDate(6, 6, 2022));
    prods[4] = createProduct(5, "Melon Juice", 18, createDate(7, 31, 2025), createDate(8, 1, 2021));
    prods[5] = createProduct(6, "Guyabano Juice", 49, createDate(1, 1, 2025), createDate(1, 1, 2022));
    prods[6] = createProduct(7, "Buko Juice", 5, createDate(5, 23, 2025), createDate(9, 10, 2022));
    prods[7] = createProduct(8, "Buko Pandan Drink", 25, createDate(6, 21, 2024), createDate(6, 6, 2022));
    prods[8] = createProduct(9, "Kapeng Barako", 12, createDate(1, 11, 2026), createDate(1, 15, 2024));
    prods[9] = createProduct(10, "Salabat", 8, createDate(7, 15, 2029), createDate(3, 12, 2024));
    prods[10] = createProduct(11, "Lambanog", 26, createDate(9, 10, 2024), createDate(1, 20, 2023));
    prods[11] = createProduct(12, "Tuba", 12, createDate(7, 7, 2024), createDate(7, 20, 2020));
    prods[12] = createProduct(13, "Bignay Wine", 4, createDate(11, 14, 2023), createDate(10, 20, 2020));
    prods[13] = createProduct(14, "Tapuy", 13, createDate(12, 18, 2026), createDate(11, 20, 2020));
    prods[14] = createProduct(15, "Basi", 16, createDate(9, 21, 2024), createDate(4, 20, 2020));

    prod->count = 15;

    memcpy(prod->prods, prods,sizeof(prods));

}
