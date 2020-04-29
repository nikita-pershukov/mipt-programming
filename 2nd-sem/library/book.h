#ifndef BOOk_H
#define BOOk_H

#include "All_include.h"

#define MAX_SIZE 256

class Book
{
protected:
    char *author;
    char *title;
    char *publisher;
    char *content;
    int year;
    int pages_count;
public:
    Book(const char *new_author = 0, const char *new_title = 0, const char *new_publisher = 0, const int new_year = 0, const int new_pages_count = 0, const char *new_content = 0);
    Book(const Book& a);

    char *Get_author() const;
    char *Get_title() const;
    char *Get_publisher() const;
    char *Get_content() const;
    int Get_year() const;
    int Get_pages_count() const;

    friend ostream& operator << (ostream&, const Book&);
    friend istream& operator >> (istream&, Book&);

    void Print_format(ostream&);

    void Set_author(char *new_author);
    void Set_title(char *new_title);
    void Set_publisher(char *new_publisher);
    void Set_content(char *new_content);
    void Set_year(int new_year);
    void Set_pages_count(int new_pages_count);
    Book& operator =(const Book &a);
    bool operator ==(const Book &a) const;

    ~Book();
};

#endif // Book_H
