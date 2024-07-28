#include <stdio.h>
// https://www.youtube.com/watch?v=IrGjyfBC-u0

typedef struct House {
    // 4 bytes each x 12 bytes in total
    int sqft;
    int bedrooms;
    int bathrooms;
} house;

void modifyBedrooms(house* h, int newBedroom)
{
    // -> means go to the object being pointed to
    // and then get this member vairable by its name
    h->bedrooms = newBedroom;
}

// getHousePrice1(house h)         getHousePrice2(house* h)
// +--------------------+          +--------------------+
// |     Stack Frame    |          |     Stack Frame    |
// |                    |          |                    |
// | +----------------+ |          | +----------------+ |
// | | Copied struct  | |          | | Pointer (4/8B) | |
// | |  sqft          | |          | +----------------+ |
// | |  bedrooms      | |          |                    |
// | |  bathrooms     | |          |        |           |
// | +----------------+ |          |        |           |
// +--------------------+          |        v           |
//                                 |                    |
//                                 | Original struct    |
//                                 | in memory          |
//                                 +--------------------+

int getHousePrice1(house h)
{
    // copying the whole house to calculate the price
    // pass by value
    // this is like bringing the actual house to the appraiser to
    // calculate the house
    return h.sqft * 1000 + h.bedrooms * 10000 + h.bathrooms * 5000;
}

int getHousePrice2(house* h)
{
    // pass by reference
    // using the pointer (address of) the house
    // access the members through the pointer
    // this is like telling the appraiser the address of the house
    // and get him to calculate the house value
    return h->sqft * 1000 + h->bedrooms * 10000 + h->bathrooms * 5000;
}

int main(void)
{
    printf("Hello pointers!\n");
    house my_house;
    my_house.sqft = 1000;
    my_house.bedrooms = 3;
    my_house.bedrooms = 2;
    // a point is a variable that holds the address of some objet (which is a house)
    //
    // Memory
    // +-------------------+
    // |                   |
    // |  +-------------+  |
    // |  | House       |  |
    // |  | +--------+  |  |
    // |  | | sqft   |  |  |
    // |  | | 1000   |  |  |
    // |  | +--------+  |  |
    // |  | +--------+  |  |
    // |  | |bedrooms|  |  |
    // |  | | 3      |  |  |
    // |  | +--------+  |  |
    // |  | +--------+  |  |
    // |  | |bathroom|  |  |
    // |  | | 2      |  |  |
    // |  | +--------+  |  |
    // |  +-------------+  |
    // |        ^          |
    // |        |          |
    // |  +-----+-----+    |
    // |  | house_ptr |    |
    // |  +-----------+    |
    // +-------------------+
    //
    // house my_house = {1500, 3, 2};
    // house *house_ptr = &my_house;
    house* house_ptr = &my_house;
    printf("The address of the house_2345 is %p\n", house_ptr);
    printf("my_house has %d bedrooms\n", my_house.bedrooms);

    // now modify the pointer
    modifyBedrooms(house_ptr, 5);
    printf("my_house has %d bedrooms\n", my_house.bedrooms);

    getHousePrice1(my_house);
    getHousePrice2(&my_house);

    char szTest[] = "Hello char array!";
    printf("szTest\t %s\n", szTest); // prints "Hello char array!"
    char* pText = szTest;
    printf("pText\t %s\n", pText); // prints "Hello char array!"

    // steps pointer by a single byte
    pText++;

    // steps pointer by 5 bytes
    pText += 5;

    printf("pText\t %s\n", pText);

    int aNumbers[] = { 1, 2, 3, 4, 5 };
    int* pNumbers = aNumbers;

    // steps pointer by a single integer (4 bytes on 32-bit)
    pNumbers++;
    // steps pointer by 5 integers (20 bytes)
    pNumbers += 5;

    //  1. char* d = "hello";
    //    (Read-only memory section)
    //    +---+---+---+---+---+---+
    //    | h | e | l | l | o | \0|
    //    +---+---+---+---+---+---+
    //      ^
    //      |
    //    +---+
    // d: |   | --> points to the start of "hello"
    //    +---+

    char* p = "Hello";
    printf("p: %s\n", p);
    printf("Address in p: %p\n", (void*)p);

    // (Writable memory section, e.g., stack)
    //    +---+---+---+---+---+---+
    // e: | h | e | l | l | o | \0|
    //    +---+---+---+---+---+---+
    char e[] = "hello";
    // This is safe and will modify the array
    e[0] = 'H';
    printf("e: %s\n", e); // Prints: Hello

    // a pointer pointing to the pointer
    char** p1 = &p;
    // dereference and print
    printf("*p1: %s\n", *p1);
    printf("Address of p1 itself: %p\n", (void*)&p1);
    printf("Address in p1: %p\n", (void*)p1);

    return 0;
}
