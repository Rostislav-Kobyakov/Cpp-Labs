#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Exhibit
{
public:
    virtual void Print() const = 0;
    virtual ~Exhibit() {}
};

class HistoricExhibit : public Exhibit
{
public:
    HistoricExhibit(const char* name, int startYear, int endYear)
        : name_(nullptr), startYear_(startYear), endYear_(endYear)
    {
        size_t nameLen = strlen(name) + 1;
        name_ = new char[nameLen];
        strcpy(name_, name);
    }

    ~HistoricExhibit()
    {
        delete[] name_;
    }

    void Print() const override
    {
        cout << "Name: " << name_ << endl;
        cout << "Start Year: " << startYear_ << endl;
        cout << "End Year: " << endYear_ << endl;
    }

private:
    char* name_;
    int startYear_;
    int endYear_;
};

class ArtExhibit : public Exhibit
{
public:
    virtual ~ArtExhibit() {}
    virtual void Print() const = 0;
    ArtExhibit() : image_(nullptr), date_(0) {}
protected:
    char* image_;
    int date_;

    ArtExhibit(const ArtExhibit& other)
        : image_(nullptr), date_(other.date_)
    {
        size_t imageLen = strlen(other.image_) + 1;
        image_ = new char[imageLen];
        strcpy(image_, other.image_);
    }

    ArtExhibit& operator=(const ArtExhibit& other)
    {
        if (this != &other)
        {
            delete[] image_;
            date_ = other.date_;

            size_t imageLen = strlen(other.image_) + 1;
            image_ = new char[imageLen];
            strcpy(image_, other.image_);
        }
        return *this;
    }

    ArtExhibit(ArtExhibit&& other) noexcept
        : image_(other.image_), date_(other.date_)
    {
        other.image_ = nullptr;
    }

    ArtExhibit& operator=(ArtExhibit&& other) noexcept
    {
        if (this != &other)
        {
            delete[] image_;
            image_ = other.image_;
            date_ = other.date_;
            other.image_ = nullptr;
        }
        return *this;
    }
};

class OldArtExhibit : public ArtExhibit
{
public:
    OldArtExhibit(const char* image, const char* author, int date)
        : ArtExhibit(), author_(nullptr)
    {
        size_t imageLen = strlen(image) + 1;
        image_ = new char[imageLen];
        strcpy(image_, image);

        size_t authorLen = strlen(author) + 1;
        author_ = new char[authorLen];
        strcpy(author_, author);
    }

    ~OldArtExhibit()
    {
        delete[] author_;
    }

    void Print() const override
    {
        cout << "Image: " << image_ << endl;
        cout << "Author: " << author_ << endl;
        cout << "Date: " << date_ << endl;
    }

    OldArtExhibit(const OldArtExhibit& other)
        : ArtExhibit(other), author_(nullptr)
    {
        size_t authorLen = strlen(other.author_) + 1;
        author_ = new char[authorLen];
        strcpy(author_, other.author_);
    }

    OldArtExhibit& operator=(const OldArtExhibit& other)
    {
        if (this != &other)
        {
            ArtExhibit::operator=(other);

            delete[] author_;
            author_ = nullptr;

            size_t authorLen = strlen(other.author_) + 1;
            author_ = new char[authorLen];
            strcpy(author_, other.author_);
        }
        return *this;
    }

    OldArtExhibit(OldArtExhibit&& other) noexcept
        : ArtExhibit(std::move(other)), author_(other.author_)
    {
        other.author_ = nullptr;
    }

    OldArtExhibit& operator=(OldArtExhibit&& other) noexcept
    {
        if (this != &other)
        {
            ArtExhibit::operator=(std::move(other));

            delete[] author_;
            author_ = other.author_;
            other.author_ = nullptr;
        }
        return *this;
    }

private:
    char* author_;
};

class Coin : public HistoricExhibit
{
public:
    Coin(const char* name, int startYear, int endYear, int denomination)
        : HistoricExhibit(name, startYear, endYear), denomination_(denomination)
    {
    }

    void Print() const override
    {
        HistoricExhibit::Print();
        cout << "Denomination: " << denomination_ << endl;
    }

private:
    int denomination_;
};

class EdgedWeapon : public HistoricExhibit
{
public:
    EdgedWeapon(const char* name, int startYear, int endYear)
        : HistoricExhibit(name, startYear, endYear)
    {
    }
};

class Painting : public OldArtExhibit
{
public:
    Painting(const char* image, const char* author, int date)
        : OldArtExhibit(image, author, date)
    {
    }
};

class Statue : public OldArtExhibit
{
public:
    Statue(const char* image, const char* author, int date)
        : OldArtExhibit(image, author, date)
    {
    }
};

class Photo : public ArtExhibit
{
public:
    Photo(const char* image, int date)
        : ArtExhibit(), date_(date)
    {
        size_t imageLen = strlen(image) + 1;
        image_ = new char[imageLen];
        strcpy(image_, image);
    }

    ~Photo()
    {
        delete[] image_;
    }

    void Print() const override
    {
        cout << "Image: " << image_ << endl;
        cout << "Date: " << date_ << endl;
    }

    Photo(const Photo& other)
        : ArtExhibit(other), date_(other.date_)
    {
        size_t imageLen = strlen(other.image_) + 1;
        image_ = new char[imageLen];
        strcpy(image_, other.image_);
    }

    Photo& operator=(const Photo& other)
    {
        if (this != &other)
        {
            ArtExhibit::operator=(other);

            delete[] image_;
            image_ = nullptr;
            date_ = other.date_;

            size_t imageLen = strlen(other.image_) + 1;
            image_ = new char[imageLen];
            strcpy(image_, other.image_);
        }
        return *this;
    }

    Photo(Photo&& other) noexcept
        : ArtExhibit(std::move(other)), image_(other.image_), date_(other.date_)
    {
        other.image_ = nullptr;
    }

    Photo& operator=(Photo&& other) noexcept
    {
        if (this != &other)
        {
            ArtExhibit::operator=(std::move(other));

            delete[] image_;
            image_ = other.image_;
            date_ = other.date_;
            other.image_ = nullptr;
        }
        return *this;
    }

private:
    char* image_;
    int date_;
};

ostream& operator<<(ostream& os, const Exhibit& exhibit)
{
    exhibit.Print();
    return os;
}

int main()
{
    Exhibit* coin = new Coin("Gold Coin", 1800, 1900, 10);
    Exhibit* weapon = new EdgedWeapon("Sword", 1500, 1600);
    Exhibit* painting = new Painting("Landscape", "John Smith", 2000);
    Exhibit* statue = new Statue("Greek God", "Michelangelo", 1500);
    Exhibit* photo = new Photo("Family Portrait", 1990);

    cout << *coin << endl;
    cout << *weapon << endl;
    cout << *painting << endl;
    cout << *statue << endl;
    cout << *photo << endl;

    delete coin;
    delete weapon;
    delete painting;
    delete statue;
    delete photo;

    return 0;
}
