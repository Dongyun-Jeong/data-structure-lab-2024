#pragma once  // 앞에서 한게 있으면 뒤에서 안해준다 중복 include 안하기(?)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Music class
class Music {
private:
    string title;
    string artist;
    string album;
    int year;
public:
    // 생성자 (Constructor)
    Music(string title, string artist, string album, int year) {
        this->title = title;
        this->artist = artist;
        this->album = album;
        this->year = year;
    }
    // 소멸자 (Destructor)
    ~Music() {}

    // Getters
    string getTitle() { 
        return title; 
    }
    string getArtist() { 
        return artist; 
    }
    string getAlbum() { 
        return album; 
    }
    int getYear() { 
        return year; 
    }
};

// MusicStreamingService class
class MusicStreamingService {
private:
    string serviceName;
    vector<Music> musicList; //벡터를 어떤형식(Music객체)으로 만들거냐

public:
    MusicStreamingService(string serviceName) {
        this->serviceName = serviceName;
    }

    // Adds a music to the service
    void addMusic(string title, string artist, string album, int year) {
        Music newMusic(title, artist, album, year);
        musicList.push_back(newMusic); //리스트 뒤에 newMusic을 추가
        cout << title << " by " << artist << " added to " << serviceName << endl;
    }

    // Searches for music by title
    Music* searchByTitle(string title) {
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getTitle() == title) {   //musicList[0, 1, ...]타이틀 같으면 리턴 다르면 i올라가서 또 비교 
                return &musicList[i]; // &는 주소값
            }
        }
        return NULL;
    }

    // Searches for music by artist
    vector<Music*> searchByArtist(string artist) {
        vector<Music*> result;
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getArtist() == artist) {
                result.push_back(&musicList[i]);        //result리스트에 같은 아티스트 있으면 넣어서 반환(?)
            }
        }
        return result;
    }

};