#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

//void overloadStreamOperators();
//vector<string> tokenize(string str, char delimiter = ',');

//// overloading << operator, formatting
class MediaItem {
public:
    MediaItem() {
        m_url = "";
        m_title = "";
        m_artist = "";
        m_duration = 0;
        m_hasAudio = false;
    }
    MediaItem(const std::string& title, const std::string& artist,
        const std::string& url, int duration, bool hasAudio) :
        m_url{ url }, m_duration{ duration }, m_hasAudio{ hasAudio }{
        m_title = title;
        m_artist = artist;
    }

    std::string toString() {
        stringstream buffer;
        buffer << "MediaItem: \n\t " << setw(20) << "title: " << this->m_title << "\n\t " << setw(20) << "artist: " << this->m_artist <<
            "\n\t " << setw(20) << "url: " << this->m_url << "\n\t " << setw(20) << "has audio? " << std::boolalpha << m_hasAudio << "\n\t " << setw(20) << "duration: " << m_duration << endl;
        return  buffer.str();
    }

    friend ostream& operator<<(ostream& stream, const MediaItem& mediaItem);
    friend istream& operator>>(istream& stream, MediaItem& mediaItem);
private:
    std::string m_url;
    std::string m_title;
    std::string m_artist;
    int m_duration;
    bool m_hasAudio;
};

/**
    Tokenizes a string.
    @param str - the string to be tokenized.
            delimiter - char - the delimiter used for tokenization
    @return a vector of strings, containing the tokens
**/
vector<string> tokenize(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream& operator>>(istream& is, MediaItem& mediaItem) {
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5) // make sure the data we have is ok
        return is;
    mediaItem.m_artist = tokens[0];
    mediaItem.m_title = tokens[1];
    mediaItem.m_url = tokens[2];
    int duration = 0;
    std::istringstream(tokens[3]) >> duration;
    mediaItem.m_duration = duration;
    bool hasAudio = false;
    std::istringstream(tokens[4]) >> hasAudio;
    mediaItem.m_hasAudio = hasAudio;
    return is;
}


ostream& operator<<(ostream& stream, const MediaItem& mediaItem)
{
    stream.width(20);
    stream << mediaItem.m_title + " |";
    stream.width(20);
    stream << mediaItem.m_artist + " |";
    stream.width(48);
    stream << mediaItem.m_url + " |";
    stream.width(10);
    stringstream strWeight;
    strWeight.precision(3);
    strWeight << mediaItem.m_duration << " |";

    stream.width(7);
    stream << strWeight.str();
    stream.width(6);
    stream << std::boolalpha << mediaItem.m_hasAudio << " |";
    stream << endl;
    return stream;
}

class Playlist {
    std::vector<MediaItem> m_items;
    int m_currentIndex;

public:
    Playlist() {
        m_currentIndex = 0;
        // by default add some data in the playlist
        m_items.push_back(MediaItem{ "Conv. nets", "Andrew Ng", "coursera.org", 1524, true });
        m_items.push_back(MediaItem{ "Quarantine math", "Foil Arms and Hog", "https://www.youtube.com/watch?v=BSxM6_zEw2k",48032, true });
        m_items.push_back(MediaItem{ "Versu te", "Petru Guelfucci", "https://www.youtube.com/watch?v=Rr_ssXwtHPY",34832, true });
        m_items.push_back(MediaItem{ "Nature slideshow", "-", "https://www.nationalgeographic.com/", 0, false });

    }

    bool loadFromCSV(const std::string& csvFilepath) {
        ifstream f(csvFilepath);

        if (!f.is_open()) {
            return false;
        }

        MediaItem mediaItem;
        while (f >> mediaItem)
        {
            m_items.push_back(mediaItem);
        }

        f.close();

        return true;

    }

    MediaItem& getItemAt(const size_t& idx) {
        if (idx > m_items.size())
            throw "Index out of range";
        return m_items[idx];
    }

    void displayPlaylist() {
        printPlaylistHeader();
        for (MediaItem mediaItem : m_items) {
            cout << mediaItem;
        }
    }
private:
    void printPlaylistHeader() {
        cout << right << setw(20) << "Title |";
        cout << right << setw(20) << right << "Artist |";
        cout << right << setw(48) << "Url |";
        cout << right << setw(7) << "Len |";
        cout << right << setw(6) << "Audio? |";
        cout << endl;
        char prev = cout.fill();
        cout << setw(103) << setfill('-') << "" << endl;
        cout.fill(prev);
    }

};

void overloadStreamOperators() {
    Playlist pl;
    pl.displayPlaylist();
    cout << endl;
    MediaItem it = pl.getItemAt(2);
    cout << it.toString();
}


int main() {
    overloadStreamOperators();

        Playlist pl;
        std::string playlistFile = "playlist.csv";
        bool loaded = pl.loadFromCSV(playlistFile);
        if(!loaded){
            std::cerr<<"Unable to load the file: "<<playlistFile<<endl;
            return -1;
        }
        pl.displayPlaylist();

    return 0;
}



