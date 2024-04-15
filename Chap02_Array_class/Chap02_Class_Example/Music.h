#pragma once  // �տ��� �Ѱ� ������ �ڿ��� �����ش� �ߺ� include ���ϱ�(?)
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
    // ������ (Constructor)
    Music(string title, string artist, string album, int year) {
        this->title = title;
        this->artist = artist;
        this->album = album;
        this->year = year;
    }
    // �Ҹ��� (Destructor)
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
    vector<Music> musicList; //���͸� �����(Music��ü)���� ����ų�

public:
    MusicStreamingService(string serviceName) {
        this->serviceName = serviceName;
    }

    // Adds a music to the service
    void addMusic(string title, string artist, string album, int year) {
        Music newMusic(title, artist, album, year);
        musicList.push_back(newMusic); //����Ʈ �ڿ� newMusic�� �߰�
        cout << title << " by " << artist << " added to " << serviceName << endl;
    }

    // Searches for music by title
    Music* searchByTitle(string title) {
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getTitle() == title) {   //musicList[0, 1, ...]Ÿ��Ʋ ������ ���� �ٸ��� i�ö󰡼� �� �� 
                return &musicList[i]; // &�� �ּҰ�
            }
        }
        return NULL;
    }

    // Searches for music by artist
    vector<Music*> searchByArtist(string artist) {
        vector<Music*> result;
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getArtist() == artist) {
                result.push_back(&musicList[i]);        //result����Ʈ�� ���� ��Ƽ��Ʈ ������ �־ ��ȯ(?)
            }
        }
        return result;
    }

};