#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include <math.h>


using namespace std;

struct sysinfo memInfo;
struct musica
{
    std::string track_id;
    std::string track_title;
    std::string artist_name;
    std::string track_duration;
    std::string track_path;
};

int main() {
    sysinfo (&memInfo);
    long long totalVirtualMem;
    vector<musica> tracks;
    vector<std::string> id_tracks;
    int linea = 0;
    int columna = 1;
    int cont = 0;
    int aux = cont;
    std::string path("/home/gretchell/Downloads/fma_small/");
    std::ifstream data("/home/gretchell/Downloads/fma_metadata/raw_tracks.csv");
    std::ifstream data_1("/home/gretchell/Downloads/fma_small/checksums");
    std::string line;
    std::string line_1;
    while (std::getline(data_1,line_1)){
        id_tracks.push_back(line_1.substr(42));
    }

    std::cout << id_tracks.size() << std::endl;

    while(std::getline(data,line)) {


        totalVirtualMem = memInfo.totalram - memInfo.freeram;
        totalVirtualMem += memInfo.totalswap - memInfo.freeswap;
        totalVirtualMem *= memInfo.mem_unit;
        double memory = (double) totalVirtualMem;
        memory /= pow(10.0, 9.0);

        std::cout << memory << std::endl;

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
            else if (columna == 1) {
                track.track_id = cell;
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
        columna = 1;
        if(track.track_title != "" || track.artist_name != "" || track.track_duration != ""){
            try {
                std::stoi(track.track_id);
            }catch (exception& e)
            {
                track.track_id = "-1";
            }
            if(std::stoi(track.track_id)>std::stoi(id_tracks[0].substr(4,6))){
                id_tracks.erase(id_tracks.begin());
            }
            if ( std::stoi(id_tracks[0].substr(4,6)) == std::stoi(track.track_id) ){
                track.track_path = path + id_tracks[0];
                tracks.push_back(track);
                std::cout << "ID: " + track.track_id + "; Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration  + "; Path: " + track.track_path << std::endl;
                id_tracks.erase(id_tracks.begin());
            }
        }
    }
}

