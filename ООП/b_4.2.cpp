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
    ArtExhibit(const ArtExhibit& other) = delete;
    ArtExhibit& operator=(const ArtExhibit& other) = delete;
    ArtExhibit(ArtExhibit&& other) noexcept = delete;
    ArtExhibit& operator=(ArtExhibit&& other) noexcept = delete;
protected:
    char* image_;
    int date_;
};

class OldArtExhibit : public ArtExhibit
{
public:
    OldArtExhibit(const char* image, const char* author, int date)
        : ArtExhibit(), author_(nullptr), date_(date)
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

    OldArtExhibit(const OldArtExhibit& other) = delete;
    OldArtExhibit& operator=(const OldArtExhibit& other) = delete;
    OldArtExhibit(OldArtExhibit&& other) noexcept = delete;
    OldArtExhibit& operator=(OldArtExhibit&& other) noexcept = delete;

private:
    char* author_;
    int date_;
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

    Photo(const Photo& other) = delete;
    Photo& operator=(const Photo& other) = delete;
    Photo(Photo&& other) noexcept = delete;
    Photo& operator=(Photo&& other) noexcept = delete;

private:
    char* image_;
    int date_;
};

class ExhibitArray
{
public:
    ExhibitArray()
        : data_(nullptr), size_(0)
    {
    }
    ~ExhibitArray()
    {
        Clear();
    }

    void Add(Exhibit* exhibit)
    {
        Exhibit** newData = new Exhibit * [size_ + 1];
        for (size_t i = 0; i < size_; ++i)
        {
            newData[i] = data_[i];
        }
        newData[size_] = exhibit;
        delete[] data_;
        data_ = newData;
        size_++;
    }

    void Remove(Exhibit* exhibit)
    {
        if (size_ == 0)
            return;

        size_t index = GetIndex(exhibit);
        if (index == size_)
            return;

        delete data_[index];
        for (size_t i = index; i < size_ - 1; ++i)
        {
            data_[i] = data_[i + 1];
        }
        size_--;
    }

    void PrintAll() const
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i]->Print();
            cout << endl;
        }
    }

    void Clear()
    {
        if (data_)
        {
            for (size_t i = 0; i < size_; ++i)
            {
                delete data_[i];
            }
            delete[] data_;
            data_ = nullptr;
            size_ = 0;
        }
    }
    size_t GetIndex(Exhibit* exhibit) const
    {
        for (size_t i = 0; i < size_; ++i)
        {
            if (data_[i] == exhibit)
            {
                return i;
            }
        }
        return size_;
    }

private:
    Exhibit** data_;
    size_t size_;
};

ostream& operator<<(ostream& os, const Exhibit& exhibit)
{
    exhibit.Print();
    return os;
}

ostream& operator<<(ostream& os, const ExhibitArray& exhibitArray)
{
    exhibitArray.PrintAll();
    return os;
}


int main()
{
    ExhibitArray exhibitArray;
    exhibitArray.Add(new Coin("Gold Coin", 1800, 1900, 10));
    exhibitArray.Add(new EdgedWeapon("Sword", 1500, 1600));
    exhibitArray.Add(new Painting("Landscape", "John Smith", 2000));
    exhibitArray.Add(new Statue("Greek God", "Michelangelo", 1500));
    exhibitArray.Add(new Photo("Family Portrait", 1990));

    cout << exhibitArray;

    exhibitArray.Remove(new EdgedWeapon("Sword", 1500, 1600));

    cout << exhibitArray;

    exhibitArray.Clear();

    return 0;
}
