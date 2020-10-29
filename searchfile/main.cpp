#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct musica
{
    std::string track_title;
    std::string artist_name;
    std::string track_duration;
};

int main() {
    vector<musica> tracks;
    int linea = 0;
    int columna = 1;
    int cont = 0;
    int aux = cont;
    std::ifstream data("/home/gretchell/Downloads/fma_metadata/raw_tracks.csv");
    std::string line;

    while(std::getline(data,line)) {
        musica track;
        std::stringstream lineStream(line);
        std::string cell;
        linea++;
        while(std::getline(lineStream,cell, ',')) {
            if (linea == 1) {
                linea++;
                break;
            }
            else if (cont != 0) {
                cont++;
                if (cell.find("/'}]") != cell.npos) {
                    cont--;
                    aux = cont;
                    cont = 0;
                }
            }
            else if (columna == 6) {
                track.artist_name = cell;
            }
            else if (columna == 23){
                track.track_duration = cell;
            }
            else if (columna == 28){
                cont++;
            }
            else if (columna == 38 + aux){
                track.track_title = cell;
            }
            else if (columna == 40 + aux){
                break;
            }
            columna++;
        }
        if(track.track_title != "" && track.artist_name != "" && track.track_duration != ""){
            tracks.push_back(track);
            std::cout << "Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration << std::endl;
        }
        columna = 1;
        if (linea == 650) {
            std::cout << tracks.size() << std::endl;
            std::cout << tracks[90].track_duration << std::endl;
            break;
        }
    }
}

